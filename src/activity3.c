
#include<avr/io.h>
#include"activity3.h"

void init_PWM()              // Initialize PWM
{
    TCCR0A |= (1<<COM0A1)|(1<<WGM01)|(1<<WGM00);
    TCCR0B |= (1<<CS00);
    DDRD |= (1<<PD6);
}

void compare_adc()              // Compares sensor output and gives required  PWM
{
     if (ADC>0 && ADC<209){
        OCR0A = 51;
    }
    else if(ADC > 210 && ADC < 509){
        OCR0A = 101;
    }
    else if(ADC > 510 && ADC < 709){
        OCR0A = 178;
    }
    else if (ADC > 710 && ADC < 1024){
        OCR0A = 242;
    }
}
