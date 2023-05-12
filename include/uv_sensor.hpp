//
// Created by jessica on 5/12/2023.
//

#ifndef MEC_E_PET_UV_SENSOR_H
#define MEC_E_PET_UV_SENSOR_H

namespace uvs {
    void setup();
    void loop();
    int averageAnalogRead(int pinToRead);
    float map_float(float x, float in_min, float in_max, float out_min, float out_max);
}

#endif //MEC_E_PET_UV_SENSOR_H
