/**
 * @file project_main.c
 * @author Prajwal M
 * @brief Project to ON LED when both the input switches are ON.
 */



#include <avr/io.h>
#include <util/delay.h>

#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"



int main(void)
{
    LED_ON();
    
    InitADC();
    uint16_t temp;
    
   init_PWM();
   
   init_uart(103);
    
    while(1)
{
    if(!(PIND&(1<<PD0)) && !(PIND&(4<<PD0)))
    {
        PORTB|=(1<<PB0);
    _delay_ms(200);
        
        temp=ReadADC(0);
    _delay_ms(200);
        
       compare_adc();
    OCR0A = temp;
    _delay_ms(200);

        
        USARTWriteChar(temp);
    }
        
    else
        {

    PORTB&=~(1<<PB0);
    _delay_ms(200);
        
    }

}

    return 0;
}

