//
// Created by oh it works on 5/12/2023.
//
#include "project_config.h"

#include "Soil_moisture_sensor.hpp"

#include <Arduino.h>


namespace sms {
    /* Change these values based on your calibration values */

// Sensor pins
#define sensorPower 7
#define sensorPin A0

    mmg::MessageNode node;

    void setup() {
        pinMode(sensorPower, OUTPUT);

        // Initially keep the sensor OFF
        digitalWrite(sensorPower, LOW);

        node.set_name("sms");

    }

    void loop(mmg::MessageManager& manager) {
        //get the reading from the function below and print it
        static int moisture = readSensor();
        Serial.print("Analog Output: ");
        Serial.println(moisture);
        // Determine status of our soil
        if (moisture < SOIL_WET) {
            Serial.println("Status: Soil is too wet");
            node.message_info = 1;
        } else if (moisture < SOIL_DRY) {
            Serial.println("Status: Soil moisture is perfect");
            node.message_info = 0;
        } else {
            Serial.println("Status: Soil is too dry - time to water!");
            node.message_info = 2;
        }
        node.data_ptr = &moisture;
        manager.push(node);

//        delay(1000);    // Take a reading every second for testing
        // Normally you should take reading perhaps once or twice a day
        Serial.println();
    }

//  This function returns the analog soil moisture measurement
    int readSensor() {
        digitalWrite(sensorPower, HIGH);    // Turn the sensor ON
        delay(10);                          // Allow power to settle
        int val = analogRead(sensorPin);    // Read the analog value form sensor
        digitalWrite(sensorPower, LOW);     // Turn the sensor OFF
        return val;                         // Return analog moisture value
    }
}


#ifndef IS_MAIN
void setup() {
    sms::setup();
}

void loop(){
    sms::loop();
}
#endif
