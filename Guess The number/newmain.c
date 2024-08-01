/*
 * File:   newmain.c
 * Author: Abdelrhman

 */
#define _XTAL_FREQ (8000000)
#include "KPD.h"

u8 customRand()
{
    static u8 seed = 0;          // Initialize seed (you can set any initial value)
    seed = (seed * 37 + 17) % 9; // Update seed (adjust constants as needed)
    return seed + 1;             // Return a number between 1 and 9
}

int main(void)
{
    TRISD = 0x00;
    PORTD = 0x00;
    KPD_enu_Init();
    u8 pressed_key, count = 1;
    u8 randomNumber = customRand();
    while (1)
    {
        do
        {
            KPD_enu_GetPressed(&pressed_key);
        } while (pressed_key == 0xff);
        if (pressed_key != (randomNumber + '0'))
        {
            if (count == 1)
            {
                PORTD = 0x01;
            }
            else if (count == 2)
            {
                PORTDbits.RD1 = 1;
            }
            else if (count == 3)
            {
                PORTDbits.RD2 = 1;
            }
            else
            {
                PORTD = 0x40;
                count = 0;
            }
            count++;
        }
        else
        {
            PORTD = 0x80;
        }
    }
}
