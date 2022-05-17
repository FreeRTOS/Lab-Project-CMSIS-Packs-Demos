# CMSIS Build CMakeLists generated on 2022-05-14T00:39:26

cmake_minimum_required(VERSION 3.18)

# Target options

set(TARGET AWS_MQTT_MutualAuth_Demo.Release+AVH_MPS3_Corstone-300)
set(CPU Cortex-M55)
set(PRJ_DIR "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo")
set(OUT_DIR "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/AWS_MQTT_MutualAuth_Demo.Release+AVH_MPS3_Corstone-300_OutDir")
set(INT_DIR "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/AWS_MQTT_MutualAuth_Demo.Release+AVH_MPS3_Corstone-300_IntDir")
set(FPU DP_FPU)
set(DSP DSP)
set(TZ TZ)
set(SECURE Secure)
set(MVE FP_MVE)
set(AS_FLAGS_GLOBAL "-masm=auto")
set(CC_FLAGS_GLOBAL "-std=c99 -Wno-macro-redefined -Wno-pragma-pack -Wno-parentheses-equality -O3")
set(CXX_FLAGS_GLOBAL "-Wno-macro-redefined -Wno-pragma-pack -Wno-parentheses-equality -O3")
set(LD_FLAGS_GLOBAL "--entry=Reset_Handler")
set(LD_SCRIPT "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/RTE/Device/SSE-300-MPS3/fvp_sse300_mps3_s.sct")

set(DEFINES
  _RTE_
  MBEDTLS_CONFIG_FILE=\"aws_mbedtls_config.h\"
)

set(INC_PATHS
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/RTE/Compiler"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/RTE/Device/SSE-300-MPS3"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/RTE/RTOS"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/RTE/Security"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/RTE/_AWS_MQTT_MutualAuth_Demo.Release_AVH_MPS3_Corstone-300"
  "/home/ubuntu/packs/ARM/CMSIS-FreeRTOS/10.4.6/CMSIS/RTOS2/FreeRTOS/Include"
  "/home/ubuntu/packs/ARM/CMSIS-FreeRTOS/10.4.6/Source/include"
  "/home/ubuntu/packs/ARM/CMSIS-FreeRTOS/10.4.6/Source/portable/GCC/ARM_CM33_NTZ/non_secure"
  "/home/ubuntu/packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include"
  "/home/ubuntu/packs/ARM/CMSIS/5.9.0/CMSIS/Driver/Include"
  "/home/ubuntu/packs/ARM/CMSIS/5.9.0/CMSIS/Driver/VIO/Include"
  "/home/ubuntu/packs/ARM/CMSIS/5.9.0/CMSIS/RTOS2/Include"
  "/home/ubuntu/packs/ARM/V2M_MPS3_SSE_300_BSP/1.2.0/Board/Device_Definition"
  "/home/ubuntu/packs/ARM/V2M_MPS3_SSE_300_BSP/1.2.0/Board/Platform"
  "/home/ubuntu/packs/ARM/V2M_MPS3_SSE_300_BSP/1.2.0/CMSIS_Driver/Config"
  "/home/ubuntu/packs/ARM/V2M_MPS3_SSE_300_BSP/1.2.0/CMSIS_Driver/Include"
  "/home/ubuntu/packs/ARM/V2M_MPS3_SSE_300_BSP/1.2.0/Device/Include"
  "/home/ubuntu/packs/ARM/V2M_MPS3_SSE_300_BSP/1.2.0/Native_Driver"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/include"
  "/home/ubuntu/packs/AWS/backoffAlgorithm/1.0.0-Beta/libraries/standard/backoffAlgorithm/source/include"
  "/home/ubuntu/packs/AWS/coreMQTT/1.1.0-Beta/libraries/standard/coreMQTT/source/include"
  "/home/ubuntu/packs/AWS/coreMQTT/1.1.0-Beta/libraries/standard/coreMQTT/source/interface"
  "/home/ubuntu/packs/AWS/coreMQTT_Agent/1.0.1-Beta/libraries/aws/coreMQTT-Agent/source/include"
  "/home/ubuntu/packs/AWS/corePKCS11/3.0.0-Beta/libraries/standard/corePKCS11/source/dependency/3rdparty/mbedtls_utils"
  "/home/ubuntu/packs/AWS/corePKCS11/3.0.0-Beta/libraries/standard/corePKCS11/source/include"
  "/home/ubuntu/packs/Arm-Packs/PKCS11/1.0.0/include"
  "/home/ubuntu/packs/Keil/ARM_Compiler/1.7.1/Include"
  "/home/ubuntu/packs/MDK-Packs/IoT_Socket/1.3.0/include"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/config_files"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/demos/include"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/demos/network_manager"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/demos/common/pkcs11_helpers"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/3rdparty/mbedtls_config"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/logging/include"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/abstractions/platform/include"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/abstractions/platform/freertos/include"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/abstractions/secure_sockets/include"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/abstractions/transport/secure_sockets"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/abstractions/wifi/include"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/c_sdk/standard/common/include"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/c_sdk/standard/common/include/private"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/freertos_plus/standard/crypto/include"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/freertos_plus/standard/tls/include"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/Board/AVH_MPS3_Corstone-300"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/config_files/Socket"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/abstractions/platform/include/platform"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/abstractions/platform/include/types"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/abstractions/platform/freertos/include/platform"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/c_sdk/standard/common/include/types"
)

set(CC_SRC_FILES
  "/home/ubuntu/packs/ARM/CMSIS-Driver/2.7.1/ETH/ETH_LAN91C111.c"
  "/home/ubuntu/packs/ARM/CMSIS-FreeRTOS/10.4.6/CMSIS/RTOS2/FreeRTOS/Source/ARM/clib_arm.c"
  "/home/ubuntu/packs/ARM/CMSIS-FreeRTOS/10.4.6/CMSIS/RTOS2/FreeRTOS/Source/cmsis_os2.c"
  "/home/ubuntu/packs/ARM/CMSIS-FreeRTOS/10.4.6/CMSIS/RTOS2/FreeRTOS/Source/freertos_evr.c"
  "/home/ubuntu/packs/ARM/CMSIS-FreeRTOS/10.4.6/CMSIS/RTOS2/FreeRTOS/Source/os_systick.c"
  "/home/ubuntu/packs/ARM/CMSIS-FreeRTOS/10.4.6/Source/event_groups.c"
  "/home/ubuntu/packs/ARM/CMSIS-FreeRTOS/10.4.6/Source/list.c"
  "/home/ubuntu/packs/ARM/CMSIS-FreeRTOS/10.4.6/Source/portable/GCC/ARM_CM33_NTZ/non_secure/port.c"
  "/home/ubuntu/packs/ARM/CMSIS-FreeRTOS/10.4.6/Source/portable/GCC/ARM_CM33_NTZ/non_secure/portasm.c"
  "/home/ubuntu/packs/ARM/CMSIS-FreeRTOS/10.4.6/Source/portable/MemMang/heap_5.c"
  "/home/ubuntu/packs/ARM/CMSIS-FreeRTOS/10.4.6/Source/queue.c"
  "/home/ubuntu/packs/ARM/CMSIS-FreeRTOS/10.4.6/Source/stream_buffer.c"
  "/home/ubuntu/packs/ARM/CMSIS-FreeRTOS/10.4.6/Source/tasks.c"
  "/home/ubuntu/packs/ARM/CMSIS-FreeRTOS/10.4.6/Source/timers.c"
  "/home/ubuntu/packs/ARM/V2M_MPS3_SSE_300_BSP/1.2.0/Board/Device_Definition/device_definition.c"
  "/home/ubuntu/packs/ARM/V2M_MPS3_SSE_300_BSP/1.2.0/CMSIS_Driver/Driver_USART.c"
  "/home/ubuntu/packs/ARM/V2M_MPS3_SSE_300_BSP/1.2.0/Native_Driver/arm_mps3_io_drv.c"
  "/home/ubuntu/packs/ARM/V2M_MPS3_SSE_300_BSP/1.2.0/Native_Driver/uart_cmsdk_drv.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/MDK/library/entropy_poll_hw.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/MDK/library/iot_socket/net_sockets.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/aes.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/arc4.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/aria.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/asn1parse.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/asn1write.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/base64.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/bignum.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/blowfish.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/camellia.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/ccm.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/certs.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/chacha20.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/chachapoly.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/cipher.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/cipher_wrap.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/cmac.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/ctr_drbg.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/debug.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/des.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/dhm.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/ecdh.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/ecdsa.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/ecjpake.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/ecp.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/ecp_curves.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/entropy.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/entropy_poll.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/error.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/gcm.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/havege.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/hkdf.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/hmac_drbg.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/md.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/md2.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/md4.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/md5.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/memory_buffer_alloc.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/nist_kw.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/oid.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/pem.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/pk.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/pk_wrap.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/pkcs11.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/pkcs12.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/pkcs5.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/pkparse.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/pkwrite.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/platform.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/platform_util.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/poly1305.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/psa_crypto.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/psa_crypto_se.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/psa_crypto_slot_management.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/psa_crypto_storage.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/psa_its_file.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/ripemd160.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/rsa.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/rsa_internal.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/sha1.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/sha256.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/sha512.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/ssl_cache.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/ssl_ciphersuites.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/ssl_cli.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/ssl_cookie.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/ssl_msg.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/ssl_srv.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/ssl_ticket.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/ssl_tls.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/threading.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/timing.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/version.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/version_features.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/x509.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/x509_create.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/x509_crl.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/x509_crt.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/x509_csr.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/x509write_crt.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/x509write_csr.c"
  "/home/ubuntu/packs/ARM/mbedTLS/1.7.0/library/xtea.c"
  "/home/ubuntu/packs/AWS/backoffAlgorithm/1.0.0-Beta/libraries/standard/backoffAlgorithm/source/backoff_algorithm.c"
  "/home/ubuntu/packs/AWS/coreMQTT/1.1.0-Beta/libraries/standard/coreMQTT/source/core_mqtt.c"
  "/home/ubuntu/packs/AWS/coreMQTT/1.1.0-Beta/libraries/standard/coreMQTT/source/core_mqtt_serializer.c"
  "/home/ubuntu/packs/AWS/coreMQTT/1.1.0-Beta/libraries/standard/coreMQTT/source/core_mqtt_state.c"
  "/home/ubuntu/packs/AWS/coreMQTT_Agent/1.0.1-Beta/libraries/aws/coreMQTT-Agent/source/core_mqtt_agent.c"
  "/home/ubuntu/packs/AWS/coreMQTT_Agent/1.0.1-Beta/libraries/aws/coreMQTT-Agent/source/core_mqtt_agent_command_functions.c"
  "/home/ubuntu/packs/AWS/corePKCS11/3.0.0-Beta/libraries/standard/corePKCS11/source/core_pkcs11.c"
  "/home/ubuntu/packs/AWS/corePKCS11/3.0.0-Beta/libraries/standard/corePKCS11/source/core_pki_utils.c"
  "/home/ubuntu/packs/AWS/corePKCS11/3.0.0-Beta/libraries/standard/corePKCS11/source/dependency/3rdparty/mbedtls_utils/mbedtls_error.c"
  "/home/ubuntu/packs/AWS/corePKCS11/3.0.0-Beta/libraries/standard/corePKCS11/source/dependency/3rdparty/mbedtls_utils/mbedtls_utils.c"
  "/home/ubuntu/packs/AWS/corePKCS11/3.0.0-Beta/libraries/standard/corePKCS11/source/portable/mbedtls/core_pkcs11_mbedtls.c"
  "/home/ubuntu/packs/Keil/ARM_Compiler/1.7.1/Source/EventRecorder.c"
  "/home/ubuntu/packs/Keil/ARM_Compiler/1.7.1/Source/retarget_io.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/Board/AVH_MPS3_Corstone-300/Driver/vio_V2M-MPS3-SSE-300.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/Board/AVH_MPS3_Corstone-300/main.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/Board/AVH_MPS3_Corstone-300/retarget_stdio.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/Interface/AWS/Socket/iot_secure_sockets.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/Interface/AWS/Socket/network_startup.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/RTE/Device/SSE-300-MPS3/startup_fvp_sse300_mps3.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/RTE/Device/SSE-300-MPS3/system_SSE300MPS3.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/Socket/VSocket/iot_socket.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/Socket/VSocket/socket_startup.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/demos/common/pkcs11_helpers/pkcs11_helpers.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/demos/coreMQTT/mqtt_demo_mutual_auth.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/demos/demo_runner/aws_demo.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/demos/demo_runner/iot_demo_freertos.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/demos/demo_runner/iot_demo_runner.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/demos/network_manager/aws_iot_network_manager.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/abstractions/platform/freertos/iot_clock_freertos.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/abstractions/platform/freertos/iot_threads_freertos.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/abstractions/transport/secure_sockets/transport_secure_sockets.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/c_sdk/standard/common/iot_device_metrics.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/c_sdk/standard/common/iot_init.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/c_sdk/standard/common/iot_static_memory_common.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/c_sdk/standard/common/taskpool/iot_taskpool.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/c_sdk/standard/common/taskpool/iot_taskpool_static_memory.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/freertos_plus/standard/crypto/src/iot_crypto.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/freertos_plus/standard/tls/src/iot_tls.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/logging/iot_logging.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/libraries/logging/iot_logging_task_dynamic_buffers.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/amazon-freertos/ports/pkcs11/core_pkcs11_pal.c"
  "/home/ubuntu/workspace/ctools_lab/example/IoT/AWS_MQTT_MutualAuth_Demo/app_main.c"
)

# Toolchain config map

include ("/opt/ctools/etc/AC6.6.18.0.cmake")

# Setup project

project(${TARGET} LANGUAGES C)

# Global Flags

set(CMAKE_C_FLAGS "${CC_CPU} ${CC_DEFINES} ${CC_SECURE} ${CC_FLAGS} ${CC_FLAGS_GLOBAL} ${CC_SYS_INC_PATHS}")
set(CMAKE_C_LINK_FLAGS "${LD_CPU} ${LD_SCRIPT} ${LD_SECURE} ${LD_FLAGS_GLOBAL} ${LD_FLAGS}")

# Compilation Database

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_custom_target(database COMMAND ${CMAKE_COMMAND} -E copy_if_different "${INT_DIR}/compile_commands.json" "${OUT_DIR}")

# Setup Target

add_executable(${TARGET} ${CC_SRC_FILES})
set(CMAKE_EXECUTABLE_SUFFIX ${EXE_SUFFIX})
set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR})
target_include_directories(${TARGET} PUBLIC ${INC_PATHS})

# Bin and Hex Conversion

add_custom_command(TARGET ${TARGET} POST_BUILD COMMAND ${CMAKE_OBJCOPY} ${ELF2HEX})
add_custom_command(TARGET ${TARGET} POST_BUILD COMMAND ${CMAKE_OBJCOPY} ${ELF2BIN})
