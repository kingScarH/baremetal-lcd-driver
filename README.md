#  KingScarH Universal LCD Driver

A portable bare-metal LCD driver (HD44780) for 4-bit mode.  
Supports **AVR**, **STM32**, **8051**, **PIC**, and more.

## Features
- Full 4-bit support
- Custom characters
- Clear, cursor control
- Portable via `lcd_config.h` layer

## Porting Steps
1. Copy config from `/boards/<your_mcu>/lcd_config.h`
2. Implement `lcd_lowlevel.c` for your board
3. Use `lcd_init()`, `lcd_print()`, etc.

---


