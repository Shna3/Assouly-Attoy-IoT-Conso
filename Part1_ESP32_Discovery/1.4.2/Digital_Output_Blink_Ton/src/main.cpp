// 1.4.2 Digital output 1.blink a LED during 9 * 50 ms
// See https://docs.espressif.com/projects/arduino-esp32/en/latest/api/adc.html
// Example of using ADC on ESP32 with Arduino framework
#include <Arduino.h>
#include <driver/adc.h>

int N = 9; //pair parameter
int Ton = 50 * N; //50*N ms = 450 ms

void setup() {
    Serial.begin(115200);
    pinMode(4, OUTPUT);
}
void loop() {

    digitalWrite(4, HIGH); // LED ON during Ton time

    delay(Ton);

    digitalWrite(4, LOW);

    delay(2000 - Ton);
}

