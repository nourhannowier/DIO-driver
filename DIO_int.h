/*********************************************************/
/***********  Author       :NOURHAN NOWIER        ********/
/***********  Version      :V01                   ********/
/***********  Date         :26/3/2020             ********/
/***********  Description  :DIO_INTERFACE FUNCS   ********/
/*********************************************************/ 



/*********************************************************/
/*** guard of file will call one time in .c    ***********/
/*********************************************************/

#ifndef _DIO_INT_H_
#define _DIO_INT_H_


/*          PORT_ID        */
#define PORTA           0
#define PORTB           1
#define PORTC           2
#define PORTD           3


/*          PIN_ID         */
#define PIN0            0
#define PIN1            1
#define PIN2            2
#define PIN3            3
#define PIN4            4
#define PIN5            5
#define PIN6            6
#define PIN7            7


/*          Direction      */
#define INPUT           0
#define OUTPUT          1


/*          Value          */ 
#define LOW             0
#define HIGH            1




ERROR_enuStatus       DIO_enuSetPinDirection( u8 PORTID , u8 PINID , u8 Copy_u8Direction );

ERROR_enuStatus       DIO_enuSetPinValue( u8 PORTID , u8 PINID , u8 Copy_u8Value );

u8                    DIO_u8GetPinValue( u8 PORTID , u8 PINID );

ERROR_enuStatus       DIO_enuSetPortDirection( u8 PORTID , u8 Copy_u8Direction );

ERROR_enuStatus       DIO_enuSetPortValue(u8 PORTID ,u8 Copy_u8Value);


/*end of _DIO_INT_H_                                     */
#endifs