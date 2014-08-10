#include <avr/io.h>
#include <avr/interrupt.h>

int main()
{
  cli();

  volatile unsigned int n;
  volatile unsigned char i;
  volatile unsigned char j;

  // set pins PB1,PB2,PB3,PB4 as output
  DDRB = 0x1E;
  n = 0;
  while (n < 30) n += 1;
  PORTB = 0;
  n = 0;
  while (n < 30) n += 1;

  while (1) {
    i = 0;
    while (i++ < 5) {
      PORTB |= 0x08;
      j = 0;
      while (j++ < 18) {
        n = 0;
        while (n++ < 150);
        PORTB |= 0x10;
        n = 0;
        while (n++ < 50);
        PORTB &= 0xEF;
      }
      PORTB &= 0xF7;
      j = 0;
      while (j++ < 18) {
        n = 0;
        while (n++ < 150);
        PORTB |= 0x10;
        n = 0;
        while (n++ < 50);
        PORTB &= 0xEF;
      }
    }

    i=0;

    while (i++ < 5) {
      PORTB |= 0x02;
      j=0;
      while (j++ < 15) {
        n = 0;
        while (n++ < 180);
        PORTB |= 0x10;
        n = 0;
        while (n++ < 60);
        PORTB &= 0xEF;
      }
      PORTB &= 0xFD;
      j=0;
      while (j++ < 15) {
        n = 0;
        while (n++ < 180);
        PORTB |= 0x10;
        n = 0;
        while (n++ < 60);
        PORTB &= 0xEF;
      }
    }
  }

  return 0;
}

