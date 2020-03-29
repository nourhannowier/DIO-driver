/****************************************************/
/********   Author       :NOURHAN NOWIER     ********/
/********   Version      :V01                ********/
/********   Date         :3/3/2020           ********/
/********   Description  :ERROR_enuStatus LIB   ********/
/****************************************************/ 



/****************************************************/
/* guard of file will call one time in .c    ********/
/****************************************************/

#ifndef _ERROR_enuStatus_H_
#define _ERROR_enuStatus_H_


typedef enum Error
{
	ES_OK,
	ES_NOK,
	ES_OUT_OF_RANGE,
	ES_NULL_POINTER
}ERROR_enuStatus;

#endif