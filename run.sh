#!/bin/bash
VHT_MPS3_Corstone_SSE-300 -C mps3_board.visualisation.disable-visualisation=1 \
-C mps3_board.telnetterminal0.start_telnet=0 \
-C mps3_board.uart0.out_file=- \
-a mqtt_mutual_auth/AWS_MQTT_MutualAuth_Demo.Release+AVH_MPS3_Corstone-300_OutDir/AWS_MQTT_MutualAuth_Demo.Release+AVH_MPS3_Corstone-300.axf
