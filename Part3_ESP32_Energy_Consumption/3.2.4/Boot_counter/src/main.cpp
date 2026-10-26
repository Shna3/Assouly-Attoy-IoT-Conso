// 3.2.4 Boot counter 1.Ordinary global variable
#include <Arduino.h>
#include <driver/adc.h>
#define uS_TO_mS_FACTOR 1000ULL
#define TIME_TO_SLEEP 2000

int bootCount = 0;

void setup() {

  Serial.begin(115200);
  delay(1000);

  bootCount++;

  Serial.print("[Binome 9 - ASSOULY & ATTOY] ");
  Serial.print("boot # - ");
  Serial.println(bootCount);

  Serial.print(" - reset reason = ");
  Serial.println(esp_reset_reason());

  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP);

  Serial.println("Sleep");
  delay(100);

  esp_deep_sleep_start();
}

void loop() {
}
