/*
 * File:   main.c
 * Author: Abdelrhman
 *
 * Created on 07 ????, 2024, 06:40 ?
 */

#include <xc.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "DIO_INTERFACE.h"
#include "LCD_INTERFACE.h"

#define _XTAL_FREQ (8000000)

volatile u8 flag1 = 0, flag2 = 0;
volatile s64 counter = 0;

// Function to initialize external interrupt
void ex_interrupt_init()
{
    OPTION_REGbits.nRBPU = 0; // Enable pull-up resistors for PORTB
    INTE = 1;                 // Enable external interrupt
    RBIE = 1;
    INTEDG = 0; // Trigger on falling edge
    INTF = 0;
    RBIF = 0; // Clear the interrupt flag
    GIE = 1;  // Enable global interrupt
}

// Function to display "WELCOME USER" message for 3 seconds
void display_welcome_message()
{
    LCD_enuSendString("WELCOME USER");
    __delay_ms(3000);
    LCD_enuClearScreen();
}

// Function to handle system sleep
void system_sleep()
{
    // Turn off LCD
    LCD_enuClearScreen();
    // Enter sleep mode
    asm("SLEEP");
}

void __interrupt() my_isr()
{
    GIE = 0;
    if (INTE == 1 && RBIF == 1)
    {
        if (flag1 == 0)
        {
            // Check button presses
            if (GIT_BIT(PORTB, 5) == 0)
            {
                while (GIT_BIT(PORTB, 5) == 0)
                    ;
                counter++;
            }
            else if (GIT_BIT(PORTB, 6) == 0)
            {
                while (GIT_BIT(PORTB, 6) == 0)
                    ;
                counter--;
            }
            else if (GIT_BIT(PORTB, 7) == 0)
            {
                while (GIT_BIT(PORTB, 7) == 0)
                    ;
                counter = 0;
            }
            RBIF = 0; // Reset the interrupt flag
        }
    }

    if (INTE == 1 && INTF == 1)
    {
        // Handle wake-up button
        if (GIT_BIT(PORTB, 0) == 0)
        {
            // Display wake-up message
            LCD_enuClearScreen();
            LCD_enuSendString("wake up #");
            LCD_enuSetPosition(2, 1);
            LCD_enuSendString("Abdelrhman ");
            __delay_ms(2000);
            LCD_enuClearScreen();
            flag1 = 0;
            flag2 = 1;
            INTF = 0; // Reset the interrupt flag
        }
    }
    GIE = 1; // Enable interrupt again
}

void main()
{
    DIO_Enu_Init();
    LCD_enuInit();
    ex_interrupt_init();

    // Display welcome message
    display_welcome_message();

    while (1)
    {
        // Display counter value
        while (flag1 == 0)
        {
            LCD_enuSetPosition(1, 1);
            LCD_enuSendString("Counter Val=");
            LCD_enuSetPosition(2, 1);
            LCD_enuSendNumber(counter);
            flag2 = 0;

            // Check if no button press for 4 seconds
            if (flag1 == 0)
            {
                for (u16 i = 0; i < 4000; i++)
                {
                    __delay_ms(1);
                    if (flag2 == 1)
                    {
                        break;
                    }
                }
                flag1 = 1;
                system_sleep();
            }
        }
    }
}
