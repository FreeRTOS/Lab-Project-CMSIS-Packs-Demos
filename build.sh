#!/bin/bash

project=""
clean="no"
folder=""
case $1 in
    "pub_sub")
        folder="mqtt_pub_sub"
        project="AWS_MQTT_PubSub_Demo.Release+AVH_MPS3_Corstone-300"
        ;;
    
    "kws")
        folder="micro_speech"
        project="Microspeech_Demo.Release+AVH_MPS3_Corstone-300"
        ;;
    
    *)
        echo "please select a project [pub_sub|kws]"
        exit 1
        ;;
esac

case $2 in
    "-c")
        clean="yes"
        ;;
    *)
        clean="no"
        ;;
esac

if [ "$clean" == "yes" ]; then
    cbuild ${folder}/$project.cprj -c
else
    csolution convert -s IoT.csolution.yml -c $project
    cbuild ${folder}/${project}.cprj
fi
