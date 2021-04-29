/**
 * @file project_main.c
 * @author Prajwal M
 * @brief Project to ON LED when both the input switches are ON.
 */


#include "activity1.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    activity1();
    while(1)
{
    if(!(PIND&(1<<PD0)) && !(PIND&(4<<PD0)))
    {
        PORTB|=(1<<PB0);
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

