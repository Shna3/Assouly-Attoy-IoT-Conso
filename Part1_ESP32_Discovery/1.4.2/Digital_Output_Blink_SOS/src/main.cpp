//1.4.2 Digital output 2.SOS in morse code
// See https://docs.espressif.com/projects/arduino-esp32/en/latest/api/adc.html
// Example of using ADC on ESP32 with Arduino framework
#include <Arduino.h>
#include <driver/adc.h>

int dit = 300; //0.3 seconds

void setup() {
    Serial.begin(115200);
    pinMode(4, OUTPUT);
}

void S(){
    digitalWrite(4, HIGH);
    delay(dit);
    digitalWrite(4, LOW);
    delay(dit);
    digitalWrite(4, HIGH);
    delay(dit);
    digitalWrite(4, LOW);
    delay(dit);
    digitalWrite(4, HIGH);
    delay(dit);
    digitalWrite(4, LOW);
}

void O(){
    digitalWrite(4, HIGH);
    delay(dit * 3);
    digitalWrite(4, LOW);
    delay(dit);
    digitalWrite(4, HIGH);
    delay(dit * 3);
    digitalWrite(4, LOW);
    delay(dit);
    digitalWrite(4, HIGH);
    delay(dit * 3);
    digitalWrite(4, LOW);
}
void loop() {
    //SOS in morse code : ··· — — — ···
    S();
    delay(3 * dit);

    O();
    delay(3 * dit);

    S();
    delay(7 * dit);
}




