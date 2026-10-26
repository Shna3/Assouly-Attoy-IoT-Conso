// 2.1.2 LCD screen 2.BME680 temperature and humidity
#include <Adafruit_Sensor.h>
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "Adafruit_BME680.h"

#define SEALEVELPRESSURE_HPA (1013.25)
LiquidCrystal_I2C lcd(0x27,20,4);

/*******************
 * Choose between I2C or SPI
 */
#define USE_I2C  // Comment this line to use SPI instead of I2C

#ifdef USE_I2C
// Connect "SCL" pin on the BME680 with GPIO 22 on the ESP32
// Connect "SDA" pin on the BME680 with GPIO 21 on the ESP32
Adafruit_BME680 bme;
#else
#define BME_SCK 14   // Connect "SCL" pin on the BME680 with GPIO 14 on the ESP32
#define BME_MISO 12  // Connect "SDO" pin on the BME680 with GPIO 12 on the ESP32
#define BME_MOSI 13  // Connect "SDA" pin on the BME680 with GPIO 13 on the ESP32
#define BME_CS 15    // Connect "CS"  pin on the BME680 with GPIO 15 on the ESP32
Adafruit_BME680 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK);
#endif

int counter_s = 0;
void setup() {
    Serial.begin(115200);
    while (!Serial);
    Serial.println(F("BME680 test"));

    if (!bme.begin()) {
        Serial.println("Could not find a valid BME680 sensor, check wiring!");
        while (1);
    }

    // Set up oversampling and filter initialization
    bme.setTemperatureOversampling(BME680_OS_8X);
    bme.setHumidityOversampling(BME680_OS_2X);

    lcd.init();// initialize the lcd 
    lcd.backlight();
}

void loop() {

    if (!bme.performReading()) {
        Serial.println("Failed to perform reading :(");
        return;
    }

    lcd.setCursor(0,0);
    lcd.print("Temperature : " + String(bme.temperature) + "*C");

    lcd.setCursor(0,1);
    lcd.print("Humidite " + String(bme.humidity) + "%");

    delay(100);

}





