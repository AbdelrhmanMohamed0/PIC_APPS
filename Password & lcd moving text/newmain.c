/*
 * File:   newmain.c
 * Author: Abdelrhman
 *
 * Created on 21  2024, 06:17 ?
 */

#define _XTAL_FREQ (8000000)
#include <xc.h>
/*
#include "APP.h"
int main(void)
{
	DIO_Enu_Init();
	LCD_enuInit();
	KPD_enu_Init();
	while (1)
	{
			Mode1();
	}
}
*/

#include <String.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "DIO_INTERFACE.h"
#include "LCD_INTERFACE.h"
#include "KPD.h"
void main(void) {
    DIO_Enu_Init();
    LCD_enuInit();
    KPD_enu_Init();
    u8 array[5]={0};
    u8 pressed_key,i=0,res=1;
    LCD_enuSendString("WELCOME USER");
    __delay_ms(2000);
    while(1){
        LCD_enuClearScreen();
        LCD_enuSendString("Enter Password");
        LCD_enuSetPosition(2,1);
        LCD_enuSendString("consists(4)digit");
        for(int j=0;j<4;j++){
        do
        {
            KPD_enu_GetPressed(&pressed_key);
        } while (pressed_key == 0xff);
            if(i==0)
              LCD_enuClearScreen();
            LCD_enuSendData(pressed_key);
            array[i++]=pressed_key;
            if(i==4){
                array[i]='\0';
            i=0;}
        }
        res=strcmp(array,"1234");
        if(res==0){
        LCD_enuClearScreen();    
        LCD_enuSendString("Abdelrhman");
        LCD_enuSetPosition(2,1);
        LCD_enuSendString("Mohamed"); 
        while(1){
        for(int j=0;j<8;j++){
        LCD_enuClearScreen();
        LCD_enuSetPosition(1,1);
        LCD_enuSendString("Abdelrhman");
        LCD_enuSetPosition(2,1);
        LCD_enuSendString("Mohamed");
        for(int j=0;j<16;j++){
            LCD_enuSendCommand(_LCD_SHIFT_RIGHT);
            __delay_ms(200);
            }
        }
        for(int j=0;j<8;j++){
        LCD_enuClearScreen();
        LCD_enuSetPosition(1,16);
        LCD_enuSendString("Abdelrhman");
        LCD_enuSetPosition(2,16);
        LCD_enuSendString("Mohamed");
            for(int j=0;j<15;j++){
            LCD_enuSendCommand(_LCD_SHIFT_LEFT);
            __delay_ms(200); 
            }
        }
        }
        }
        else{
        LCD_enuClearScreen();
        LCD_enuSendString("WRONG PASSWORD");          
        __delay_ms(1500);
        }
                
    }
    
    return;
}
