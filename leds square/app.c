#define _XTAL_FREQ (8000000)
#include <xc.h>
void main(void) {
    TRISB = 0;
    PORTB = 0;
    int j = 0;
    while(1) {
        j = 0;
        for(int i = 0; i < 8; i++) {
            PORTB = 0x00;
            if(i < 3) {
                PORTB |= (1 << i);
                PORTB |= 0x30;
            } else if(i == 3) {
                PORTB = 0x2C;
            } else if(i > 3 && i < 7) {
                PORTB |= (1 << (6 - i));
                PORTB |= 0x18;
            } else {
                PORTB  = 0x29;
            }
            __delay_ms(500);
        }
        while(j < 500) {
            PORTB = 0x01;
            PORTB = 0x03;
            PORTB = 0x07;
            j++;
        }
    }
}
