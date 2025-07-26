#include "lcd_config.h"
#include "lcd_lowlevel.h"

static void lcd_pulse_enable() {
    LCD_EN_WRITE(1);
    LCD_DELAY_US(1);
    LCD_EN_WRITE(0);
    LCD_DELAY_US(100);
}

static void lcd_write_4bits(uint8_t data) {
    LCD_D4_WRITE((data >> 0) & 0x01);
    LCD_D5_WRITE((data >> 1) & 0x01);
    LCD_D6_WRITE((data >> 2) & 0x01);
    LCD_D7_WRITE((data >> 3) & 0x01);
    lcd_pulse_enable();
}

void lcd_cmd(uint8_t cmd) {
    LCD_RS_WRITE(0); // Command mode
    lcd_write_4bits(cmd >> 4);
    lcd_write_4bits(cmd & 0x0F);
    LCD_DELAY_MS(2);
}

void lcd_data(uint8_t data) {
    LCD_RS_WRITE(1); // Data mode
    lcd_write_4bits(data >> 4);
    lcd_write_4bits(data & 0x0F);
    LCD_DELAY_MS(2);
}

void lcd_init() {
    DDRB |= 0x3F; // Set PORTB0-5 as output (or use macros if you want per pin DDR)

    LCD_DELAY_MS(40);
    lcd_write_4bits(0x03); LCD_DELAY_MS(5);
    lcd_write_4bits(0x03); LCD_DELAY_US(150);
    lcd_write_4bits(0x03); LCD_DELAY_US(150);
    lcd_write_4bits(0x02); // Set 4-bit mode

    lcd_cmd(0x28); // 4-bit, 2 line, 5x8 font
    lcd_cmd(0x0C); // Display ON
    lcd_cmd(0x06); // Entry mode
    lcd_cmd(0x01); // Clear
    LCD_DELAY_MS(2);
}

void lcd_clear() {
    lcd_cmd(0x01);
    LCD_DELAY_MS(2);
}

void lcd_set_cursor(uint8_t row, uint8_t col) {
    uint8_t addr[] = {0x00, 0x40};
    lcd_cmd(0x80 | (addr[row] + col));
}

void lcd_print(const char *str) {
    while (*str) lcd_data(*str++);
}

void lcd_create_char(uint8_t location, uint8_t charmap[]) {
    location &= 0x7;
    lcd_cmd(0x40 | (location << 3));
    for (uint8_t i = 0; i < 8; i++) {
        lcd_data(charmap[i]);
    }
}
