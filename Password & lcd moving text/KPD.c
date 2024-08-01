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
	static u8 LOC_u8KPDRowArr[ROWS_NUM] = {KPD_R0, KPD_R1, KPD_R2, KPD_R3};
#if COLS_NUM == 4
	static u8 LOC_u8KPDColumnArr[COLS_NUM] = {KPD_C0, KPD_C1, KPD_C2, KPD_C3};
#elif COLS_NUM == 6
	static u8 LOC_u8KPDColumnArr[COLS_NUM] = {KPD_C0, KPD_C1, KPD_C2, KPD_C3, KPD_C4, KPD_C5};
#endif
	*Copy_pu8Value = NOTPRESSED;
	for (LOC_u8ColumnIndex = 0; LOC_u8ColumnIndex < COLS_NUM; LOC_u8ColumnIndex++)
	{
#if COLS_NUM == 4
        CLR_BIT(KPD_PORT,LOC_u8KPDColumnArr[LOC_u8ColumnIndex]);
#elif COLS_NUM == 6
		if (LOC_u8ColumnIndex < 4)
            CLR_BIT(KPD_PORT,LOC_u8KPDColumnArr[LOC_u8ColumnIndex]);
		else
            CLR_BIT(KPD_PORT_PLUS,LOC_u8KPDColumnArr[LOC_u8ColumnIndex]);
#endif
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
#if COLS_NUM == 4
        SET_BIT(KPD_PORT, LOC_u8KPDColumnArr[LOC_u8ColumnIndex]);
#elif COLS_NUM == 6
		if (LOC_u8ColumnIndex < 4)
        SET_BIT(KPD_PORT, LOC_u8KPDColumnArr[LOC_u8ColumnIndex]);
		else
        SET_BIT(KPD_PORT_PLUS, LOC_u8KPDColumnArr[LOC_u8ColumnIndex]);
#endif
	}
	Local_EnuErrorState = ES_OK;
}
