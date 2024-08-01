/*
 * File:   newmain.c
 * Author: Abdelrhman Mohamed
 *
 * Created on 17 , 2024, 09:37 ?
 */


#include <xc.h>
#define _XTAL_FREQ (8000000)
#define SET_BIT(REG , BIT) (REG |=  (1 << BIT))
#define CLR_BIT(REG , BIT) (REG &= ~(1 << BIT))
#define TOG_BIT(REG , BIT) (REG ^=  (1 << BIT))
#define GIT_BIT(REG , BIT) ((REG >> BIT) & 0x1)
const unsigned char delay = 10 ;
void sev_seg1_display(unsigned int num)
{
    SET_BIT(PORTB,2);
    CLR_BIT(PORTB,3);
    CLR_BIT(PORTB,4);
    PORTC = (num%10);
    __delay_ms(delay);
    CLR_BIT(PORTB,2);
    SET_BIT(PORTB,3);
    CLR_BIT(PORTB,4);
    PORTC = ((num/10)%10);
    __delay_ms(delay);
    CLR_BIT(PORTB,2);
    CLR_BIT(PORTB,3);
    SET_BIT(PORTB,4);
    PORTC = ((num/100)%10);
    __delay_ms(delay);
}
void sev_seg2_display(unsigned int num)
{
    SET_BIT(PORTC,4);
    CLR_BIT(PORTC,5);
    CLR_BIT(PORTC,6);
    PORTD = (num%10);
    __delay_ms(delay);
    CLR_BIT(PORTC,4);
    SET_BIT(PORTC,5);
    CLR_BIT(PORTC,6);
    PORTD = ((num/10)%10);
    __delay_ms(delay);
    CLR_BIT(PORTC,4);
    CLR_BIT(PORTC,5);
    SET_BIT(PORTC,6);
    PORTD = ((num/100)%10);
    __delay_ms(delay);
}

void delay_with_7_segment(unsigned int number1,unsigned int number2,long delaay)
{
    delaay /= 60;
    while(--delaay > 0)
    {
        sev_seg1_display(number1);
        sev_seg2_display(number2);
    }
}
void main(void) {
    TRISC=0;
    PORTC=0;
    TRISD=0;
    PORTD=0;
    TRISB=0xc3;
    OPTION_REGbits.nRBPU=0;
    CLR_BIT(PORTB,2);
    CLR_BIT(PORTB,3);
    CLR_BIT(PORTB,4);
    unsigned int counter_team_1=0;
    unsigned int counter_team_2=0;
    delay_with_7_segment((unsigned int)101,(unsigned int)103,3000);
    while(1)
    {
    if(PORTBbits.RB0==0){
        counter_team_1 +=2;
        while(PORTBbits.RB0==0);
    }
    else if(PORTBbits.RB1==0){
        counter_team_1 +=3;
        while(PORTBbits.RB1==0);
    }
        else if(PORTBbits.RB6==0){
        counter_team_2 +=2;
        while(PORTBbits.RB6==0);
    }
        else if(PORTBbits.RB7==0){
        counter_team_2 +=3;
        while(PORTBbits.RB7==0);
    }
        delay_with_7_segment(counter_team_1,counter_team_2,120);
    } 
    return;
}
