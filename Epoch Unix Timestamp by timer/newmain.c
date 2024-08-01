/*
 * File:   newmain.c
 * Author: Abdelrhman
 *
 * Created on 08 ????, 2024, 07:12 ?
 */


#define _XTAL_FREQ (8000000)
#include <xc.h>
#include <time.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "DIO_INTERFACE.h"
#include "LCD_INTERFACE.h"
#include "KPD.h"
#include "timer.h"
unsigned short cnt = 0;
    time_t epochTime ;
void __interrupt() my_isr()
{
    GIE = 0;
    if(TMR0IF == 1 && TMR0IE == 1)
    {
        
        cnt++;
        if(cnt == 4000)
        {
            epochTime++;
            cnt =0;
        }
        TMR0IF = 0; //reset the flag --important--
    }
    TMR0 = 6+54; //54 - is a COMPENSATION VALUE FOR ISR instructions
    GIE =1; //enable interrupt again again
    
}

void main(void) {
    struct tm *timeInfo;
    u8 pressed_key ,*endPtr, i=0,array[20]={0};
    DIO_Enu_Init();
    LCD_enuInit();
    KPD_enu_Init();
    timer0_init(_TIMER_PRESCALER_2);
    LCD_enuSendString("WELCOME #");
    LCD_enuSetPosition(2,1);
    LCD_enuSendString("Abdelrhman");
    __delay_ms(2000);
    LCD_enuClearScreen();
    LCD_enuSendString("enter the Epoch ");
       LCD_enuSetPosition(2,1);
    LCD_enuSendString("Unix Timestamp");
    while(1){
        do{
        do
        {
            KPD_enu_GetPressed(&pressed_key);
        } while (pressed_key == 0xff);
        if(i == 0){        
        LCD_enuClearScreen();
        }
        LCD_enuSendData(pressed_key);
        array[i++]=pressed_key;
        }while(pressed_key!='=');
        array[--i]='\0';
        LCD_enuClearScreen();
        epochTime = strtol(array, &endPtr, 10);
        while(1){
        timeInfo = localtime(&epochTime);
        LCD_enuSetPosition(1,1);
        LCD_enuSendNumber(timeInfo->tm_mday + 1);
        LCD_enuSendData('/');
        LCD_enuSendNumber(timeInfo->tm_mon + 1);
        LCD_enuSendData('/');
        LCD_enuSendNumber(timeInfo->tm_year + 1900);
        LCD_enuSetPosition(2,1);
        LCD_enuSendNumber((timeInfo->tm_hour + 4)%12);
        LCD_enuSendData(':');
        LCD_enuSendNumber((timeInfo->tm_min + 40)%60);
        LCD_enuSendData(':');
        LCD_enuSendNumber(timeInfo->tm_sec / 10);
        LCD_enuSendNumber(timeInfo->tm_sec % 10);
        }
    }
}


