/**
 * @file project_main.c
 * @author Prajwal M
 * @brief Project to Seat Heating Application.
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
    
    InitADC();          // Initialize ADC ports
    uint16_t temp;       
    
   init_PWM();          // Start PWM generation
   
  USARTInit(103);      // Initialize ports for UART
    
    while(1)
{
    if(!(PIND&(1<<PD0)) && !(PIND&(4<<PD0)))  // Check whether both the swithes were closed
    {
        PORTB|=(1<<PB0);   // Led ON
    _delay_ms(200);
        
        temp=ReadADC(0);    // Read adc values from sensors
    _delay_ms(200);
        
       compare_adc();       // compare sensor output and give required PWM
    OCR0A = temp;
    _delay_ms(200);

        
        USARTWriteChar(temp);      // Read the sensor value and give output in degree celsius
    }
        
    else
        {

    PORTB&=~(1<<PB0);              // Led Off
    _delay_ms(200);
        
    }

}

    return 0;
}

