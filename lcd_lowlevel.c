#include "lcd_config.h"

void pin_write(uint8_t pin, uint8_t value) {
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
        LATB |= (1 << pin);  // LATx for PIC18 series
    else
        LATB &= ~(1 << pin);

#elif defined(MCU_MSP430)
    if (value)
        P1OUT |= (1 << pin);
    else
        P1OUT &= ~(1 << pin);

#elif defined(MCU_TIVA)
    if (value)
        GPIO_PORTA_DATA_R |= (1 << pin);  // Example: PORTA
    else
        GPIO_PORTA_DATA_R &= ~(1 << pin);

#endif
}

void delay_us(uint16_t us) {
#if defined(MCU_AVR)
    _delay_us(us);

#elif defined(MCU_STM32)
    for (uint32_t i = 0; i < us * 16; i++) __NOP();

#elif defined(MCU_8051)
    while (us--) {
        _nop_(); _nop_(); _nop_(); _nop_(); // adjust if needed
    }

#elif defined(MCU_PIC)
    __delay_us(us); // XC8 Compiler

#elif defined(MCU_MSP430)
    while (us--) {
        __delay_cycles(1); // adjust as per clock speed
    }

#elif defined(MCU_TIVA)
    for (uint32_t i = 0; i < us * 10; i++) __asm(" NOP");

#endif
}

void delay_ms(uint16_t ms) {
    while (ms--) delay_us(1000);
}
