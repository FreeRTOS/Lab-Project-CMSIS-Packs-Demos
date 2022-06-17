/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "command_responder.h"

extern "C" {
  #include "logging_levels.h"

  /* Logging configuration for the MQTT library. */
  #ifndef LIBRARY_LOG_NAME
      #define LIBRARY_LOG_NAME    "KWS"
  #endif

  #ifndef LIBRARY_LOG_LEVEL
      #define LIBRARY_LOG_LEVEL    LOG_INFO
  #endif

  #include "logging_stack.h"
  #include "mqtt_agent_task.h"
  #include "demo_config.h"
}

#define MICROSPEECH_TOPIC   "microspeech_demo/" democonfigCLIENT_IDENTIFIER

#define MICROSPEECH_PAYLOAD_FORMAT \
    "{"                            \
       "\"keyword\": \"%.*s\","    \
       "\"score\": %d,"            \
       "\"timestamp\": %u,"        \
       "\"ts_unit\": \"ms\""       \
     "}"
#define COMMAND_MAX_SIZE  ( 7 )  //Commands can be silence, unknown yes, no
#define SCORE_SIZE        ( 3 )
#define TS_SIZE           ( 10 )

#define MAX_PAYLOAD_SIZE    ( sizeof( MICROSPEECH_PAYLOAD_FORMAT ) + COMMAND_MAX_SIZE + SCORE_SIZE + TS_SIZE )

// The default implementation writes out the name of the recognized command
// to the error console. Real applications will want to take some custom
// action instead, and should implement their own versions of this function.
void RespondToCommand(tflite::ErrorReporter* error_reporter,
                      int32_t current_time, const char* found_command,
                      uint8_t score, bool is_new_command) {


  char cPayload[ MAX_PAYLOAD_SIZE + 1 ] = { 0 };
  size_t xPayloadLength = 0;
  MQTTStatus_t xMQTTStatus;

  if (is_new_command) {
    xPayloadLength = snprintf( cPayload,
              MAX_PAYLOAD_SIZE,
              MICROSPEECH_PAYLOAD_FORMAT,
              COMMAND_MAX_SIZE,
              found_command,
              score,
              current_time );
    if( ( xPayloadLength > 0 ) && ( xPayloadLength <= MAX_PAYLOAD_SIZE ) )
    {
        xMQTTStatus = xMQTTAgentPublish( MICROSPEECH_TOPIC,
                                        strlen(MICROSPEECH_TOPIC),
                                        MQTTQoS0,
                                        ( uint8_t * ) cPayload,
                                        xPayloadLength );
        if( xMQTTStatus == MQTTSuccess )
        {
          LogInfo(("Send payload to MQTT Agent" ));
        }
        else
        {
          LogError(("Send payload to MQTT Agent failed, status = %d", xMQTTStatus ));
        }
    }
    else
    {
        LogError(("Failed to serialize MQTT payload."));
    }

  LogInfo(("Heard %s (%d) @%dms\n", found_command,
                 score, current_time ));
  }
}
