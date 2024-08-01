#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define DIO_MASK_BIT	1

#define DIO_PORTA		0
#define DIO_PORTB		1
#define DIO_PORTC		2
#define DIO_PORTD		3
#define DIO_PORTE		4

#define DIO_PIN0		0
#define DIO_PIN1		1
#define DIO_PIN2		2
#define DIO_PIN3		3
#define DIO_PIN4		4
#define DIO_PIN5		5
#define DIO_PIN6		6
#define DIO_PIN7		7


#define INPUT		1
#define OUTPUT		0

#define LOW			0
#define HIGH		1

#define FLOAT		0
#define PULL_UP		1

#define TRISA  		(*((u8*)0x85))
#define PORTA		(*((v_u8*)0x05))


#define TRISB  		(*((u8*)0x86))
#define PORTB		(*((v_u8*)0x06))


#define TRISC  		(*((u8*)0x87))
#define PORTC		(*((v_u8*)0x07))


#define TRISD  		(*((u8*)0x88))
#define PORTD		(*((v_u8*)0x08))

#define TRISE  		(*((u8*)0x89))
#define PORTE		(*((v_u8*)0x09))


#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)		0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)			CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)


#endif