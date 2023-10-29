#ifndef Wifi_Setup_H
#define Wifi_Setup_H

#define wifi_state_Pin 26  // wifi status LED

#define WIFI_SSID "Galaxy A526AD7"
#define WIFI_PASSWORD "pqmm9039"

#include <WiFi.h>

void connectToWiFi();
void customDelay(unsigned int milliseconds);

#endif