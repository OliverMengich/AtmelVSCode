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
	 int pin0_status;
	
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
		int res[4];
		// FIRST LED 
		int counter = 0;
		  pin0_status = ~PINB & (1<<PB0); /*Read status of pin PB2 */
		   res[counter] = (pin0_status)? (PORTC |(1<<PC0) ):(PORTC & (~(1<<PC0))); 
		   PORTC = res[counter];  
		  
		   // SECOND LED
		 pin1_status = ~PINB & (1<<PB1);
		 counter =counter+1;
		  res [counter] = (pin1_status)? (PORTC |(1<<PC1) ):(PORTC & (~(1<<PC1))) ;  
		 PORTC = res [counter];
		
		  
		  // THIRD LED
		 pin2_status = ~PINB & (1<<PB2);
		 counter = counter+1;
		  res[counter] = (pin2_status)? (PORTC |(1<<PC2) ):(PORTC & (~(1<<PC2))) ;  
		 PORTC = res[counter];
		
		 
		 // FOURTH LED 
		 pin3_status = ~ PINB & (1<<PB3);
		 counter =counter + 1;
		 res[counter] = (pin3_status)? (PORTC | (1<<PC3) ):(PORTC & (~(1<<PC3)));  
		  PORTC = res[counter]; 
	
	      DDRD = 0xFF;
	       int passwordcorrect [4] = {res[0], res[1], res[2],res[3]};
		 if(counter == 4)
		 {
			  for(int i = 0; i<4;i++)
			  {
				   if(res[i] == passwordcorrect[4])
				   {
					   PORTD = PORTD | (1<<PD0);
					   _delay_ms(500);
					   PORTD = PORTD & (~(1<<PD0));
					   _delay_ms(500);
				   }
				   else
				   {
					   PORTD = PORTD | (1<<PD1);
					   _delay_ms(500);
					   PORTD = PORTD & (~(1<<PD1));
					   _delay_ms(500);
				   }
			   }
		 }
		
    }
	return 0;
}

