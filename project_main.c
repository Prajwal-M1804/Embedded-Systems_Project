/**
 * @file project_main.c
 * @author Prajwal M
 * @brief Project to ON LED when both the input switches are ON.
 */


#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    activity1();
    InitADC();
    uint16_t temp;
    void InitPWM();
    char OutPWM ();
    uint16_t temp_data;
    
    while(1)
{
    if(!(PIND&(1<<PD0)) && !(PIND&(4<<PD0)))
    {
        PORTB|=(1<<PB0);
    _delay_ms(200);
        
        temp=ReadADC(0);
    _delay_ms(200);
    }
    else
        {

    PORTB&=~(1<<PB0);
    _delay_ms(200);
    }

}

    return 0;
}

