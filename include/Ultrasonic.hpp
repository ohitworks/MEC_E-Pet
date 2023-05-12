//
// Created by oh it works on 5/12/2023.
//
#pragma once

#ifndef MEC_E_PET_ULTRASONIC_HPP
#define MEC_E_PET_ULTRASONIC_HPP

#include "message_manager.hpp"

namespace ult {
    void setup();
    void loop(mmg::MessageManager &msg_manager);
}

#endif //MEC_E_PET_ULTRASONIC_HPP
