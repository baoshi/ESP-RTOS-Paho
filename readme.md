**MQTT client with ESP8266 RTOS SDK**

This project contains ESP8266 port of the embedded C client in Eclipse Paho project (http://www.eclipse.org/paho/) 
It uses ESP8266 RTOS SDK available at https://github.com/espressif/ESP8266_RTOS_SDK

**Features**
* Based on Eclipse Paho project
* Improved error handling, auto recovery on many errors.
* Easy integration with RTOS

**Usage**

To connect to broker
```c
struct Network network;
MQTTClient client = DefaultClient;
MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
unsigned char mqtt_buf[100];
unsigned char mqtt_readbuf[100];

NewNetwork(&network);
ConnectNetwork(&network, MQTT_HOST, MQTT_PORT);
NewMQTTClient(&client, &network, 5000, mqtt_buf, 100, mqtt_readbuf, 100);
data.willFlag = 0;
data.MQTTVersion = 3;
data.clientID.cstring = mqtt_client_id; // you client's unique identifier
data.username.cstring = MQTT_USER;
data.password.cstring = MQTT_PASS;
data.keepAliveInterval = 10; // interval for PING message to be sent (seconds)
data.cleansession = 0;
MQTTConnect(&client, &data);
```

To subscribe a topic
```c
// Callback when receiving subscribed message
LOCAL void ICACHE_FLASH_ATTR topic_received(MessageData* md)
{
    int i;
    MQTTMessage* message = md->message;
    dmsg_puts("Received Topic ");
    for (i = 0; i t; md->topic->lenstring.len; ++i)
        dmsg_putchar(md->topic->lenstring.data[i]);
    dmsg_puts(", Message ");
    for (i = 0; i < (int)message->payloadlen; ++i)
        dmsg_putchar(((char*)message->payload)[i]);
    dmsg_puts("\r\n");
}
main()
{
    ...
    MQTTSubscribe(&client, "/mytopic", QOS1, topic_received);
}    
```

To publish a message
```c
char msg[PUB_MSG_LEN];
MQTTMessage message;
message.payload = msg;
message.payloadlen = PUB_MSG_LEN;
message.dup = 0;
message.qos = QOS1;
message.retained = 0;
MQTTPublish(&client, "topic", &message);
```

More details at http://www.ba0sh1.com/esp8266-mqtt-rtos

Copyright (c) 2015, Baoshi Zhu. All rights reserved.
Source code in this project is governed by BSD-style license that can be found in the LICENSE.txt file. 

 