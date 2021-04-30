/**
 * @file project_main.c
 * @author Prajwal M
 * @brief Project to ON LED when both the input switches are ON.
 */


#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    activity1();
    InitADC();
    uint16_t temp;
    void InitPWM();
    char OutPWM ();
    char temp_data;
    init_uart(103);
    
    while(1)
{
    if(!(PIND&(1<<PD0)) && !(PIND&(4<<PD0)))
    {
        PORTB|=(1<<PB0);
    _delay_ms(200);
        
        temp=ReadADC(0);
    _delay_ms(200);
        
        temp_data = OutPWM(temp);
        
        USARTWriteChar(temp);
    }
        
    else
        {

    PORTB&=~(1<<PB0);
    _delay_ms(200);
        OCR1A=0;
    }

}

    return 0;
}

