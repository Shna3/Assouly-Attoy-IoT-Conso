// 3.2.2 Light sleep mode - consumption
#include <Arduino.h>
#include <driver/adc.h>
#define uS_TO_mS_FACTOR 1000ULL
#define TIME_TO_SLEEP  2000
#define LED_PIN 2
void setup(){
  pinMode(LED_PIN,OUTPUT);
  // ESP32 wakes after TIME_TO_SLEEP milliseconds
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_mS_FACTOR);
}

void loop(){
  digitalWrite(LED_PIN,HIGH);
  delay(TIME_TO_SLEEP);
  digitalWrite(LED_PIN,LOW);
  esp_light_sleep_start();
}