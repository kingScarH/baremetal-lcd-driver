#include "lcd_lowlevel.h"
#include <avr/io.h>
#include <util/delay.h>

void pin_write(uint8_t pin, uint8_t value) {
    if (value)
        PORTB |= (1 << pin);// yadi agar high ho to set ho jayega anyatha clear 
    else
        PORTB &= ~(1 << pin);
}

void delay_us(uint16_t us) {
    _delay_us(us); //ye avr ka delay hai (blocking delay)
}

void delay_ms(uint16_t ms) {
    _delay_ms(ms);
}
