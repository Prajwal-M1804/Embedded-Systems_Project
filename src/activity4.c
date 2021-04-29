#include<avr/io.h>
#include"activity4.h"

void USARTInit(uint16_t ubrr_value)
{
    // set Baud rate

    UBRR0L = ubrr_value;
    UBRR0H = (ubrr_value>>8)&(0x00ff);
    UCSR0C = (1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);

    // Enable the receiver and transmitter

    UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);

}


void USARTwrite(char data)
{
    // wait until the transmitter is ready
    while(!(UCSR0A & (1<<UDRE0)))
    {
        //do nothing
    }

    UDR0 = data;
}
