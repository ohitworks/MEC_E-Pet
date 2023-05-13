#include "U8g2lib.h"

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

    u8g2.clearBuffer();
    u8g2.drawBox(u8g2.getDisplayWidth() / 4, u8g2.getDisplayHeight() / 4,
                 u8g2.getDisplayWidth() / 2, u8g2.getDisplayHeight() / 2);
    u8g2.sendBuffer();
    delay(1000);
}

void loop() {
    // mail loop
    u8g2.firstPage();
    for (int x = 0; x < 124; x += 6) {
        // keep screen clear 0.5s
//        u8g2.clearDisplay();
//        u8g2.sendBuffer();
//        delay(500);

        // draw the picture
        u8g2.clearBuffer();
        u8g2.drawXBM(x, 10, 21, 20, frontLeg_bits);
        u8g2.sendBuffer();
        delay(700);
        u8g2.nextPage();
    }
}