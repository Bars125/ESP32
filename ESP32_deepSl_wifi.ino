#define THRESHOLD 40  // Greater the value, more the sensitivity (wake-up Pin)

#include <Wire.h>
#include "I2SInit.h"
#include "WifiSetup.h" 
#include "SpiffSetup.h"

#define record_Pin 35  // record audio while holding a button

void customDelay(unsigned int milliseconds) {
  unsigned int startTime = millis();
  while (millis() - startTime < milliseconds) {
  }
}

void print_wakeup_touchpad() {
  touch_pad_t touchPin = esp_sleep_get_touchpad_wakeup_status();
  if (touchPin == 3) {
    Serial.println("Wakeup caused by touchpad on GPIO 15");
  } else {
    Serial.println("Wakeup not by touchpad");
  }
}

void start_deep_sleep() {
  Serial.println("");
  Serial.println("Going to sleep now");
  esp_deep_sleep_start();
}

void setup() {

  // Setting up the Serial Monitor
  Serial.begin(115200);
  customDelay(1000);

  // I2S setup
  //i2s_driver_install(i2s_num, &i2s_config, 0, NULL);  // ESP32 will allocated resources to run I2S
  //i2s_set_pin(i2s_num, &pin_config);                  // Tell it the pins you will be using

  // Led indication setup
  pinMode(wifi_state_Pin, OUTPUT);
  pinMode(record_Pin, INPUT_PULLUP);
  digitalWrite(wifi_state_Pin, 0);  // wifi status LED make sure it's 0

  // Wake up settings
  print_wakeup_touchpad();
  touchSleepWakeUpEnable(T3, THRESHOLD);  // Setup sleep, wakeup on Touch Pad 3 (GPIO15)

  //Programm  starts Here

  connectToWiFi();  // right after being waken up connect to wifi

  // main cycle: recoding after pressing the button; quit when wifi conn-ion is lost;
  while (1) {

    //Recording
    if (digitalRead(record_Pin) == LOW) {
      Serial.println("Recording...");
      while (digitalRead(record_Pin) == LOW) {
        // Read audio data from the I2S interface
      }
      Serial.println("Recorded! Processing...");
      break;
    }
    if (WiFi.status() != WL_CONNECTED) {
      digitalWrite(wifi_state_Pin, 0);
      break;
    }

    //Playing
    //i2s_write(i2s_num,&Value32Bit,4,&BytesWritten,portMAX_DELAY ); 
  }
  customDelay(1000);
  start_deep_sleep();
}

void loop() {

}