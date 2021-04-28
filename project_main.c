/**
 * @file project_main.c
 * @author Prajwal M
 * @brief Project to ON LED when both the input switches are ON.
 */


#include "Activity1.h"

int main(void)
{
    DDRB|=(1<<PB0);
    DDRD&=~(1<<PD0);
    DDRD&=~(4<<PD0);
    PORTD|=(1<<PD0);
    PORTD|=(4<<PD0);

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
