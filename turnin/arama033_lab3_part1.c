#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char tempA = 0x00;
    unsigned char tempB = 0x00;
    unsigned char counter = 0x00;

    while (1) {
	tempA = PINA;
	tempB = PINB;
	counter = 0x00;
	if ((tempA & 0x01) == 0x01) 
        {
	counter = counter + 1;
	}
	if ((tempA & 0x02) == 0x02)
       {
	counter = counter + 1;
	}
	if ((tempA & 0x04) == 0x04)
       {
    counter = counter + 1;
   }
   if ((tempA & 0x08) == 0x08) 
   {
     counter = counter + 1;
   }
	if ((tempA & 0x10) == 0x10) 
  {
     counter = counter + 1;
   }
  if ((tempA & 0x20) == 0x20)
   {
    counter = counter + 1;
   }
	if ((tempA & 0x40) == 0x40) 
  {
     counter = counter + 1;
  }
 if ((tempA & 0x80) == 0x80) 
  {      counter = counter + 1;

  }
	if ((tempB & 0x01) == 0x01) 
  {
      counter = counter + 1;
  }
   if ((tempB & 0x02) == 0x02)
    {
     counter = counter + 1;
    }
   if ((tempB & 0x04) == 0x04) 
    {
      counter = counter + 1;
    }
   if ((tempB & 0x08) == 0x08) 
   {
     counter = counter + 1;
   }
   if ((tempB & 0x10) == 0x10)
   {
        counter = counter + 1;
    }
   if ((tempB & 0x20) == 0x20)
   {       
     counter = counter + 1;
   }
 if ((tempB & 0x40) == 0x40) 
  {
   counter = counter + 1;
  }
   if ((tempB & 0x80) == 0x80)
  {
   counter = counter + 1;
  }

	PORTC = counter;
	
    }
    return 1;
}
