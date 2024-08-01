#include "STD_TYPES.h"
#include "ERROR_STATES.h"
#include "BIT_MATH.h"
#include "Stack.h"
#include "DIO_INTERFACE.h"
#include "LCD_INTERFACE.h"
#include "KEYPAD_INTERFACE.h"
#include <math.h>
#include <string.h>

void Infix_To_Postfix(u8 *array, Stack *postfix);
void display(ELEMENT_TYPE ch);
int Is_digit(u8 ch);
int Is_unery_operator(u8 op);
int Precedance_element1_is_grater(ELEMENT_TYPE element_1, ELEMENT_TYPE element_2);
f64 Evaluate_Postfix(Stack *postfix);
f64 DO_operation(ELEMENT_TYPE poped_element1, ELEMENT_TYPE poped_element2, ELEMENT_TYPE poped_element);

void reverse(char *str, int len);
int intToStr(int x, char str[], int d);
void fltoa(float n, char *res, int afterpoint);
u8 Mode1(void);
