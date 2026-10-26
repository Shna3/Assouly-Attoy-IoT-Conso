//1.5.2 ADC 1. LDR value in the range 0-4095
// See https://docs.espressif.com/projects/arduino-esp32/en/latest/api/adc.html
// Example of using ADC on ESP32 with Arduino framework
#include <Arduino.h>
#include <driver/adc.h>

void setup() {
    Serial.begin(115200);
    // Configure ADC on GPIO 36 (ADC1_CH0)
    analogSetPinAttenuation(36, (adc_attenuation_t)ADC_ATTEN_DB_12);  // Set attenuation to 12dB (max ~3.1V)
    analogSetWidth(12);                                               // Set ADC resolution to 12 bits (0-4095)
}

void loop() {

    // Read ADC value (0-4095)
    int value = analogRead(36);

    Serial.print("[Binôme 09 : ASSOULY & ATTOY] LDR = ");
    Serial.println(value);

    delay(1000);
}