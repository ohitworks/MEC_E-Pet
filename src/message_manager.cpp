//
// Created by oh it words on 5/12/2023.
//
#include "project_config.h"

#include "message_manager.hpp"

#include "string.h"


namespace mmg {

    void setup() {

    }

    void loop() {

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

    void MessageNode::set_name(const char *msg_name) {
        memcpy(this->message_name, msg_name, 3);
        this->message_name[3] = 0;
    }

    /**
     *
     * @param target_name
     * @param node
     * @return
     */
    bool is_message(const char *target_name, MessageNode &node) {
        if (strcmp(target_name, reinterpret_cast<const char *>(&node.message_name)) == 0) {
            return true;
        }
        return false;
    }
}
