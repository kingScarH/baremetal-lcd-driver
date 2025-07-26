#include "lcd_config.h"
#include "lcd_core.h"

static void lcd_pulse_enable() {
    LCD_EN_PORT |= (1 << LCD_EN_PIN);
    _delay_us(1);
    LCD_EN_PORT &= ~(1 << LCD_EN_PIN);
    _delay_us(100);
}

static void lcd_write_4bits(uint8_t data) {
    if (data & 0x01) LCD_D4_PORT |= (1 << LCD_D4_PIN); else LCD_D4_PORT &= ~(1 << LCD_D4_PIN);
    if (data & 0x02) LCD_D5_PORT |= (1 << LCD_D5_PIN); else LCD_D5_PORT &= ~(1 << LCD_D5_PIN);
    if (data & 0x04) LCD_D6_PORT |= (1 << LCD_D6_PIN); else LCD_D6_PORT &= ~(1 << LCD_D6_PIN);
    if (data & 0x08) LCD_D7_PORT |= (1 << LCD_D7_PIN); else LCD_D7_PORT &= ~(1 << LCD_D7_PIN);
    lcd_pulse_enable();
}

void lcd_cmd(uint8_t cmd) {
    LCD_RS_PORT &= ~(1 << LCD_RS_PIN); // RS = 0
    lcd_write_4bits(cmd >> 4);
    lcd_write_4bits(cmd & 0x0F);
    _delay_ms(2);
}

void lcd_data(uint8_t data) {
    LCD_RS_PORT |= (1 << LCD_RS_PIN); // RS = 1
    lcd_write_4bits(data >> 4);
    lcd_write_4bits(data & 0x0F);
    _delay_ms(2);
}

void lcd_init() {
    LCD_RS_DDR |= (1 << LCD_RS_PIN);
    LCD_EN_DDR |= (1 << LCD_EN_PIN);
    LCD_D4_DDR |= (1 << LCD_D4_PIN);
    LCD_D5_DDR |= (1 << LCD_D5_PIN);
    LCD_D6_DDR |= (1 << LCD_D6_PIN);
    LCD_D7_DDR |= (1 << LCD_D7_PIN);

    _delay_ms(40);

    lcd_write_4bits(0x03); _delay_ms(5);
    lcd_write_4bits(0x03); _delay_us(150);
    lcd_write_4bits(0x03); _delay_us(150);
    lcd_write_4bits(0x02); // Set 4-bit mode

    lcd_cmd(0x28); // 4-bit, 2 line, 5x8 font
    lcd_cmd(0x0C); // Display ON
    lcd_cmd(0x06); // Entry mode
    lcd_cmd(0x01); // Clear
    _delay_ms(2);
}

void lcd_clear() {
    lcd_cmd(0x01);
    _delay_ms(2);
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
