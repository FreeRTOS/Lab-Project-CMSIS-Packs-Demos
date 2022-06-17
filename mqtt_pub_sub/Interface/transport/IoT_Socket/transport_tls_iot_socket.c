/* -----------------------------------------------------------------------------
 * Copyright (c) 2021 Arm Limited (or its affiliates). All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * -------------------------------------------------------------------------- */

#include "logging_levels.h"

/* Logging configuration for the PKCS #11 library. */
#ifndef LIBRARY_LOG_NAME
    #define LIBRARY_LOG_NAME    "TRANSPORT"
#endif

#ifndef LIBRARY_LOG_LEVEL
    #define LIBRARY_LOG_LEVEL    LOG_INFO
#endif

#include "logging_stack.h"

#include <string.h>
#include "transport_interface_api.h"
#include "iot_socket.h"
#include "tls_helper.h"


static int32_t Recv_Cb (void *pvCallerContext, unsigned char * pucReceiveBuffer, size_t xReceiveLength);
static int32_t Send_Cb (void *pvCallerContext, const unsigned char *pucData,     size_t xDataLength);


TransportStatus_t Transport_Connect( NetworkContext_t * pNetworkContext,
                                     const ServerInfo_t * pServerInfo,
                                     const TLSParams_t * pTLSParams,
                                     uint32_t sendTimeoutMs,
                                     uint32_t recvTimeoutMs )
{

    TransportStatus_t status = TRANSPORT_STATUS_SUCCESS;
    int32_t socketStatus = 0;
    uint8_t ipAddr[4];
    uint32_t ipAddrLen;
    TLSHelperParams_t tlsHelperParams = { 0 };

    if( ( pNetworkContext == NULL ) || ( pServerInfo == NULL ) )
    {
        status = TRANSPORT_STATUS_INVALID_PARAMETER;
    }
    else if( pServerInfo->pHostName == NULL )
    {
        status = TRANSPORT_STATUS_INVALID_PARAMETER;
    }
    else
    {
        /* Create a TCP socket. */
        pNetworkContext->socket = iotSocketCreate(IOT_SOCKET_AF_INET, IOT_SOCKET_SOCK_STREAM, IOT_SOCKET_IPPROTO_TCP);
        if( pNetworkContext->socket < 0)
        {
            status = TRANSPORT_STATUS_SOCKET_CREATE_FAILURE;
        }

        /* Resolve the DNS name and get the IP address of the host. */
        if( status == TRANSPORT_STATUS_SUCCESS )
        {
            memset( ipAddr, 0x00, sizeof( ipAddr ) );
            ipAddrLen = sizeof( ipAddr );
            socketStatus = iotSocketGetHostByName (pServerInfo->pHostName, IOT_SOCKET_AF_INET,ipAddr, &ipAddrLen);
            if( socketStatus < 0)
            {
                status = TRANSPORT_STATUS_DNS_FAILURE;
            }
        }

        /* Create a TCP connection to the host. */
        if( status == TRANSPORT_STATUS_SUCCESS )
        {
             LogInfo(("Initiating TCP connection with host: %s:%d",  pServerInfo->pHostName, pServerInfo->port ));
             socketStatus = iotSocketConnect (pNetworkContext->socket, ipAddr, ipAddrLen, pServerInfo->port);
             if(socketStatus < 0 )
             {
                 status = TRANSPORT_STATUS_CONNECT_FAILURE;
             }
        }
        
        /* IF this is a secure TLS connection, perform the TLS handshake. */
        if( ( status == TRANSPORT_STATUS_SUCCESS ) && ( pTLSParams != NULL ) )
        {
            /* Initialize TLS */
            tlsHelperParams.pcDestination             = pServerInfo->pHostName;
            tlsHelperParams.pcServerCertificate       = pTLSParams->pRootCa;
            tlsHelperParams.ulServerCertificateLength = pTLSParams->rootCaSize;
            tlsHelperParams.pvCallerContext           = pNetworkContext;
            tlsHelperParams.pxNetworkRecv             = &Recv_Cb;
            tlsHelperParams.pxNetworkSend             = &Send_Cb;
            tlsHelperParams.pPrivateKeyLabel          = pTLSParams->pPrivateKeyLabel;
            tlsHelperParams.pClientCertLabel          = pTLSParams->pClientCertLabel;
            tlsHelperParams.pcLoginPIN                = pTLSParams->pLoginPIN;


            pNetworkContext->pTLSContext = pvPortMalloc( sizeof( TLSContext_t ) );
            
            if( pNetworkContext->pTLSContext != NULL )
            {
                iotSocketSetOpt (pNetworkContext->socket, IOT_SOCKET_SO_SNDTIMEO, &sendTimeoutMs, sizeof(sendTimeoutMs));
                iotSocketSetOpt (pNetworkContext->socket, IOT_SOCKET_SO_RCVTIMEO, &recvTimeoutMs, sizeof(recvTimeoutMs));


                if( TLS_Init( ( TLSContext_t * ) ( pNetworkContext->pTLSContext ), &tlsHelperParams) == pdPASS )
                {
                    LogInfo(("Initiating TLS handshake with host: %s:%d",  pServerInfo->pHostName, pServerInfo->port ));
                    /* Initiate TLS handshake */
                    if( TLS_Connect( ( TLSContext_t * ) ( pNetworkContext->pTLSContext ) ) != 0)
                    {
                        status = TRANSPORT_STATUS_TLS_FAILURE;
                    }
                }
                else
                {
                    status = TRANSPORT_STATUS_TLS_FAILURE;
                }
            }
            else
            {
                status = TRANSPORT_STATUS_INSUFFICIENT_MEMORY;
            }
        }

        if( status == TRANSPORT_STATUS_SUCCESS )
        {
            uint32_t nonblocking = 0U;
            iotSocketSetOpt(pNetworkContext->socket, IOT_SOCKET_IO_FIONBIO, &nonblocking, sizeof(nonblocking));
        }
    }

    return status;
}

int32_t Transport_Recv( NetworkContext_t * pNetworkContext,
                        void * pBuffer,
                        size_t bytesToRecv )
{
  int32_t rc = -1;

  if ( (pNetworkContext == NULL) || ( pBuffer == NULL ) || ( bytesToRecv == 0 ) )
  {
    rc = -1;
  }
  else 
  {
      if( pNetworkContext->pTLSContext != NULL )
      {
          rc = TLS_Recv ( ( TLSContext_t * ) ( pNetworkContext->pTLSContext ) , pBuffer, bytesToRecv);
      }
      else
      {
          rc = iotSocketRecv (pNetworkContext->socket, pBuffer, bytesToRecv);
      }
  }

  return rc;
}

int32_t Transport_Send( NetworkContext_t * pNetworkContext,
                              const void * pMessage,
                              size_t bytesToSend )
{
  int32_t rc = -1;

  if ( (pNetworkContext == NULL) || ( pMessage == NULL ) || ( bytesToSend == 0 ) )
  {
    rc = -1;
  }
  else 
  {
      if( pNetworkContext->pTLSContext != NULL )
      {
          rc = TLS_Send( ( TLSContext_t * ) ( pNetworkContext->pTLSContext ), pMessage, bytesToSend);
      }
      else
      {
          rc = iotSocketSend(pNetworkContext->socket, pMessage, bytesToSend);
      }
  }

  return rc;
}

/**
 * @brief Defines callback type for receiving bytes from the network.
 *
 * @param[in] pvCallerContext Opaque context handle provided by caller.
 * @param[out] pucReceiveBuffer Buffer to fill with received data.
 * @param[in] xReceiveLength Length of previous parameter in bytes.
 *
 * @return The number of bytes actually read or appropirate error code.
 */
static int32_t Recv_Cb (void *pvCallerContext, unsigned char * pucReceiveBuffer, size_t xReceiveLength)
{
    int32_t rc;
    NetworkContext_t * pNetworkContext = ( NetworkContext_t * ) ( pvCallerContext );

    if( ( pNetworkContext == NULL ) || ( pucReceiveBuffer == NULL ) )
    {
        rc = IOT_SOCKET_ERROR;
    }
    else
    {
        rc = iotSocketRecv (pNetworkContext->socket, pucReceiveBuffer, xReceiveLength);
        if (rc < 0)
        {
            if( rc == IOT_SOCKET_EAGAIN )
            {
                /* There was no data on a non-blocking socket, or operation timedout on a blocking socket. */
                rc = 0;
            }
        }
    }

    return (rc);
}

/**
 * @brief Defines callback type for sending bytes to the network.
 *
 * @param[in] pvCallerContext Opaque context handle provided by caller.
 * @param[out] pucReceiveBuffer Buffer of data to send.
 * @param[in] xReceiveLength Length of previous parameter in bytes.
 *
 * @return The number of bytes actually sent.
 */
static int32_t Send_Cb (void *pvCallerContext, const unsigned char *pucData, size_t xDataLength)
{
    NetworkContext_t * pNetworkContext = ( NetworkContext_t * )( pvCallerContext );
    int32_t rc;

    if( ( pNetworkContext == NULL ) || ( pucData == NULL ) )
    {
        rc = IOT_SOCKET_ERROR;
    }
    else
    {
        rc = iotSocketSend (pNetworkContext->socket, pucData, xDataLength);
    }
    
    return (rc);
}

TransportStatus_t Transport_Disconnect( NetworkContext_t * pNetworkContext )
{
    TransportStatus_t status = TRANSPORT_STATUS_SUCCESS;
    int32_t socketStatus;
    if( pNetworkContext == NULL )
    {
        status = TRANSPORT_STATUS_INVALID_PARAMETER;
    }
    else
    {
        do
        {
           socketStatus = iotSocketClose( pNetworkContext->socket );
        } while ( socketStatus == IOT_SOCKET_EAGAIN );

        if( socketStatus < 0 )
        {
            LogError(("Failed to close the socket, error = %d", socketStatus ));
            status = TRANSPORT_STATUS_SOCKET_CLOSE_FAILURE;
        }

        if(  pNetworkContext->pTLSContext != NULL )
        {
            TLS_Cleanup( (TLSContext_t * ) ( pNetworkContext->pTLSContext ) );
            vPortFree( pNetworkContext->pTLSContext );
            pNetworkContext->pTLSContext = NULL;
        }
    }

    return status;
}
