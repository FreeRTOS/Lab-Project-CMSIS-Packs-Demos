#!/bin/bash

#!/bin/bash

board=""
binary=""

case $1 in
    "pub_sub")
        board="VHT_MPS3_Corstone_SSE-300"
        folder="mqtt_pub_sub"
        project="AWS_MQTT_PubSub_Demo.Release+AVH_MPS3_Corstone-300"
        ;;
    
    "kws")
        board="VHT_Corstone_SSE-300_Ethos-U55"
        folder="micro_speech"
        project="Microspeech_Demo.Debug+AVH_MPS3_Corstone-300"
        ;;
    
    *)
        echo "please select a project [pub_sub|kws]"
        exit 1
        ;;
esac

$board -C mps3_board.visualisation.disable-visualisation=1 \
-C mps3_board.telnetterminal0.start_telnet=0 \
-C mps3_board.uart0.out_file=- \
-a $folder/${project}_OutDir/${project}.axf
