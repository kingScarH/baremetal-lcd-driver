#ifndef LCD_CORE_H
#define LCD_CORE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief Initialize the LCD.
 */
void lcd_init(void);

/**
 * @brief Clear the LCD display.
 */
void lcd_clear(void);

/**
 * @brief Set cursor position.
 * @param row Row number (0 or 1)
 * @param col Column number (0 to 15)
 */
void lcd_set_cursor(uint8_t row, uint8_t col);

/**
 * @brief Print a string on the LCD.
 * @param str Null-terminated string
 */
void lcd_print(const char *str);

/**
 * @brief Send a command to the LCD.
 * @param cmd Command byte
 */
void lcd_cmd(uint8_t cmd);

/**
 * @brief Send data to the LCD.
 * @param data Data byte
 */
void lcd_data(uint8_t data);

/**
 * @brief Create a custom character.
 * @param location Memory location (0 to 7)
 * @param charmap  Array of 8 bytes (5x8 font)
 */
void lcd_create_char(uint8_t location, uint8_t charmap[]);

#ifdef __cplusplus
}
#endif

#endif // LCD_CORE_H
