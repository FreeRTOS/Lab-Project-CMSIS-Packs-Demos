#!/bin/bash

csolution convert -s IoT.csolution.yml -c AWS_MQTT_MutualAuth_Demo.Release+AVH_MPS3_Corstone-300
cbuild AWS_MQTT_MutualAuth_Demo/AWS_MQTT_MutualAuth_Demo.Release+AVH_MPS3_Corstone-300.cprj 
