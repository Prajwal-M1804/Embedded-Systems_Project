#include <avr/io.h>
#include <util/delay.h>

void activity1()
{
    DDRB|=(1<<PB0);
    DDRD&=~(1<<PD0);
    DDRD&=~(4<<PD0);
    PORTD|=(1<<PD0);
    PORTD|=(4<<PD0);

}
