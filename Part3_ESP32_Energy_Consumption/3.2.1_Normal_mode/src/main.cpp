// 3.2.1 Normal mode - Consumption
#include <Arduino.h>
#include <driver/adc.h>
#define TIME_TO_SLEEP 2000
#define LED_PIN 2

void setup(){
    pinMode(LED_PIN,OUTPUT);
}

void loop(){
  digitalWrite(LED_PIN,HIGH);
  delay(TIME_TO_SLEEP);
  digitalWrite(LED_PIN,LOW);
  delay(TIME_TO_SLEEP);
}

