/**
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of the
 * network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2015 Sensnology AB
 * Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors
 *
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 *******************************
 *
 * REVISION HISTORY
 * Version 1.0 - Henrik Ekblad
 *
 * DESCRIPTION
 * The ESP8266 MQTT gateway sends radio network (or locally attached sensors) data to your MQTT broker.
 * The node also listens to MY_MQTT_TOPIC_PREFIX and sends out those messages to the radio network
 *
 * LED purposes:
 * - To use the feature, uncomment any of the MY_DEFAULT_xx_LED_PINs in your sketch
 * - RX (green) - blink fast on radio message recieved. In inclusion mode will blink fast only on presentation recieved
 * - TX (yellow) - blink fast on radio message transmitted. In inclusion mode will blink slowly
 * - ERR (red) - fast blink on error during transmission error or recieve crc error
 *
 * See http://www.mysensors.org/build/esp8266_gateway for wiring instructions.
 * nRF24L01+  ESP8266
 * VCC        VCC
 * CE         GPIO4
 * CSN/CS     GPIO15
 * SCK        GPIO14
 * MISO       GPIO12
 * MOSI       GPIO13
 *
 * Not all ESP8266 modules have all pins available on their external interface.
 * This code has been tested on an ESP-12 module.
 * The ESP8266 requires a certain pin configuration to download code, and another one to run code:
 * - Connect REST (reset) via 10K pullup resistor to VCC, and via switch to GND ('reset switch')
 * - Connect GPIO15 via 10K pulldown resistor to GND
 * - Connect CH_PD via 10K resistor to VCC
 * - Connect GPIO2 via 10K resistor to VCC
 * - Connect GPIO0 via 10K resistor to VCC, and via switch to GND ('bootload switch')
 *
  * Inclusion mode button:
 * - Connect GPIO5 via switch to GND ('inclusion switch')
 *
 * Hardware SHA204 signing is currently not supported!
 *
 * Make sure to fill in your ssid and WiFi password below for ssid & pass.
 */

 /******************************************************************* 
 * EDIT: Jan 29, 2018
 * DESCRIPTION 
 * As part of an one-year project at Herman Hollerith Zentrum (HHZ),
 * an IoT environment was set up. The original script was modified 
 * to integrate the sensor into our IoT environment.
 * 
 * ADDITIONAL INFORMATION
 * - EG-120 uses channel 0 -> 2.400 GHz
 * - EG-125 uses channel 1 -> 2.401 GHz
 * - EG-126 uses channel 2 -> 2.402 GHz
 * 
 *  Modified by manh3141 
 */

// Enable debug prints to serial monitor
#define MY_DEBUG

// Use a bit lower baudrate for serial prints on ESP8266 than default in MyConfig.h
#define MY_BAUD_RATE 9600

// Enables and select radio type (if attached)
#define MY_RADIO_NRF24
//#define MY_RADIO_RFM69

// Define the channel to be used
#define MY_RF24_CHANNEL  2 // Channel

#define MY_GATEWAY_MQTT_CLIENT
#define MY_GATEWAY_ESP8266

// Set this node's subscribe and publish topic prefix
#define MY_MQTT_PUBLISH_TOPIC_PREFIX "hhz/126_2"
#define MY_MQTT_SUBSCRIBE_TOPIC_PREFIX "input_hhz/126_2"

// Set MQTT client id
#define MY_MQTT_CLIENT_ID "gateway126_2"

// Enable these if your MQTT broker requires usenrame/password
#define MY_MQTT_USER "digitalhhz"
#define MY_MQTT_PASSWORD "hackathon"

// Set WIFI SSID and password
#define MY_ESP8266_SSID "Digital_HHZ_125"
#define MY_ESP8266_PASSWORD "HHZ_IOT17"

// Set the hostname for the WiFi Client. This is the hostname
// it will pass to the DHCP server if not static.
#define MY_ESP8266_HOSTNAME "mysensors_gateway-126_2"

// Enable MY_IP_ADDRESS here if you want a static ip address (no DHCP)
//#define MY_IP_ADDRESS 192,168,178,87

// If using static ip you need to define Gateway and Subnet address as well
//#define MY_IP_GATEWAY_ADDRESS 192,168,178,1
//#define MY_IP_SUBNET_ADDRESS 255,255,255,0


// MQTT broker ip address.
#define MY_CONTROLLER_IP_ADDRESS 192, 168, 0, 12

// The MQTT broker port to to open
#define MY_PORT 1883

/*
// Enable inclusion mode
#define MY_INCLUSION_MODE_FEATURE
// Enable Inclusion mode button on gateway
#define MY_INCLUSION_BUTTON_FEATURE
// Set inclusion mode duration (in seconds)
#define MY_INCLUSION_MODE_DURATION 60
// Digital pin used for inclusion mode button
#define MY_INCLUSION_MODE_BUTTON_PIN  3
// Set blinking period
#define MY_DEFAULT_LED_BLINK_PERIOD 300
// Flash leds on rx/tx/err
#define MY_DEFAULT_ERR_LED_PIN 16  // Error led pin
#define MY_DEFAULT_RX_LED_PIN  16  // Receive led pin
#define MY_DEFAULT_TX_LED_PIN  16  // the PCB, on board LED
*/

#include <ESP8266WiFi.h>
#include <MySensors.h>

void setup()
{
}

void presentation()
{
  // Present locally attached sensors here
}


void loop()
{
  // Send locally attech sensors data here
  Serial.println("Sensor:");
  Serial.println(MY_ESP8266_HOSTNAME);
  Serial.println("Node ID:");
  Serial.println(MY_MQTT_CLIENT_ID);
  Serial.println("Channel:");
  Serial.println(MY_RF24_CHANNEL);
}
