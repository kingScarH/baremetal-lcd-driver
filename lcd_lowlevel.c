/**
 * @file    lcd_port.c
 * @author  Sandeep Ray
 * @brief   Hardware Abstraction Layer for LCD GPIO & Delays
 *
 *          This file provides cross-platform GPIO write and microsecond/millisecond
 *          delay implementations for multiple embedded platforms like AVR, STM32,
 *          8051, PIC, MSP430, and TIVA C series.
 *
 *          Designed for educational and production-quality LCD interfacing code.
 */

#include "lcd_config.h"  // MCU-specific defines

/**
 * @brief Write a digital value to a specific GPIO pin.
 *
 * @param pin   GPIO pin number (0-7)
 * @param value Logical value to write (0 or 1)
 */
void pin_write(uint8_t pin, uint8_t value)
{
#if defined(MCU_AVR)
    if (value)
        PORTB |= (1 << pin);
    else
        PORTB &= ~(1 << pin);

#elif defined(MCU_STM32)
    if (value)
        GPIOA->ODR |= (1 << pin);
    else
        GPIOA->ODR &= ~(1 << pin);

#elif defined(MCU_8051)
    if (value)
        P1 |= (1 << pin);
    else
        P1 &= ~(1 << pin);

#elif defined(MCU_PIC)
    if (value)
        LATB |= (1 << pin);  // For PIC18 series
    else
        LATB &= ~(1 << pin);

#elif defined(MCU_MSP430)
    if (value)
        P1OUT |= (1 << pin);
    else
        P1OUT &= ~(1 << pin);

#elif defined(MCU_TIVA)
    if (value)
        GPIO_PORTA_DATA_R |= (1 << pin);  // Example: Port A
    else
        GPIO_PORTA_DATA_R &= ~(1 << pin);

#else
    #error "MCU not defined or unsupported for pin_write()"
#endif
}

/**
 * @brief Microsecond delay routine.
 *
 * @param us Duration in microseconds
 */
void delay_us(uint16_t us)
{
#if defined(MCU_AVR)
    _delay_us(us);

#elif defined(MCU_STM32)
    for (uint32_t i = 0; i < us * 16; i++) __NOP();  // Adjust for 16 MHz

#elif defined(MCU_8051)
    while (us--) {
        _nop_(); _nop_(); _nop_(); _nop_();  // Approx 1 us (tuned)
    }

#elif defined(MCU_PIC)
    __delay_us(us);  // Using XC8 Compiler macro

#elif defined(MCU_MSP430)
    while (us--) {
        __delay_cycles(1);  // Tune as per clock
    }

#elif defined(MCU_TIVA)
    for (uint32_t i =_
