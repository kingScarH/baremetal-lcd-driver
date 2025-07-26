#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

//--------------------------------------------------
// SELECT MCU HERE (Define only one) Aap jo bhi MCU use karenge sirf us defination line ko un comment karenge 
//--------------------------------------------------
// #define MCU_AVR    
// #define MCU_STM32
// #define MCU_8051
// #define MCU_PIC
// #define MCU_MSP430
#define MCU_TIVA
//--------------------------------------------------

// Pin Numbers (Abstract)
#define LCD_RS_PIN_NUM  0
#define LCD_EN_PIN_NUM  1
#define LCD_D4_PIN_NUM  2
#define LCD_D5_PIN_NUM  3
#define LCD_D6_PIN_NUM  4
#define LCD_D7_PIN_NUM  5

//--------------------------------------------------
// MCU-Specific Macros
//--------------------------------------------------

#if defined(MCU_AVR)
  #include <avr/io.h>
  #include <util/delay.h>
  #define LCD_RS_WRITE(x)    pin_write(LCD_RS_PIN_NUM, x)
  #define LCD_EN_WRITE(x)    pin_write(LCD_EN_PIN_NUM, x)
  #define LCD_D4_WRITE(x)    pin_write(LCD_D4_PIN_NUM, x)
  #define LCD_D5_WRITE(x)    pin_write(LCD_D5_PIN_NUM, x)
  #define LCD_D6_WRITE(x)    pin_write(LCD_D6_PIN_NUM, x)
  #define LCD_D7_WRITE(x)    pin_write(LCD_D7_PIN_NUM, x)
  #define LCD_DELAY_US(x)    _delay_us(x)
  #define LCD_DELAY_MS(x)    _delay_ms(x)

#elif defined(MCU_STM32)
  #include "stm32f4xx.h"
  #define LCD_RS_WRITE(x)    pin_write(LCD_RS_PIN_NUM, x)
  #define LCD_EN_WRITE(x)    pin_write(LCD_EN_PIN_NUM, x)
  #define LCD_D4_WRITE(x)    pin_write(LCD_D4_PIN_NUM, x)
  #define LCD_D5_WRITE(x)    pin_write(LCD_D5_PIN_NUM, x)
  #define LCD_D6_WRITE(x)    pin_write(LCD_D6_PIN_NUM, x)
  #define LCD_D7_WRITE(x)    pin_write(LCD_D7_PIN_NUM, x)
  #define LCD_DELAY_US(x)    delay_us(x)
  #define LCD_DELAY_MS(x)    delay_ms(x)

#elif defined(MCU_8051)
  #include <REG51.H>
  #define LCD_RS_WRITE(x)    pin_write(LCD_RS_PIN_NUM, x)
  #define LCD_EN_WRITE(x)    pin_write(LCD_EN_PIN_NUM, x)
  #define LCD_D4_WRITE(x)    pin_write(LCD_D4_PIN_NUM, x)
  #define LCD_D5_WRITE(x)    pin_write(LCD_D5_PIN_NUM, x)
  #define LCD_D6_WRITE(x)    pin_write(LCD_D6_PIN_NUM, x)
  #define LCD_D7_WRITE(x)    pin_write(LCD_D7_PIN_NUM, x)
  #define LCD_DELAY_US(x)    delay_us(x)
  #define LCD_DELAY_MS(x)    delay_ms(x)

#elif defined(MCU_PIC)
  #include <xc.h>
  #define LCD_RS_WRITE(x)    pin_write(LCD_RS_PIN_NUM, x)
  #define LCD_EN_WRITE(x)    pin_write(LCD_EN_PIN_NUM, x)
  #define LCD_D4_WRITE(x)    pin_write(LCD_D4_PIN_NUM, x)
  #define LCD_D5_WRITE(x)    pin_write(LCD_D5_PIN_NUM, x)
  #define LCD_D6_WRITE(x)    pin_write(LCD_D6_PIN_NUM, x)
  #define LCD_D7_WRITE(x)    pin_write(LCD_D7_PIN_NUM, x)
  #define LCD_DELAY_US(x)    delay_us(x)
  #define LCD_DELAY_MS(x)    delay_ms(x)

#elif defined(MCU_MSP430)
  #include <msp430.h>
  #define LCD_RS_WRITE(x)    pin_write(LCD_RS_PIN_NUM, x)
  #define LCD_EN_WRITE(x)    pin_write(LCD_EN_PIN_NUM, x)
  #define LCD_D4_WRITE(x)    pin_write(LCD_D4_PIN_NUM, x)
  #define LCD_D5_WRITE(x)    pin_write(LCD_D5_PIN_NUM, x)
  #define LCD_D6_WRITE(x)    pin_write(LCD_D6_PIN_NUM, x)
  #define LCD_D7_WRITE(x)    pin_write(LCD_D7_PIN_NUM, x)
  #define LCD_DELAY_US(x)    delay_us(x)
  #define LCD_DELAY_MS(x)    delay_ms(x)

#elif defined(MCU_TIVA)
  #include "tm4c123gh6pm.h"
  #define LCD_RS_WRITE(x)    pin_write(LCD_RS_PIN_NUM, x)
  #define LCD_EN_WRITE(x)    pin_write(LCD_EN_PIN_NUM, x)
  #define LCD_D4_WRITE(x)    pin_write(LCD_D4_PIN_NUM, x)
  #define LCD_D5_WRITE(x)    pin_write(LCD_D5_PIN_NUM, x)
  #define LCD_D6_WRITE(x)    pin_write(LCD_D6_PIN_NUM, x)
  #define LCD_D7_WRITE(x)    pin_write(LCD_D7_PIN_NUM, x)
  #define LCD_DELAY_US(x)    delay_us(x)
  #define LCD_DELAY_MS(x)    delay_ms(x)

#else
  #error "Please define one of: MCU_AVR, MCU_STM32, MCU_8051, MCU_PIC, MCU_MSP430, MCU_TIVA"
#endif

#endif
