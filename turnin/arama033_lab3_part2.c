#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {

    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char tempA = 0x00;
    unsigned char setter = 0x00;
 
    while (1) {
	tempA = PINA;
  setter = 0x00;


if ((tempA == 0x01) || (tempA == 0x02)) 
{
 setter = 0x60;  
}

else if ((tempA == 0x03) || (tempA == 0x04))
 {
   setter = 0x70;  
 }
	
	else if ((tempA == 0x05) || (tempA == 0x06)) 
  {
    setter = 0x38;  
  }

	else if ((tempA  == 0x07) || (tempA == 0x08) || (tempA == 0x09)) 
  {
    setter = 0x3C;  
  }

else if ((tempA == 0x0A) || (tempA == 0x0B) || (tempA == 0x0C)) 
{
   setter = 0x3E;  
}


else if ((tempA  == 0x0D) || (tempA  == 0x0E) || (tempA == 0x0F)) 
{
   setter = 0x3F;  
}

else
{

setter = 0x40; 

{
	PORTC = setter;
	
    }
    return 1;
}
