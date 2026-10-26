//// 1.4.2 : digital input 2.interruption
// See https://docs.espressif.com/projects/arduino-esp32/en/latest/api/adc.html
// Example of using ADC on ESP32 with Arduino framework
#include <Arduino.h>
#include <driver/adc.h>
volatile int counter = 0;
volatile int change = 0;

void button(){
    counter++;
    change = 1;
}

void setup() {
    Serial.begin(115200);
    pinMode(4, INPUT);

    // button function executed only when GPIO 4 is in FALLING state (which means button has been pressed then released)
    attachInterrupt(digitalPinToInterrupt(4), button, FALLING); 
}

void loop() {

    if(change == 1){
        change = 0;
        Serial.println("[Binôme 09 : ASSOULY & ATTOY] Number of times the button was pressed and released : " + String(counter));
    }

    delay(5);
}


