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
  DDRA=0x00; PORTA=0xFF;
  DDRB=0xFF; PORTB=0x00;
  unsigned char tempA = 0x00;
  unsigned char tempB = 0x00;
  while (1)
   {
	tempA=PINA & 0x01;
	tempB=PINA & 0x02;
	if (tempB==0x00 && tempA==0x01) 
        {
		PORTB = 0x01;
	}
	else
        {
		PORTB=0x00;
	}
    }
    return 1;
}
