/*********************************************************/
/***********  Author       :NOURHAN NOWIER        ********/
/***********  Version      :V01                   ********/
/***********  Date         :26/3/2020             ********/
/***********  Description  :LCD_Program FUNCS     ********/
/*********************************************************/ 



/*********************************************************/
/**************   STD LIB DIRECTIVES  ********************/
/*********************************************************/


#include      "STD_TYPES.h"
#include      "BIT_MATH.h"
#include      "ERROR_STATUS.h"


/*********************************************************/
/***************  Component DIRECTIVES  ******************/
/*********************************************************/


#include      <util/delay.h>
#include      "DIO_int.h"

#include      "LCD_int.h"
#include      "LCD_priv.h"
#include      "LCD_config.h"


/*********************************************************/
/**************  FUNCTION Implementation  ****************/
/*********************************************************/

/*********************************************************/
/* Description   : This function Initialize LCD          */
/*                                                       */ 
/*                 Inputs : void                         */  
/*                 return : enum                         */  
/*********************************************************/
/*********************************************************/
/* Pre_condition :                                       */
/*                                                       */ 
/*                                                       */ 
/*********************************************************/


ERROR_enuStatus     LCD_enuInit(void)
{
	ERROR_enuStatus  error = ES_NOK ;
	
	_delay_ms(35);
	
	#if       LCD_MODE   ==    BITS_8

	/****************************************************/
	/*              DL  =  1 for 8_BITS mode            */
	/*              N   =  1 for 2_LINES                */
	/*              F   =  0 for 5x7                    */
	/****************************************************/
		LCD_enuSendCMD(0X38);
		_delay_ms(1);
	/****************************************************/
	/*              D   =  1 for Display ON             */
	/*              C   =  0 for Cursor                 */
	/*              B   =  0 for Blinking OFF           */
	/****************************************************/
		LCD_enuSendCMD(0X0C);
		_delay_ms(1);
    /****************************************************/
	/*                  CLEAR DISPLAY                   */
	/****************************************************/
		LCD_enuSendCMD(0X01);
		_delay_ms(2);
	/****************************************************/
	/*          ENTRY MODE :                            */
	/*          I/D  =  1 for INCREASES                 */
	/*          S    =  0 for Display not shift         */
	/****************************************************/	
		LCD_enuSendCMD(0X06);
		_delay_ms(1);
		
		error = ES_OK;
		
	#elif     LCD_MODE   ==    BITS_4
	
	/****************************************************/
	/*              DL  =  0 for 4_BITS mode            */
	/*              N   =  1 for 2_LINES                */
	/*              F   =  0 for 5x7                    */
	/****************************************************/
		LCD_enuSendCMD(0X28);
		_delay_ms(1);
	/****************************************************/
	/*              D   =  1 for Display ON             */
	/*              C   =  0 for Cursor                 */
	/*              B   =  0 for Blinking OFF           */
	/****************************************************/
		LCD_enuSendCMD(0X0C);
		_delay_ms(1);
    /****************************************************/
	/*                  CLEAR DISPLAY                   */
	/****************************************************/
		LCD_enuSendCMD(0X01);
		_delay_ms(2);
		
	/****************************************************/
	/*          ENTRY MODE :                            */
	/*          I/D  =  1 for INCREASES                 */
	/*          S    =  0 for Display not shift         */
	/****************************************************/	
		LCD_enuSendCMD(0X06);
		_delay_ms(1);
		
		error = ES_OK;
		
	#else
		#error  " Wrong LCD MODE "
	
	#endif		
	
	return error ;
}


/*********************************************************/
/**************  FUNCTION Implementation  ****************/
/*********************************************************/

/*********************************************************/
/* Description   : This function send command            */
/*                                                       */ 
/*                 Inputs : command                      */  
/*                 return : enum                         */  
/*********************************************************/
/*********************************************************/
/* Pre_condition :                                       */
/*                                                       */ 
/*                                                       */ 
/*********************************************************/

ERROR_enuStatus     LCD_enuSendCMD( u8 Copy_u8CMD )
{
	ERROR_enuStatus  error = ES_NOK ;
    
	/*1) RS = 0 */
	DIO_enuSetPinValue ( LCD_CONTROL , RS_PIN  , LOW );
	
	/*2) RW = 0 */
	DIO_enuSetPinValue ( LCD_CONTROL , RW_PIN  , LOW );
	
	/* calling latch function */
	LCD_enuLatch( Copy_u8CMD );
	
	error  =  ES_NOK  ;
	
	return error ;
}


/*********************************************************/
/**************  FUNCTION Implementation  ****************/
/*********************************************************/

/*********************************************************/
/* Description   : This function send data               */
/*                                                       */ 
/*                 Inputs : data                         */  
/*                 return : enum                         */  
/*********************************************************/
/*********************************************************/
/* Pre_condition :                                       */
/*                                                       */ 
/*                                                       */ 
/*********************************************************/

ERROR_enuStatus     LCD_enuSendData( u8 Copy_u8Data ) 
{
	ERROR_enuStatus  error = ES_NOK ;
	
	/*1) RS = 0 */
	DIO_enuSetPinValue ( LCD_CONTROL , RS_PIN  , HIGH );
	
	/*2) RW = 0 */
	DIO_enuSetPinValue ( LCD_CONTROL , RW_PIN  , LOW );
	
	/* calling latch function */
	LCD_enuLatch( Copy_u8CMD );
	
	error  =  ES_NOK  ;
	
	return error ;
}

/*********************************************************/
/**************  FUNCTION Implementation  ****************/
/*********************************************************/

/*********************************************************/
/* Description   : This function give pulse              */
/*                 on enable Pin                         */ 
/*                 Inputs : Void                         */  
/*                 return : enum                         */  
/*********************************************************/
/*********************************************************/
/* Pre_condition :                                       */
/*                                                       */ 
/*                                                       */ 
/*********************************************************/

ERROR_enuStatus   LCD_enuLatch ( u8 Copy_u8Value )
{
	ERROR_enuStatus  error = ES_NOK ;
	
	/*3) Send Command or Send Data */
	DIO_enuSetPortValue( LCD_DATA , Copy_u8Value );
	
	/*4) Enable Pulse*/
	DIO_enuSetPinValue ( LCD_CONTROL , E_PIN  , HIGH );
	_delay_ms(2);
	DIO_enuSetPinValue ( LCD_CONTROL , E_PIN  , LOW );
	
	error  =  ES_NOK  ;
	
	return error ;
}