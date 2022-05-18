#!/bin/bash

case $1 in
    "-c")
        cbuild aws_mqtt_mutual_auth/AWS_MQTT_MutualAuth_Demo.Release+AVH_MPS3_Corstone-300.cprj -c
        ;;
    *)
        csolution convert -s IoT.csolution.yml -c AWS_MQTT_MutualAuth_Demo.Release+AVH_MPS3_Corstone-300
        cbuild aws_mqtt_mutual_auth/AWS_MQTT_MutualAuth_Demo.Release+AVH_MPS3_Corstone-300.cprj
        ;;
esac
