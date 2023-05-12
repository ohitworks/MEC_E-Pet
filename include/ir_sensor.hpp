//
// Created by jessica on 5/12/2023.
//

#ifndef MEC_E_PET_IR_SENSOR_H
#define MEC_E_PET_IR_SENSOR_H

#include "message_manager.hpp"

namespace irs {
    void setup();
    void loop(mmg::MessageManager &manager);
}

#endif //MEC_E_PET_IR_SENSOR_H
