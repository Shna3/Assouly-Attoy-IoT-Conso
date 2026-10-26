// 1.5.2 ADC 3. potentiometer value in the range of 0-255
#include <Arduino.h>
#include <driver/adc.h>

#define POT_PIN 36

int sensorMin = 4095;
int sensorMax = 0;

void setup() {

    Serial.begin(115200);

    analogSetPinAttenuation(POT_PIN, (adc_attenuation_t)ADC_ATTEN_DB_12);

    analogSetWidth(12);

    Serial.println("Calibration du potentiometre");

    for(int i = 0; i < 500; i++) { // 5s calibration

        int value = analogRead(POT_PIN);

        if(value < sensorMin)
            sensorMin = value;

        if(value > sensorMax)
            sensorMax = value;

        delay(10);
    }

    Serial.print("[Binome 09 : ASSOULY & ATTOY] ");
    Serial.print("Min = ");
    Serial.println(sensorMin);

    Serial.print("[Binome 09 : ASSOULY & ATTOY] ");
    Serial.print("Max = ");
    Serial.println(sensorMax);
}

void loop() {

    int value = analogRead(POT_PIN);

    int calibrated = map(value, sensorMin, sensorMax, 0, 255);

    calibrated = constrain(calibrated, 0, 255);

    Serial.print("[Binome 09 : ASSOULY & ATTOY] ");
    Serial.print("Raw = ");
    Serial.print(value);

    Serial.print(" | Calibrated = ");
    Serial.println(calibrated);

    delay(1000);
}