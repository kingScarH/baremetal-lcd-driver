/*
 * @FILE     : lcd_lowlevel.c
 * @AUTHOR   : Sandeep Ray aka kingScarH
 *
 *
 * @BRIEF    : Low-level 4-bit LCD driver for HD44780-compatible character displays.
 *             Designed for embedded systems (e.g., STM32, AVR) using GPIO control.
 *             Handles direct control of RS/EN/D4-D7 lines with timing.
 *
 * NOTE: This implementation assumes LCD pin macros are defined in lcd_config.h.
 *       Timing delays and GPIO macros should be ported as per the platform.
 */

#include "lcd_config.h"
#include "lcd_lowlevel.h"

/* Internal pulse to latch data into LCD */
static void lcd_pulse_enable() {
    LCD_EN_WRITE(1);
    LCD_DELAY_US(1);
    LCD_EN_WRITE(0);
    LCD_DELAY_US(100);  // Allow command to settle
}

/* Send 4 bits to LCD data pins */
static void lcd_write_4bits(uint8_t data) {
    LCD_D4_WRITE((data >> 0) & 0x01);
    LCD_D5_WRITE((data >> 1) & 0x01);
    LCD_D6_WRITE((data >> 2) & 0x01);
    LCD_D7_WRITE((data >> 3) & 0x01);
    lcd_pulse_enable();
}

/* Send command to LCD (RS=0) */
void lcd_cmd(uint8_t cmd) {
    LCD_RS_WRITE(0);                // Command mode
    lcd_write_4bits(cmd >> 4);     // High nibble
    lcd_write_4bits(cmd & 0x0F);   // Low nibble
    LCD_DELAY_MS(2);
}

/* Send data to LCD (RS=1) */
void lcd_data(uint8_t data) {
    LCD_RS_WRITE(1);                // Data mode
    lcd_write_4bits(data >> 4);    // High nibble
    lcd_write_4bits(data & 0x0F);  // Low nibble
    LCD_DELAY_MS(2);
}

/* LCD Initialization Sequence (HD44780 in 4-bit mode) */
void lcd_init() {
    // Optional: Configure DDR manually (or use pinMode macros)
    DDRB |= 0x3F;  // PB0–PB5 as output (adjust as per MCU)

    LCD_DELAY_MS(40);     // LCD power-up delay
    lcd_write_4bits(0x03); LCD_DELAY_MS(5);
    lcd_write_4bits(0x03); LCD_DELAY_US(150);
    lcd_write_4bits(0x03); LCD_DELAY_US(150);
    lcd_write_4bits(0x02); // Enter 4-bit mode

    lcd_cmd(0x28);  // 4-bit mode, 2 lines, 5x8 font
    lcd_cmd(0x0C);  // Display ON, Cursor OFF
    lcd_cmd(0x06);  // Entry mode: auto-increment
    lcd_cmd(0x01);  // Clear display
    LCD_DELAY_MS(2);
}

/* Clear LCD display */
void lcd_clear() {
    lcd_cmd(0x01);
    LCD_DELAY_MS(2);
}

/* Set cursor to row,col */
void lcd_set_cursor(uint8_t row, uint8_t col) {
    uint8_t addr[] = {0x00, 0x40};  // DDRAM mapping
    lcd_cmd(0x80 | (addr[row] + col));
}

/* Print string on LCD */
void lcd_print(const char *str) {
    while (*str) {
        lcd_data(*str++);
    }
}

/* Create custom character in CGRAM */
void lcd_create_char(uint8_t location, uint8_t charmap[]) {
    location &= 0x7;  // Only 8 custom chars (0-7)
    lcd_cmd(0x40 | (location << 3));
    for (uint8_t i = 0; i < 8; i++) {
        lcd_data(charmap[i]);
    }
}
