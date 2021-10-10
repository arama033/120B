#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
   
    DDRB = 0x01; PORTB = 0x00;
    DDRD = 0x00; PORTD = 0xFF;

    unsigned char tmpB = 0x00;
    unsigned char tmpD = 0x00;
    unsigned char result = 0x00;
    unsigned short netwght = 0x0000;

    while (1) {
	tmpD = PIND;
	tmpB = PINB;
	netwght = (tmpD << 1) | (tmpB & 0x01);

if (netwght <= 0x0005)
  {
		result = 0x00;
	}
  else if (netwght > 0x0005) 
  {
		result = 0x04;
	}
	else if (netwght >= 0x0046) 
  {
		result = 0x02;
	}
	PORTB = result;
	
    }
    return 1;
}
