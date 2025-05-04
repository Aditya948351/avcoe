#include <htc.h>
#define _XTAL_FREQ 8000000
void main()
{
  TRISB=0X00;
  PORTB=0X00;
  while(1)
  { 
    PORTB=0XFF;
    __delay_ms(10000);
    PORTB=0X00;
    __delay_ms(10000);
  }
}
