/**
 *
 */

#include "project_config.h"

#ifdef IS_MAIN

#include "display.hpp"
#include "ir_sensor.hpp"
#include "uv_sensor.hpp"
#include "Ultrasonic.hpp"
#include "message_manager.hpp"
#include "Soil_moisture_sensor.hpp"

#include <Arduino.h>

mmg::MessageManager message_manager(MESSAGE_NODE_NUMBERS);

void setup() {
    Serial.begin(9600);
    Serial.println("Hello world!");


//    mmg::setup();

    dis::setup();

//    ult::setup();
//
//    sms::setup();

//    irs::setup();
//
//    uvs::setup();
}

/**
 * 
 * @param message 
 */
void controller(mmg::MessageNode &message) {
    bool send = true;
    static mmg::MessageNode node;

    if (mmg::is_message("ult", message)) {
        switch (message.message_info) {
            case 0:
                // is low
                node.set_name("ctr");
                node.message_info = CODE_EM_SML;  // Use smail expression to welcome
                message_manager.push(node);
                send = true;
                break;
            case 1:
                // is high
                node.set_name("ctr");
                node.message_info = CODE_CLEAR;
                message_manager.push(node);
                send = false;
                break;
            default:
                send = false;
                break;
        }
    } else if (mmg::is_message("sms", message)) {
        switch (message.message_info) {
            case 1:  // Soil is too wet.
                node.set_name("ctr");
                node.message_info = CODE_EM_DIZZY;
                break;
            case 2:  // Soil is too dry
                node.set_name("ctr");
                node.message_info = CODE_EM_WORRY;
                break;
            case 0:  // Soil good.
                node.set_name("ctr");
                node.message_info = CODE_EM_SML;
                break;
            default:
                send = false;
                break;
        }

    } else if (mmg::is_message("irs", message)) {
        switch (message.message_info) {
            case 0:  // LOW
            case 1:  // HIGH
            default:
                send = false;
                break;
        }

    } else if (mmg::is_message("uvs", message)) {
        switch (message.message_info) {
            case 0:  // LOW: not a sunny day
                node.set_name("ctr");
                node.message_info = CODE_EM_SML;
                break;
            case 1:  // HIGH
                node.set_name("ctr");
                node.message_info = CODE_EM_LAUGH;
                break;
            default:
                send = false;
                break;
        }
    } else {
        send = false;
    }
    if (send) {
        message_manager.push(node);
    }
}

void loop() {
    // mail loop
    Serial.println("Hello world!");

    static mmg::MessageNode message;

//    mmg::loop();
//    ult::loop(message_manager);
//    sms::loop(message_manager);
//    irs::loop(message_manager);
//    uvs::loop(message_manager);
    static mmg::MessageNode node;

//    node.set_name("ctr");
//    node.message_info = CODE_EM_SML;  // Use smail expression to welcome
//    message_manager.push(node);
//    node.set_name("ctr");
//    node.message_info = CODE_EM_WORRY;  // Use smail expression to welcome
//    message_manager.push(node);
//    node.set_name("ctr");
//    node.message_info = CODE_EM_CRY;  // Use smail expression to welcome
//    message_manager.push(node);
//    node.set_name("ctr");
//    node.message_info = CODE_EM_DIZZY;  // Use smail expression to welcome
//    message_manager.push(node);
//    node.set_name("ctr");
//    node.message_info = CODE_EM_LAUGH;  // Use smail expression to welcome
//    message_manager.push(node);

//    while (message_manager.pop(message) == 0) {
//        controller(message);
//    }

    dis::loop(message_manager);

//    delay(1000);
}

#endif
