//
// Created by oh it works on 5/12/2023.
//
#include "project_config.h"
#include "ir_sensor.hpp"

#include <Arduino.h>

namespace irs {

    int irSensor = 8;     // define IR sensor serial port (8) 定义串口8
    bool irSensorOutput;  // Output signal value of the infrared sensor 红外传感器输出信号数值

    mmg::MessageNode node;


    void setup() {
        // Initializing serial port communication
        // The OUT pin connected to the human infrared induction module is set to the input mode
        // 连接人体红外感应模块的OUT引脚设置为输入模式
        pinMode(irSensor, INPUT);
        node.set_name("irs");
    }

    void loop(mmg::MessageManager &manager) {
        // Read and store infrared sensing signal output level values.
        // 读取并存储红外传感信号输出电平数值
        irSensorOutput = digitalRead(irSensor);
        if (irSensorOutput == HIGH) {
            Serial.println("IR : High.");
            node.message_info = 1;
        } else {
            Serial.println("IR : Low.");
            node.message_info = 0;
        }
        manager.push(node);
//        delay(1000);  // The cycle interval is set to 0.1s 间隔设置为0.1秒
    }
}

#ifndef IS_MAIN
void setup() {
    irs::setup();
}

void loop() {
    irs::loop();
}
#endif
