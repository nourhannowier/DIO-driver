/*********************************************************/
/***********  Author       :NOURHAN NOWIER        ********/
/***********  Version      :V01                   ********/
/***********  Date         :26/3/2020             ********/
/***********  Description  :LCD_INTERFACE FUNCS   ********/
/*********************************************************/ 



/*********************************************************/
/*** guard of file will call one time in .c    ***********/
/*********************************************************/

#ifndef _LCD_INT_H_
#define _LCD_INT_H_

/****                  CONTROL                       *****/
#define  LCD_CONTROL          PORTA
#define  RS_PIN               PIN0
#define  RW_PIN               PIN1
#define  E_PIN                PIN2


/****                  DATA                          *****/
#define  LCD_DATA             PORTB


ERROR_enuStatus     LCD_enuInit(void);

ERROR_enuStatus     LCD_enuSendCMD(  u8 Copy_u8CMD  ); 

ERROR_enuStatus     LCD_enuSendData( u8 Copy_u8Data ); 

ERROR_enuStatus     LCD_enuSendString( u8 * Copy_Pu8String );


#endif
