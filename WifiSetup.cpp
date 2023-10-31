#include "WifiSetup.h"
#include "General_Cred.h"

void customDelay(unsigned int milliseconds) {
  unsigned int startTime = millis();
  while (millis() - startTime < milliseconds) {
  }
}

void connectToWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  for (byte i; i < 10; i++) {
    Serial.println("Connecting to WiFi...");
    customDelay(1000);
    if (WiFi.status() == WL_CONNECTED) {
      digitalWrite(wifi_state_Pin, 1);
      Serial.println("Connected to Wi-Fi");
      Serial.print("IP Address: ");
      Serial.println(WiFi.localIP());
      break;
    }
  }
}