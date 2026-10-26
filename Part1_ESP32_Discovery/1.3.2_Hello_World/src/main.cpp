// Part 1.3.2
// See https://docs.espressif.com/projects/arduino-esp32/en/latest/api/adc.html
// Example of using ADC on ESP32 with Arduino framework
#include <Arduino.h>
#include <driver/adc.h>

void setup() {
   Serial.begin(115200);                                            // Set ADC resolution to 12 bits (0-4095)
}
void loop() {

    Serial.println("[Binôme 09 : ASSOULY & ATTOY] Hello Arduino World!");

    delay(2000);  // Wait 2 second
}




