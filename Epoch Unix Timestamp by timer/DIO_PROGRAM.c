#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#define _XTAL_FREQ (8000000)
#include "DIO_PRIVATE.h"
#include "DIO_CONFIG.h"

ES_t DIO_Enu_Init(void)
{
    ES_t Local_EnuErrorState = ES_NOT_OK;

    TRISA = CONC(PA_PIN7_DIR, PA_PIN6_DIR, PA_PIN5_DIR, PA_PIN4_DIR, PA_PIN3_DIR, PA_PIN2_DIR, PA_PIN1_DIR, PA_PIN0_DIR);
    TRISB = CONC(PB_PIN7_DIR, PB_PIN6_DIR, PB_PIN5_DIR, PB_PIN4_DIR, PB_PIN3_DIR, PB_PIN2_DIR, PB_PIN1_DIR, PB_PIN0_DIR);
    TRISC = CONC(PC_PIN7_DIR, PC_PIN6_DIR, PC_PIN5_DIR, PC_PIN4_DIR, PC_PIN3_DIR, PC_PIN2_DIR, PC_PIN1_DIR, PC_PIN0_DIR);
    TRISD = CONC(PD_PIN7_DIR, PD_PIN6_DIR, PD_PIN5_DIR, PD_PIN4_DIR, PD_PIN3_DIR, PD_PIN2_DIR, PD_PIN1_DIR, PD_PIN0_DIR);
    TRISE = CONC(PE_PIN7_DIR, PE_PIN6_DIR, PE_PIN5_DIR, PE_PIN4_DIR, PE_PIN3_DIR, PE_PIN2_DIR, PE_PIN1_DIR, PE_PIN0_DIR);
    
    PORTA = CONC(PA_PIN7_VAL, PA_PIN6_VAL, PA_PIN5_VAL, PA_PIN4_VAL, PA_PIN3_VAL, PA_PIN2_VAL, PA_PIN1_VAL, PA_PIN0_VAL);
    PORTB = CONC(PB_PIN7_VAL, PB_PIN6_VAL, PB_PIN5_VAL, PB_PIN4_VAL, PB_PIN3_VAL, PB_PIN2_VAL, PB_PIN1_VAL, PB_PIN0_VAL);
    PORTC = CONC(PC_PIN7_VAL, PC_PIN6_VAL, PC_PIN5_VAL, PC_PIN4_VAL, PC_PIN3_VAL, PC_PIN2_VAL, PC_PIN1_VAL, PC_PIN0_VAL);
    PORTD = CONC(PD_PIN7_VAL, PD_PIN6_VAL, PD_PIN5_VAL, PD_PIN4_VAL, PD_PIN3_VAL, PD_PIN2_VAL, PD_PIN1_VAL, PD_PIN0_VAL);
    PORTE = CONC(PE_PIN7_VAL, PE_PIN6_VAL, PE_PIN5_VAL, PE_PIN4_VAL, PE_PIN3_VAL, PE_PIN2_VAL, PE_PIN1_VAL, PE_PIN0_VAL);
    Local_EnuErrorState = ES_OK;

    return Local_EnuErrorState;
}

ES_t DIO_Enu_SetPortDirection(u8 Copy_u8PortID, u8 Copy_u8Value)
{
    ES_t Local_EnuErrorState = ES_NOT_OK;

    if (Copy_u8PortID <= DIO_PORTE)
    {
        switch (Copy_u8PortID)
        {
        case DIO_PORTA:
            TRISA = Copy_u8Value;
            break;
        case DIO_PORTB:
            TRISB = Copy_u8Value;
            break;
        case DIO_PORTC:
            TRISC = Copy_u8Value;
            break;
        case DIO_PORTD:
            TRISD = Copy_u8Value;
            break;
        case DIO_PORTE:
            TRISE = Copy_u8Value;
            break;
        }
        Local_EnuErrorState = ES_OK;
    }
    else
    {
        Local_EnuErrorState = ES_OUT_OF_RANGE;
    }
    return Local_EnuErrorState;
}

ES_t DIO_Enu_SetPortValue(u8 Copy_u8PortID, u8 Copy_u8Value)
{
    ES_t Local_EnuErrorState = ES_NOT_OK;

    if (Copy_u8PortID <= DIO_PORTE)
    {
        switch (Copy_u8PortID)
        {
        case DIO_PORTA:
            PORTA = Copy_u8Value;
            break;
        case DIO_PORTB:
            PORTB = Copy_u8Value;
            break;
        case DIO_PORTC:
            PORTC = Copy_u8Value;
            break;
        case DIO_PORTD:
            PORTD = Copy_u8Value;
            break;
        case DIO_PORTE:
            PORTE = Copy_u8Value;
            break;
        }
        Local_EnuErrorState = ES_OK;
    }
    else
    {
        Local_EnuErrorState = ES_OUT_OF_RANGE;
    }

    return Local_EnuErrorState;
}

ES_t DIO_Enu_SetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value)
{
    ES_t Local_EnuErrorState = ES_NOT_OK;
    if (Copy_u8PortID <= DIO_PORTE &&
        Copy_u8PinID <= DIO_PIN7 &&
        Copy_u8Value <= OUTPUT)
    {
        switch (Copy_u8PortID)
        {
        case DIO_PORTA:
            TRISA &= ~(DIO_MASK_BIT << Copy_u8PinID);
            TRISA |= (Copy_u8Value << Copy_u8PinID);
            break;
        case DIO_PORTB:
            TRISB &= ~(DIO_MASK_BIT << Copy_u8PinID);
            TRISB |= (Copy_u8Value << Copy_u8PinID);
            break;
        case DIO_PORTC:
            TRISC &= ~(DIO_MASK_BIT << Copy_u8PinID);
            TRISC |= (Copy_u8Value << Copy_u8PinID);
            break;
        case DIO_PORTD:
            TRISD &= ~(DIO_MASK_BIT << Copy_u8PinID);
            TRISD |= (Copy_u8Value << Copy_u8PinID);
            break;
        case DIO_PORTE:
            TRISE &= ~(DIO_MASK_BIT << Copy_u8PinID);
            TRISE |= (Copy_u8Value << Copy_u8PinID);
            break;
        }
        Local_EnuErrorState = ES_OK;
    }
    else
    {
        Local_EnuErrorState = ES_OUT_OF_RANGE;
    }

    return Local_EnuErrorState;
}

ES_t DIO_Enu_SetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value)
{
    ES_t Local_EnuErrorState = ES_NOT_OK;

    if (Copy_u8PortID <= DIO_PORTE &&
        Copy_u8PinID <= DIO_PIN7 &&
        Copy_u8Value <= HIGH)
    {
        switch (Copy_u8PortID)
        {
        case DIO_PORTA:
            PORTA &= ~(DIO_MASK_BIT << Copy_u8PinID);
            PORTA |= (Copy_u8Value << Copy_u8PinID);
            break;
        case DIO_PORTB:
            PORTB &= ~(DIO_MASK_BIT << Copy_u8PinID);
            PORTB |= (Copy_u8Value << Copy_u8PinID);
            break;
        case DIO_PORTC:
            PORTC &= ~(DIO_MASK_BIT << Copy_u8PinID);
            PORTC |= (Copy_u8Value << Copy_u8PinID);
            break;
        case DIO_PORTD:
            PORTD &= ~(DIO_MASK_BIT << Copy_u8PinID);
            PORTD |= (Copy_u8Value << Copy_u8PinID);
            break;
        case DIO_PORTE:
            PORTE &= ~(DIO_MASK_BIT << Copy_u8PinID);
            PORTE |= (Copy_u8Value << Copy_u8PinID);
            break;
        }
        Local_EnuErrorState = ES_OK;
    }
    else
    {
        Local_EnuErrorState = ES_OUT_OF_RANGE;
    }

    return Local_EnuErrorState;
}

ES_t DIO_Enu_TogPortValue(u8 Copy_u8PortID)
{
    ES_t Local_EnuErrorState = ES_NOT_OK;

    if (Copy_u8PortID <= DIO_PORTE)
    {
        switch (Copy_u8PortID)
        {
        case DIO_PORTA:
            PORTA = ~PORTA;
            break;
        case DIO_PORTB:
            PORTB = ~PORTB;
            break;
        case DIO_PORTC:
            PORTC = ~PORTC;
            break;
        case DIO_PORTD:
            PORTD = ~PORTD;
            break;
        case DIO_PORTE:
            PORTE = ~PORTE;
            break;
        }
        Local_EnuErrorState = ES_OK;
    }
    else
    {
        Local_EnuErrorState = ES_OUT_OF_RANGE;
    }

    return Local_EnuErrorState;
}

ES_t DIO_Enu_TogPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
    ES_t Local_EnuErrorState = ES_NOT_OK;

    if (Copy_u8PortID <= DIO_PORTE &&
        Copy_u8PinID <= DIO_PIN7)
    {
        switch (Copy_u8PortID)
        {
        case DIO_PORTA:
            TOG_BIT(PORTA, Copy_u8PinID);
            break;
        case DIO_PORTB:
            TOG_BIT(PORTB, Copy_u8PinID);
            break;
        case DIO_PORTC:
            TOG_BIT(PORTC, Copy_u8PinID);
            break;
        case DIO_PORTD:
            TOG_BIT(PORTD, Copy_u8PinID);
            break;
        case DIO_PORTE:
            TOG_BIT(PORTE, Copy_u8PinID);
            break;
        }
        Local_EnuErrorState = ES_OK;
    }
    else
    {
        Local_EnuErrorState = ES_OUT_OF_RANGE;
    }

    return Local_EnuErrorState;
}

ES_t DIO_Enu_GetPortValue(u8 Copy_u8PortID, u8 *Copy_pu8Value)
{
    ES_t Local_EnuErrorState = ES_NOT_OK;

    if (Copy_pu8Value != NULL)
    {
        if (Copy_u8PortID <= DIO_PORTE)
        {
            switch (Copy_u8PortID)
            {
            case DIO_PORTA:
                *Copy_pu8Value = PORTA;
                break;
            case DIO_PORTB:
                *Copy_pu8Value = PORTB;
                break;
            case DIO_PORTC:
                *Copy_pu8Value = PORTC;
                break;
            case DIO_PORTD:
                *Copy_pu8Value = PORTD;
                break;
            case DIO_PORTE:
                *Copy_pu8Value = PORTE;
                break;
            }
            Local_EnuErrorState = ES_OK;
        }
        else
        {
            Local_EnuErrorState = ES_OUT_OF_RANGE;
        }
    }
    else
    {
        Local_EnuErrorState = ES_NULL_POINTER;
    }

    return Local_EnuErrorState;
}

ES_t DIO_Enu_GetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 *Copy_pu8Value)
{
    ES_t Local_EnuErrorState = ES_NOT_OK;

    if (Copy_pu8Value != NULL)
    {
        if (Copy_u8PortID <= DIO_PORTE &&
            Copy_u8PinID <= DIO_PIN7)
        {
            switch (Copy_u8PortID)
            {
            case DIO_PORTA:
                *Copy_pu8Value = GIT_BIT(PORTA, Copy_u8PinID);
                break;
            case DIO_PORTB:
                *Copy_pu8Value = GIT_BIT(PORTB, Copy_u8PinID);
                break;
            case DIO_PORTC:
                *Copy_pu8Value = GIT_BIT(PORTC, Copy_u8PinID);
                break;
            case DIO_PORTD:
                *Copy_pu8Value = GIT_BIT(PORTD, Copy_u8PinID);
                break;
            case DIO_PORTE:
                *Copy_pu8Value = GIT_BIT(PORTE, Copy_u8PinID);
                break;
            }
            Local_EnuErrorState = ES_OK;
        }
        else
        {
            Local_EnuErrorState = ES_OUT_OF_RANGE;
        }
    }
    else
    {
        Local_EnuErrorState = ES_NULL_POINTER;
    }

    return Local_EnuErrorState;
}

ES_t DIO_Enu_WriteHighNibbles(u8 Copy_u8PortID,u8 Copy_u8Value)
{

    ES_t Local_EnuErrorState = ES_NOT_OK;

	if ( (Copy_u8PortID <= DIO_PORTE))
	{
		Copy_u8Value = (Copy_u8Value<<4) ;
		switch(Copy_u8PortID)
		{
		case DIO_PORTA :
			PORTA &=0x0f;                   
			PORTA |=Copy_u8Value;			
			break ;
		case DIO_PORTB:
			PORTB &=0x0f;                 
			PORTB |=Copy_u8Value;
			break ;
		case DIO_PORTC :
			PORTC &=0x0f;                 
			PORTC |=Copy_u8Value;
			break ;
		case DIO_PORTD:
			PORTD &=0x0f;                 
			PORTD |=Copy_u8Value;
			break ;
		case DIO_PORTE:
			PORTE &=0x0f;                 
			PORTE |=Copy_u8Value;
			break ;
		default: break ;

        }
        Local_EnuErrorState = ES_OK;
    }
    else
    {
        Local_EnuErrorState = ES_OUT_OF_RANGE;
    }

	return Local_EnuErrorState ;

}

ES_t DIO_Enu_WriteLowNibbles(u8 Copy_u8PortID,u8 Copy_u8Value)
{
    ES_t Local_EnuErrorState = ES_NOT_OK;

	if ( (Copy_u8PortID <= DIO_PORTE))
	{
		Copy_u8Value&=0x0f;
		switch(Copy_u8PortID)
		{
		case DIO_PORTA :
			PORTA &=0xf0;                   
			PORTA |=Copy_u8Value;			
			break ;
		case DIO_PORTB:
			PORTB &=0xf0;                 
			PORTB |=Copy_u8Value;
			break ;
		case DIO_PORTC :
			PORTC &=0xf0;                 
			PORTC |=Copy_u8Value;
			break ;
		case DIO_PORTD:
			PORTD &=0xf0;                 
			PORTD |=Copy_u8Value;
			break ;
		case DIO_PORTE:
			PORTE &=0xf0;                 
			PORTE |=Copy_u8Value;
			break ;
            default: break ;

        }
        Local_EnuErrorState = ES_OK;
    }
    else
    {
        Local_EnuErrorState = ES_OUT_OF_RANGE;
    }

	return Local_EnuErrorState ;

}
