#include "U8g2lib.h"

U8G2_UC1701_MINI12864_F_4W_SW_SPI u8g2(U8G2_R0,
                                       13, 12, 11, 9, 10);

void setup() {
    u8g2.begin();
    u8g2.clearBuffer();
    u8g2.drawBox(u8g2.getDisplayWidth() / 4, u8g2.getDisplayHeight() / 4,
                 u8g2.getDisplayWidth() / 2, u8g2.getDisplayHeight() / 2);
    u8g2.sendBuffer();
}

void loop() {
    // 主循环
}