#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

// Abstract pin definitions(lcd module  ka pins) 
#define LCD_RS_PIN_NUM  0
#define LCD_EN_PIN_NUM  1
#define LCD_D4_PIN_NUM  2
#define LCD_D5_PIN_NUM  3
#define LCD_D6_PIN_NUM  4
#define LCD_D7_PIN_NUM  5

// Abstract port operations (Har ek mcu ke liye pin map karna hoga )
#define LCD_RS_WRITE(x)    pin_write(LCD_RS_PIN_NUM, x)
#define LCD_EN_WRITE(x)    pin_write(LCD_EN_PIN_NUM, x)
#define LCD_D4_WRITE(x)    pin_write(LCD_D4_PIN_NUM, x)
#define LCD_D5_WRITE(x)    pin_write(LCD_D5_PIN_NUM, x)
#define LCD_D6_WRITE(x)    pin_write(LCD_D6_PIN_NUM, x)
#define LCD_D7_WRITE(x)    pin_write(LCD_D7_PIN_NUM, x)

#define LCD_DELAY_US(x)    delay_us(x)
#define LCD_DELAY_MS(x)    delay_ms(x)

#endif
