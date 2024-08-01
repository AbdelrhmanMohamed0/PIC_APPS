#define _XTAL_FREQ (8000000)
#include <xc.h>
#include "KPD.h"
ES_t KPD_enu_Init(void)
{
	ES_t Local_EnuErrorState = ES_NOT_OK;
	TRISB = 0x0F;
	PORTB = 0xFF;
	// open internal pull-up resistor
	OPTION_REGbits.nRBPU = 0;
	Local_EnuErrorState = ES_OK;

	return Local_EnuErrorState;
}

ES_t KPD_enu_GetPressed(u8 *Copy_pu8Value)
{
	ES_t Local_EnuErrorState = ES_NOT_OK;
	u8 LOC_u8PinState;
	u8 LOC_u8ColumnIndex, LOC_u8RowIndex;
	*Copy_pu8Value = NOTPRESSED;
	for (LOC_u8ColumnIndex = 0; LOC_u8ColumnIndex < COLS_NUM; LOC_u8ColumnIndex++)
	{
		CLR_BIT(KPD_PORT, LOC_u8KPDColumnArr[LOC_u8ColumnIndex]);
		for (LOC_u8RowIndex = 0; LOC_u8RowIndex < ROWS_NUM; LOC_u8RowIndex++)
		{
			LOC_u8PinState = GIT_BIT(KPD_PORT, LOC_u8KPDRowArr[LOC_u8RowIndex]);
			if (LOC_u8PinState == 0)
			{
				*Copy_pu8Value = KPD_u8Buttons[LOC_u8RowIndex][LOC_u8ColumnIndex];
				while (LOC_u8PinState == 0)
				{
					LOC_u8PinState = GIT_BIT(KPD_PORT, LOC_u8KPDRowArr[LOC_u8RowIndex]);
				}
				Local_EnuErrorState = ES_OK;
				return Local_EnuErrorState;
			}
		}
		SET_BIT(KPD_PORT, LOC_u8KPDColumnArr[LOC_u8ColumnIndex]);
	}
	Local_EnuErrorState = ES_OK;
	return Local_EnuErrorState;
}
