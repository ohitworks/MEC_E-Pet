#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-deprecated-headers"
/**
  **************************** MEC_E-Pet: message.cpp ****************************
  * @file
  * Created by oh-it-works on 23-5-4.
  * @author     oh-it-works
  * @date       May 04, 2023
  * @brief      WriteHere
  * @note       WriteHere
  **************************** MEC_E-Pet: message.cpp ****************************
 */

#include "message.h"
#include <Arduino.h>
#include <string.h>
#include <stdlib.h>

namespace message {
    MessageManager mm(3);

    void setup() {
        // write your initialization code here
        Serial.begin(9600);

        auto mn = MessageNode();
        strcpy(mn.message_name, "001");
        mn.message_info = 1;
        mm.push(mn);
    }

    void loop() {
        // write your code here
        static auto mn = MessageNode();
        static int times = 0;

        if (mm.is_empty()) {
            Serial.print("Empty queue\n");

            if (times % 2) {
                Serial.print("Pull queue...\n");
                memset(mn.message_name, 0, 3);
                itoa(times, mn.message_name, 10);
                mn.message_info = 2;
                mm.push(mn);
            }
        } else if (mm.pop(mn) == 0) {
            Serial.print("Popped ");
            Serial.print(mn.message_name);
            Serial.print("  info:");
            Serial.print(mn.message_info);
            Serial.print("  with ptr:");
            Serial.print((int) mn.data_ptr, 16);
            Serial.print("\n");
            mn.clear();
        } else {
            Serial.print("WARNING: pop error!!!\n");
        }

        times = (times + 1) % 1000;
        Serial.print(times);
        Serial.print("\n");

        delay(700);
    }

    MessageManager::MessageManager(uint8_t message_list_max_length) {
        this->message_list_max_length = message_list_max_length;
        this->message_list = new MessageNode[message_list_max_length];
    }

    MessageManager::~MessageManager() {
        delete[] this->message_list;
    }

    /**
     * set the last message in queue to param `message`, then delete it.
     * @param message the variable to be update.
     * @return 0 if success, -1 if the queue is empty
     */
    int MessageManager::pop(MessageNode &message) {
        int index;
        for (index = 0; index < this->message_list_max_length; index++) {
            if (memcmp("\0\0\0\0", &this->message_list[index], sizeof(uint8_t) * 4) == 0) {
                break;
            }
        }
        if (index == 0) {
            // queue is empty
            return -1;
        }
        message = this->message_list[--index];
        this->message_list[index].clear();
        return 0;
    }

    /**
     * Return true if the queue is empty else false.
     */
    bool MessageManager::is_empty() const {
        for (int index = 0; index < this->message_list_max_length; index++) {
            if (memcmp("\0\0\0\0", &this->message_list[index], sizeof(uint8_t) * 4) != 0) {
                return false;
            }
        }
        return true;
    }

    /**
     * Push `message` into the queue.
     * @param message
     * @return -1 if the queue is empty.
     */
    int MessageManager::push(const MessageNode &message) const {
        int index;
        for (index = 0; index < this->message_list_max_length; index++) {
            if (memcmp("\0\0\0\0", &this->message_list[index], sizeof(uint8_t) * 4) == 0) {
                break;
            }
        }
        if (index == this->message_list_max_length) {
            // queue is full
            return -1;
        }

        memcpy(&this->message_list[index], &message, sizeof(MessageNode));
        return 0;
    }

    void MessageNode::clear() {
        memset(this->message_name, 0, 4);
        this->message_info = 0;
        this->data_ptr = nullptr;
    }
}

#pragma clang diagnostic pop