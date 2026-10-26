
//2.2.1 Get weather data 
// This code is part of an ESP32 Arduino project that connects to a WiFi network,
// fetches weather data from the WeatherStack API, and displays it on the Serial Monitor.
// It uses the ArduinoJson library to parse the JSON response from the API.
#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>

#define WEATHERSTACK_API_KEY "WEATHERSTACK_API_KEY" //modify
const char* ssid = "ssid"; //modify
const char* password = "password"; //modify

void setup() {
    Serial.begin(115200);
    delay(10);

    // We start by connecting to a WiFi network
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void loop() {
    // wait for WiFi connection
    if ((WiFi.status() == WL_CONNECTED)) {
        HTTPClient http;

        Serial.print("[HTTP] begin...\n");
        String url = String("http://api.weatherstack.com/current?access_key=") + WEATHERSTACK_API_KEY + "&query=Paris";
        http.begin(url);

        Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        // httpCode will be negative on error
        if (httpCode == HTTP_CODE_OK) {
            String payload = http.getString();
            //Serial.println(payload);

            // Convert to JSON
            JsonDocument doc;
            deserializeJson(doc, payload);

            // Read and display values
            String city = doc["location"]["name"];
            String time = doc["location"]["localtime"];
            String temp = doc["current"]["temperature"];
            String wind = doc["current"]["wind_speed"];
            //String desc = doc["current"]["weather_descriptions"][0];
            Serial.println("[Binôme 09 : ASSOULY & ATTOY] Name of the city: " + city + ", Current time: " + time + ", Temperature: " + temp + "*C, Wind speed: " + wind);

        } else {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }
        http.end();
    }
    delay(5000);
}
