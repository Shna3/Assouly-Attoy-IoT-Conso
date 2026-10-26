//1.5.2 ADC 2. LDR value in the range 0-255
// See https://docs.espressif.com/projects/arduino-esp32/en/latest/api/adc.html
// Example of using ADC on ESP32 with Arduino framework
#include <Arduino.h>
#include <driver/adc.h>

int sensorMin = 4095;
int sensorMax = 0;

void setup() {
    Serial.begin(115200);
    // Configure ADC on GPIO 36 (ADC1_CH0)
    analogSetPinAttenuation(36, (adc_attenuation_t)ADC_ATTEN_DB_12);  // Set attenuation to 12dB (max ~3.1V)
    analogSetWidth(12); // Set ADC resolution to 12 bits (0-4095)

    Serial.println("Calibration de la LDR");

    int i = 0;

    while (i < 500) { // 5s calibration - value every 10 ms
        int value = analogRead(36);

        if (value < sensorMin)
            sensorMin = value;

        if (value > sensorMax)
            sensorMax = value;

        i++;
        delay(10);
    }

    Serial.print("[Binôme 09 : ASSOULY & ATTOY] ");
    Serial.print("Min = ");
    Serial.println(sensorMin);

    Serial.print("[Binôme 09 : ASSOULY & ATTOY] ");
    Serial.print("Max = ");
    Serial.println(sensorMax);
}

void loop() {

    int value = analogRead(36);

    int calibrated = map(value, sensorMin, sensorMax, 0, 255);

    calibrated = constrain(calibrated, 0, 255);

    Serial.print("[Binôme 09 : ASSOULY & ATTOY] ");

    Serial.print("Raw = ");
    Serial.print(value);

    Serial.print(" | Calibrated = ");
    Serial.println(calibrated);

    delay(1000);
}