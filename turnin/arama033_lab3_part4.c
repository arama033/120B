#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
   
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char tempA = 0x00;
    unsigned char swp1 = 0x00;
    unsigned char swp2 = 0x00;

    while (1) {
	tempA = PINA;
	swp1 = (tempA >> 4) & 0x0F;
	swp2 = (tempA << 4) & 0xF0;
	PORTB = swp1;
	PORTC = swp2;
	
    }
    return 1;
}
