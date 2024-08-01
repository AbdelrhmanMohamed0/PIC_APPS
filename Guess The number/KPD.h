/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"

#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7

#define KPD_PORT  PORTB

#define KPD_R0    PIN0
#define KPD_R1    PIN1
#define KPD_R2    PIN2
#define KPD_R3    PIN3

#define KPD_C0    PIN4
#define KPD_C1    PIN5
#define KPD_C2    PIN6
#define KPD_C3    PIN7

#define NOTPRESSED 0xff

#define ROWS_NUM 4
#define COLS_NUM 4
                         /* C0   C1  C2  C3  */
static u8 KPD_u8Buttons[ROWS_NUM][COLS_NUM] = { {'7','8','9','/'}, /* Row0 */
						   				 		{'4','5','6','*'}, /* Row1 */
						   				 		{'1','2','3','-'}, /* Row2 */
						   				 		{'?','0','=','+'}  /* Row3 */
                           			   		  };
static u8 LOC_u8KPDColumnArr[COLS_NUM] = {KPD_C0, KPD_C1, KPD_C2, KPD_C3};
static u8 LOC_u8KPDRowArr[ROWS_NUM] = {KPD_R0, KPD_R1, KPD_R2, KPD_R3};

ES_t KPD_enu_Init(void);
ES_t KPD_enu_GetPressed( u8 * Copy_pu8Value );
#endif	/* XC_HEADER_TEMPLATE_H */

