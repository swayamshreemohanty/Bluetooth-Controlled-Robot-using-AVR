
#include<avr/io.h>
/*Includes io.h header file where all the Input/Output Registers and its Bits are defined for AVR microcontroller*/

#define	F_CPU	8000000
/*Defines a macro for the delay.h header file. F_CPU is the microcontroller frequency value for the delay.h header file. Default value of F_CPU in delay.h header file is 1000000(1MHz)*/

#include<util/delay.h>
/*Includes delay.h header file which defines two functions, _delay_ms (millisecond delay) and _delay_us (microsecond delay)*/

#include<avr/usart.h>
/*Includes usart.h header file which includes all the usart functions*/



void main(void)
{
	DDRC=0x0f;
	/*PC0,PC1,PC2,PC3 pins of PortC are declared output ( i/p1,i/p2,i/p3,i/p4 pins of DC Motor Driver are connected )*/
	
	unsigned char usart_received_data;
	/*Variable declaration*/

	usart_init();
	/*USART initialization*/

	

	/*Start of infinite loop*/
	while(1)
	{
		usart_received_data=usart_data_receive();
		/*Data receive from PC */
		
		if(usart_received_data == 'A' || usart_received_data == 'a')
		{
			PORTC=0b00001010;
			/*Robot will move forward*/

		}
		else if(usart_received_data == 'B' || usart_received_data == 'b')
		{
			PORTC=0b00000101;
			/*Robot will move backward*/

			
		}
		else if(usart_received_data == 'C' || usart_received_data == 'c')
		{
			PORTC=0b00000010;
			/*Robot will move towards left*/

			
		}
		else if(usart_received_data == 'D' || usart_received_data == 'd')
		{
			PORTC=0b00001000;
			/*Robot will move towards right*/

			
		}
		else if(usart_received_data == 'E' || usart_received_data == 'e')
		{
			PORTC=0b000000000;
			/*Robot will stop*/
         }
     }
 }
         

