#define _XTAL_FREQ (8000000)
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(void)
{
    int random_number = (rand() % 9) + 1;

    // init phase
    OPTION_REGbits.nRBPU = 0;
    TRISB = 0x38; //(0,1,2) out (3-4-5) IN
    PORTB = 0x07; // rows are initially high
    TRISD = 0;
    PORTD = 0;
    unsigned char num = 0;
    unsigned char no_of_trials = 0;
    while (1)
    {
        // ******** First Raw *******
        PORTB = 0x07;
        PORTBbits.RB0 = 0;
        // check for columns
        if (PORTBbits.RB3 == 0)
            num = 1;
        else if (PORTBbits.RB4 == 0)
            num = 2;
        else if (PORTBbits.RB5 == 0)
            num = 3;
        // ******** Second Raw *******
        PORTB = 0x07;
        PORTBbits.RB1 = 0;
        // check for columns
        if (PORTBbits.RB3 == 0)
            num = 4;
        else if (PORTBbits.RB4 == 0)
            num = 5;
        else if (PORTBbits.RB5 == 0)
            num = 6;
        // ******** Third Raw *******
        PORTB = 0x07;
        PORTBbits.RB2 = 0;
        // check for columns
        if (PORTBbits.RB3 == 0)
            num = 7;
        else if (PORTBbits.RB4 == 0)
            num = 8;
        else if (PORTBbits.RB5 == 0)
            num = 9;
        // PORTD = num;
        //__delay_ms(750)  //this for education only

        // check if the gussed number equal to the random number
        if (num == random_number)
        {
            PORTDbits.RD7 == 1; // turn on the green led
            __delay_ms(500);
            break;
        }
        else
        {
            if (no_of_trials == 0)
            {
                no_of_trials++;
                PORTD = 0x01;
            }
            else if (no_of_trials == 1)
            {
                no_of_trials++;
                PORTD = 0x03;
            }
            else if (no_of_trials == 2)
            {
                no_of_trials++;
                PORTD = 0x87;
                __delay_ms(500);
                break;
            }
                  
        }

            
    }
}
