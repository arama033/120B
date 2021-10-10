/*	Author: arama033
 *  Partner(s) Name: Abhinav
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) 
{
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0x00; PORTC = 0xFF;
    DDRD = 0xFF; PORTD = 0x00;
    unsigned short netWeight = 0x0000;
    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;
    unsigned char tmpC = 0x00;
    unsigned char tmpE = 0x00;
    while (1) {
    tmpA = PINA;
  	tmpB = PINB;
  	tmpC = PINC;
  	netWeight = tmpA + tmpB + tmpC;
    tmpE = netWeight >> 2;
    tmpE = tmpE << 2;

    if (netWeight > 0x8C) 
    {
		tmpE = tmpE | 0x01;
	  }
	else 
  {
		tmpE = tmpE | 0x00;
	}

 if (((tmpA - tmpC) > 0x50)||((tmpC - tmpA) > 0x50)) 
    {
			tmpE = tmpE | 0x02;
  	}
    PORTD = tmpE;
    }
	return 0;
}




  


   


