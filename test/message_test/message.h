#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-deprecated-headers"
/**
  **************************** MEC_E-Pet: message.h ****************************
  * @file
  * Created by oh-it-works on 23-5-4.
  * @author     oh-it-works
  * @date       May 04, 2023
  * @brief      WriteHere
  * @note       WriteHere
  **************************** MEC_E-Pet: message.h ****************************
 */

#pragma once

#include <stdint.h>

namespace message {
    class MessageNode {
    public:
        char message_name[4] = {};
        int message_info = 0;
        void *data_ptr = nullptr;
        void clear();
    };

    /**
     * A message management class that provides a queue management mechanism,
     * where the element type of the queue is `ManagerNode`.
     */
    class MessageManager {
    public:
        MessageManager(uint8_t message_list_max_length);

        ~MessageManager();

        int pop(MessageNode &message);

        int push(const MessageNode &message) const;

        bool is_empty() const;

        MessageNode *message_list;
        uint8_t message_list_max_length;

    };

    void setup();

    void loop();
}

#pragma clang diagnostic pop