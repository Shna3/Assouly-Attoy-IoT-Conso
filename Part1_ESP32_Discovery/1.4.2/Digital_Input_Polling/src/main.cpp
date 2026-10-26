// 1.4.2 : digital input 1."polling"
// See https://docs.espressif.com/projects/arduino-esp32/en/latest/api/adc.html
// Example of using ADC on ESP32 with Arduino framework
#include <Arduino.h>
#include <driver/adc.h>

int value = 0; //button value to LOW
int counter = 0;

void setup() {
    Serial.begin(115200);
    pinMode(4, INPUT);
}
void loop() {
    
    int state = digitalRead(4);

    if(state == 1){ // button is pressed
        value = 1;
    };

    if(state == 0 && value == 1){ // button is pressed then released
        value = 0;
        counter++;
        Serial.println("[Binôme 09 : ASSOULY & ATTOY] Number of times the button was pressed and released : " + String(counter));
    };

    delay(20);

}


