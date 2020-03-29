/****************************************************/
/********   Author       :NOURHAN NOWIER     ********/
/********   Version      :V01                ********/
/********   Date         :3/3/2020           ********/
/********   Description  :BIT_MATH LIB       ********/
/****************************************************/ 



/****************************************************/
/* guard of file will call one time in .c    ********/
/****************************************************/

#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_


#define SET_BIT(Reg, bit_num)         (Reg|=(1<<bit_num))
#define CLR_BIT(Reg, bit_num)         (Reg&=~(1<<bit_num))
#define TOG_BIT(Reg, bit_num)         (Reg^=(1<<bit_num))
#define GET_BIT(Reg, bit_num)         ((Reg>>bit_num)&0x01)
#define ASSIGN_BIT(Reg,bit_num,val)   Reg=((Reg&(~(1<<bit_num)))|(val<<bit_num))

#endif