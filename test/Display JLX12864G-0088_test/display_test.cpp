#include "project_config.h"
#include "U8g2lib.h"

#include "Ultrasonic.hpp"


static const unsigned char frontLeg_bits[] = {
        0x00, 0xf0, 0x0f, 0x00, 0xdc, 0x1f, 0x00, 0xf8, 0x1f, 0x00, 0xf8, 0x1f,
        0x00, 0xf8, 0x1f, 0x00, 0xfc, 0x00, 0x00, 0xf8, 0x07, 0x01, 0x7e, 0x00,
        0x01, 0x7f, 0x00, 0xc3, 0xff, 0x01, 0xef, 0x7f, 0x01, 0xff, 0x7f, 0x00,
        0xfe, 0x7f, 0x00, 0xfc, 0x3f, 0x00, 0xf8, 0x1f, 0x00, 0xf0, 0x0f, 0x00,
        0xe0, 0x18, 0x00, 0xe0, 0x00, 0x00, 0x20, 0x00, 0x00, 0x60, 0x00, 0x00
};

U8G2_UC1701_MINI12864_F_4W_SW_SPI u8g2(U8G2_R0,
                                       13, 12, 11, 9, 10);

void setup() {
    u8g2.begin();
    ult::setup();
}

void loop() {
    // mail loop
    u8g2.clearDisplay();
    ult::loop(<#initializer#>);
    u8g2.print(ult::cm);
    u8g2.sendBuffer();
}