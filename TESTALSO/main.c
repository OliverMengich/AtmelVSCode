 /*
 * TESTALSO.c
 *
 * Created: 03/11/2019 03:24:32
 * Author : olive
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include "avr/iom32.h"
#include <util/delay.h>


int main(void)
{
	// FOR THE FIRST LED
	 DDRC = DDRC | (1<<PC0); /* Make PB3 as output pin */
	 DDRB = DDRB & (~(1<<PB0)); /* Make PB2 as input pin */
	 PORTB = PORTB | (1<<PB0); /* Enable pull-up on PB2 by writing 1 to it */
	 int pin_status;
	
     DDRD = 0xFF;
	 
	
	 // FOR THE SECOND LED
	  int number = DDRC | (1<<PC1);
	  DDRC = number;
	  int number1 = DDRB & (~(1<<PB1));
	  DDRB= number1;
	  int number2 = PORTB | (1<<PB1);
	  PORTB = number2;
	   int pin1_status;
	   
	   // FOR THE THIRD LED
	   int number3 = DDRC | (1<< PC2);
	   DDRC = number3;
	   int number4 = DDRB & (~(1<<PB2));
	   DDRB = number4;
	   int number5 = PORTB | (1<<PB2);
	   PORTB = number5;
	   int pin2_status;
	   
	   // FOR THE FOURTH LED
	   int number6 = DDRC | (1<<PC3);
	   DDRC = number6;
	   int number7 = DDRB | (1<<PB3);
	   DDRB = number7;
	   int number8 = PORTB | (1<<PB3);
	   PORTB = number8;
	   int pin3_status;
	   
    /* Replace with your application code */
    while (1) 
    {
		int firstpin;
		int secondpin;
		int thirdpin;
		int fourthpin;
		// FIRST LED 
		  pin_status = ~PINB & (1<<PB0); /*Read status of pin PB2 */
		  if(pin_status) /* Transmit status of pin PB2 on to pin PB3 to drive LED.*/
		  {
			   firstpin =PORTC | (1<<PC0);
			  PORTC = firstpin; 
			//  PORTC = PORTC | (1<<PC0); /*Switch is open, pin_status = 1, LED is ON */
		  }
		  else
		  {
			  firstpin = PORTC & (~(1<<PC0));
			  PORTC = firstpin; /*Switch is closed, pin_status = 0, LED is OFF */
		  }
		  
		   // SECOND LED
		 pin1_status = ~PINB & (1<<PB1);
		 if(pin1_status)
		  {
			  
			 secondpin = PORTC | (1<<PC1);
			 PORTC = secondpin;
		  }
		  else
		  {
			  secondpin = PORTC & (~(1<<PC1));
			  PORTC = secondpin;
		  }
		  
		  // THIRD LED
		 pin2_status = ~PINB & (1<<PB2);
		 if(pin2_status)
		 {
			 //PORTC = PORTC  | (1<<PC2);|
			 
			 thirdpin = PORTC |(1<<PC2);
			 PORTC = thirdpin;
		 }
		 else
		 {
			 thirdpin = PORTC & (~(1<<PC2));
			 PORTC = thirdpin;
		 }
		 
		 // FOURTH LED 
		 pin3_status = ~ PINB & (1<<PB3);
		 if(pin3_status)
		 {
			 fourthpin = PORTC | (1<<PC3);
			 PORTC = fourthpin;
		 }
		 else
		 {
			 
			 fourthpin = PORTC & (~(1<<PC3));
			 PORTC = fourthpin;
		 }
		 
		 
		 int pinD_status;
		 
		 pinD_status = PIND;
		  
		//  if(fourthpin + thirdpin + secondpin + firstpin)
		  //{
			// PORTD = PORTD | (1<<PD0);
			// _delay_ms(500);
			//_delay_ms(500);
			 //PORTD = PORTD & (~(1<<PD0));
			 //_delay_ms(500);  
			// break;
		//  }
		  if(pinD_status = 11000000)
		  {
			    _delay_ms(500);
			    //_delay_ms(500);
			    PORTD = PORTD & (~(1<<PD0));
			    _delay_ms(500);
			    // break;
			  
		  }
		//  if(!(fourthpin + thirdpin + secondpin + firstpin))
		  //{
			//  PORTD = PORTD | (1<<PD1);
			  //_delay_ms(500);
			//  PORTD = PORTD & (~(1<<PD1));
			//  _delay_ms(500);
			//  break;
		  //}
    }
	return 0;
}

