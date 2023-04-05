#ifndef motor_H_
#define motor_H_

#define F_CPU 8000000UL
#include <avr/io.h>

void PWM_init(void){
    TCNT0 = 0; /* Set timer0 count zero */
    // Set fast PWM mode with non inverted output clock prescaler 64
    TCCR0 = (1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00)|(1<<CS01);
    // enabler pin connected to pin 4 of port D
    DDRD |= (1<<PD4);
}


#endif /* motor_H_ */