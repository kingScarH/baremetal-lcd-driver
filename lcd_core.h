#ifndef LCD_CORE_H
#define LCD_CORE_H

#include <stdint.h>

void lcd_init(void);
void lcd_clear(void);
void lcd_set_cursor(uint8_t row, uint8_t col);
void lcd_print(const char *str);
void lcd_cmd(uint8_t cmd);
void lcd_data(uint8_t data);
void lcd_create_char(uint8_t location, uint8_t charmap[]);

#endif
