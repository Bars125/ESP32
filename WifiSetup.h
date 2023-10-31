#ifndef Wifi_Setup_H
#define Wifi_Setup_H

#define wifi_state_Pin 26  // wifi status LED

#include <WiFi.h>

void connectToWiFi();
void customDelay(unsigned int milliseconds);

#endif