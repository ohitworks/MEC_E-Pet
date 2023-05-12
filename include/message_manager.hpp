//
// Created by oh it works on 5/12/2023.
//

#ifndef MEC_E_PET_MESSAGE_MANAGER_H
#define MEC_E_PET_MESSAGE_MANAGER_H

#ifndef uint8_t
typedef unsigned char uint8_t;
#endif


namespace mmg {

    void setup();

    void loop();

    class MessageNode {
    public:
        char message_name[4] = {0};
        int message_info = 0;
        void *data_ptr = nullptr;

        void clear();
        void set_name(const char * msg_name);
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

    /**
     *
     * @return
     */
    bool is_message(const char *, MessageNode &);

//    mmg::MessageManager message_manager;

}

#endif //MEC_E_PET_MESSAGE_MANAGER_H
