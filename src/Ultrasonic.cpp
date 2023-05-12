//
// Created by oh it works on 5/12/2023.
//

#include "project_config.h"

#define TrigPin 6
#define EchoPin 7

#include <Arduino.h>

#include "Ultrasonic.hpp"

namespace ult {
    static double cm = 0;

    mmg::MessageNode node;

    void setup() {
        pinMode(TrigPin, OUTPUT);
        pinMode(EchoPin, INPUT);

        delayMicroseconds(2);
        digitalWrite(TrigPin, LOW);

        node.set_name("ult");
    }

    void loop(mmg::MessageManager &msg_manager) {
//        digitalWrite(7, LOW);
        digitalWrite(TrigPin, LOW);        //Send level pulses to the Trigpin pins in low and high order
        delayMicroseconds(2);             //Delay time
        digitalWrite(TrigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(TrigPin, LOW);
        cm = pulseIn(EchoPin, HIGH) / 58.0;    //Read the pulse width and convert it to centimeters

        Serial.print(cm);

        node.message_info = cm <= ULT_LOW;
        node.data_ptr = &cm;
        msg_manager.push(node);
    }
}


#ifndef IS_MAIN

void setup() {
    ult::setup();
}

void loop() {
    // put your main code here, to run repeatedly:
    ult::loop();
}

#endif
