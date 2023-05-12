//
// Created by jessica on 5/12/2023.
//

#ifndef MEC_E_PET_SOIL_MOISTURE_SENSOR_H
#define MEC_E_PET_SOIL_MOISTURE_SENSOR_H

#include "message_manager.hpp"

namespace sms {
    void setup();

    void loop(mmg::MessageManager &manager);

    int readSensor();
}
#endif //MEC_E_PET_SOIL_MOISTURE_SENSOR_H
