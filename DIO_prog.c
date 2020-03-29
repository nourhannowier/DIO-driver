/*********************************************************/
/***********  Author       :NOURHAN NOWIER        ********/
/***********  Version      :V01                   ********/
/***********  Date         :26/3/2020             ********/
/***********  Description  :DIO_Program FUNCS     ********/
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


#include      "DIO_int.h"
#include      "DIO_reg.h"


/*********************************************************/
/**************  FUNCTION Implementation  ****************/
/*********************************************************/

/*********************************************************/
/* Description   : This function set pin Direction       */
/*                                                       */ 
/*                 Inputs : port , pin , Direction       */  
/*                 return : enum                         */  
/*********************************************************/
/*********************************************************/
/* Pre_condition :                                       */
/*                                                       */ 
/*                                                       */ 
/*********************************************************/


ERROR_enuStatus       DIO_enuSetPinDirection( u8 PORTID , u8 PINID , u8 Copy_u8Direction )
{
	ERROR_enuStatus   error = ES_NOK;
	if( ( PORTID < 4 )&&( PINID < 8 ) )
	{
		if( Copy_u8Direction == OUTPUT )
		{
			switch(PORTID)
			{
				case PORTA: SET_BIT( DDRA_Reg , PINID ); break;
				case PORTB: SET_BIT( DDRB_Reg , PINID ); break;
				case PORTC: SET_BIT( DDRC_Reg , PINID ); break;
				case PORTD: SET_BIT( DDRD_Reg , PINID ); break;
			}
			error = ES_OK ;
		}
		else if( Copy_u8Direction == INPUT )
		{
			switch(PORTID)
			{
			    case PORTA: CLR_BIT( DDRA_Reg , PINID ); break;
				case PORTB: CLR_BIT( DDRB_Reg , PINID ); break;
				case PORTC: CLR_BIT( DDRC_Reg , PINID ); break;
				case PORTD: CLR_BIT( DDRD_Reg , PINID ); break;
			}
			error = ES_OK ;
		}
	}
	else
	{
		error = ES_OUT_OF_RANGE ;
	}

	return error;	
}



/*********************************************************/
/**************  FUNCTION Implementation  ****************/
/*********************************************************/

/*********************************************************/
/* Description   : This function set pin Value           */
/*                                                       */ 
/*                 Inputs : port , pin , Value           */  
/*                 return : enum                         */  
/*********************************************************/
/*********************************************************/
/* Pre_condition :                                       */
/*                                                       */ 
/*                                                       */ 
/*********************************************************/


ERROR_enuStatus       DIO_enuSetPinValue( u8 PORTID , u8 PINID , u8 Copy_u8Value )
{
	ERROR_enuStatus   error =  ES_NOK;
	if( ( PORTID < 4 )&&( PINID < 8 ) )
	{
		if( Copy_u8Value == HIGH )
		{
			switch(PORTID)
			{
				case PORTA: SET_BIT( PORTA_Reg , PINID ); break;
				case PORTB: SET_BIT( PORTB_Reg , PINID ); break;
				case PORTC: SET_BIT( PORTC_Reg , PINID ); break;
				case PORTD: SET_BIT( PORTD_Reg , PINID ); break;
			}
			error = ES_OK ;
		}
		else if( Copy_u8Value == LOW )
		{
			switch(PORTID)
			{
				case PORTA: CLR_BIT( PORTA_Reg , PINID ); break;
				case PORTB: CLR_BIT( PORTB_Reg , PINID ); break;
				case PORTC: CLR_BIT( PORTC_Reg , PINID ); break;
				case PORTD: CLR_BIT( PORTD_Reg , PINID ); break;
			}
			error = ES_OK ;
		}
	}	
    else
	{
		error = ES_OUT_OF_RANGE ;
	}		
	return error;
}

/*********************************************************/
/**************  FUNCTION Implementation  ****************/
/*********************************************************/

/*********************************************************/
/* Description   : This function get pin Value           */
/*                                                       */ 
/*                 Inputs : port , pin                   */  
/*                 return : u8                           */  
/*********************************************************/
/*********************************************************/
/* Pre_condition :                                       */
/*                                                       */ 
/*                                                       */ 
/*********************************************************/


u8           DIO_u8GetPinValue( u8 PORTID , u8 PINID )
{
	u8 Local_u8Value =0;
	if( ( PORTID < 4 )&&( PINID < 8 ) )
	{
		switch(PORTID)
		{
			case PORTA: Local_u8Value = GET_BIT( PINA_Reg , PINID ); break;
			case PORTB: Local_u8Value = GET_BIT( PINB_Reg , PINID ); break;
			case PORTC: Local_u8Value = GET_BIT( PINC_Reg , PINID ); break;
			case PORTD: Local_u8Value = GET_BIT( PIND_Reg , PINID ); break;
		}
	}
	else
	
	return Local_u8Value ;
}

/*********************************************************/
/**************  FUNCTION Implementation  ****************/
/*********************************************************/

/*********************************************************/
/* Description   : This function set port direction      */
/*                                                       */ 
/*                 Inputs : port , Direction             */  
/*                 return : enum                         */  
/*********************************************************/
/*********************************************************/
/* Pre_condition :                                       */
/*                                                       */ 
/*                                                       */ 
/*********************************************************/


ERROR_enuStatus       DIO_enuSetPortDirection( u8 PORTID , u8 Copy_u8Direction )
{
	ERROR_enuStatus  error = ES_NOK;
	if( PORTID <4)
	{
		switch(PORTID)
		{
			case PORTA:  DDRA_Reg = Copy_u8Direction ; break;
			case PORTB:  DDRB_Reg = Copy_u8Direction ; break;
			case PORTC:  DDRC_Reg = Copy_u8Direction ; break;
			case PORTD:  DDRD_Reg = Copy_u8Direction ; break;
		}
			error = ES_OK ;
	}
	else
	{
		error = ES_OUT_OF_RANGE ;
	}
	
	return error ;	
}


/*********************************************************/
/**************  FUNCTION Implementation  ****************/
/*********************************************************/

/*********************************************************/
/* Description   : This function set port Value          */
/*                                                       */ 
/*                 Inputs : port , Value                 */  
/*                 return : enum                         */  
/*********************************************************/
/*********************************************************/
/* Pre_condition :                                       */
/*                                                       */ 
/*                                                       */ 
/*********************************************************/
ERROR_enuStatus       DIO_enuSetPortValue(u8 PORTID ,u8 Copy_u8Value)
{
	ERROR_enuStatus error = ES_NOK ;
	if(PORTID <4)
	{
		switch(PORTID)
		{
			case PORTA :   PORTA_Reg = Copy_u8Value ; break ;
			case PORTB :   PORTB_Reg = Copy_u8Value ; break ;
			case PORTC :   PORTC_Reg = Copy_u8Value ; break ;
			case PORTD :   PORTD_Reg = Copy_u8Value ; break ;
		}
		error = ES_OK ;
	}
	else
	{
		error = ES_OUT_OF_RANGE	;
	}
	return error;
}