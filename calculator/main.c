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
