#include "config.hpp"

#ifdef IS_MAIN

#include "display.hpp"
#include "Ultrasonic.hpp"
#include "Soil_moisture_sensor.hpp"
#include "ir_sensor.hpp"
#include "uv_sensor.hpp"

#include <Arduino.h>


void setup() {
    Serial.begin(9600);

    dis::setup();

    ult::setup();

    sms::setup();

    irs::setup();

    uvs::setup();
}

void loop() {
    // mail loop
//    u8g2.clearDisplay();
//    u8g2.print(ult::loop());
//    u8g2.sendBuffer();
//
//    sms::loop();

//    irs::loop();
    dis::loop();
    delay(1000);
}

#endif
