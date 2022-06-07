# ARM-AVH-IoT-Demo
Refrence example to showcase AWS IoT connectivity using ARM CMSIS packs for FreeRTOS modular libraries running on ARM Virtual Hardware.

## Hardware

Virtual Hardware: AVH Corstone 300

Processor : ARM Cortex M55


## Use Vscode and EC2 Instance with Virtual Hardware

1. Create an EC2 instance containing ARM Corestone 300 Virtual Hardware. Goto this [page](https://www.arm.com/products/development-tools/simulation/virtual-hardware) for more details on 
how to sign up for an EC2 instance contianing ARM AMI.
2. Login to the EC2 Instance and clone the repo:
```
git clone git@github.com:ravibhagavandas/ARM-AVH-IoT-Demo.git
```
3. Setup Vscode Remote development if needed: https://code.visualstudio.com/docs/remote/ssh
4. Install CMSIS packs for all dependent libraries. Goto repository home folder and execute:
```
./install_cpacks.sh
```

6. Configure ThingName, Endpoint and ROOT CA in file `mqtt_pub_sub/config_files/demo_config.h`:
- Root CA  PEM for AWS IoT Server certificate: `democonfigROOT_CA_PEM`
- Device Thing Name: `democonfigCLIENT_IDENTIFIER`
- MQTT Broker Endpoint: `democonfigMQTT_BROKER_ENDPOINT`
- MQTT Broker Port: `democonfigMQTT_BROKER_PORT`

7. Configure following credentials in file `mqtt_pub_sub/config_files/aws_clientcredential_keys.h`:
- Device private Key PEM file: `keyCLIENT_CERTIFICATE_PEM` 
- Device certificate PEM file: `keyCLIENT_PRIVATE_KEY_PEM` 

8. Build MQTT Pub Sub Multithreaded demo for AVH Corestone 300:
```
./build.sh
```

8. Run the demo:
```
./run.sh
```
