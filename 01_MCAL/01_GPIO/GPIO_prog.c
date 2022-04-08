/****************************** *********************************************************
 ***************************  - GPIO_program.c				 ****************************
***************************   - Created: 3/9/2021			 ****************************
***************************   - Author: Abdelrahman_Magdy     ***************************
***************************   - Version : _1_				 ****************************
***************************   - Note :
									*-
									*-
 **************************************************************************************/ 


/*=======================================================================================
============================   The Foundation Of Function   ============================= 
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "STD_TYPES.h"
		 #include "BIT_MATH.h"
/*======================================*/	 
/*===========  INCLUDE MCAL  ===========*/
		#include "GPIO_private.h"
		#include "GPIO_interface.h"
		#include "GPIO_config.h"
/*======================================*/	
/*===========  INCLUDE HAL   ===========*/
			

/*======================================*/	

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/	




/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function Set The Mode Of Pin Mode Take 2Bits	
*			1- MODE_INPUT 
*			2- MODE_OUTPUT
*			3- MODE_ALTF  
*			4- MODE_ANALOG
*/
void MGPIO_vSetPinMode(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8Mode  ){
	
	switch(Copy_u8PortName)
	{
	  case _GPIOA_PORT : MGPIOA->MODER |= (u32) ( Copy_u8Mode << ( 2U* Copy_u8PinNum )) ; break;
	  case _GPIOB_PORT : MGPIOB->MODER |= (u32) ( Copy_u8Mode << ( 2U* Copy_u8PinNum )) ; break;
	  case _GPIOC_PORT : MGPIOC->MODER |= (u32) ( Copy_u8Mode << ( 2U* Copy_u8PinNum )) ; break;
	  case _GPIOD_PORT : MGPIOD->MODER |= (u32) ( Copy_u8Mode << ( 2U* Copy_u8PinNum )) ; break;
	  case _GPIOE_PORT : MGPIOE->MODER |= (u32) ( Copy_u8Mode << ( 2U* Copy_u8PinNum )) ; break;
	  case _GPIOH_PORT : MGPIOH->MODER |= (u32) ( Copy_u8Mode << ( 2U* Copy_u8PinNum )) ; break;
	  default : /*ERROR*/ break ;
    }
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function Set The Type Of OutPut (OpenDrain = 0 , PushPull = 1) :
*								                         - OUTPUT_TYPE_PUSH_PULL
*								                         - OUTPUT_TYPE_OPEN_DRAIN	
*/
void MGPIO_vSetPinOutPutType(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8OutPutType  ){
	
	switch(Copy_u8PortName)
	{
	  case _GPIOA_PORT : MGPIOA->OTYPER |= (u32) ( Copy_u8OutPutType << ( Copy_u8PinNum )) ; break;
	  case _GPIOB_PORT : MGPIOB->OTYPER |= (u32) ( Copy_u8OutPutType << ( Copy_u8PinNum )) ; break;
	  case _GPIOC_PORT : MGPIOC->OTYPER |= (u32) ( Copy_u8OutPutType << ( Copy_u8PinNum )) ; break;
	  case _GPIOD_PORT : MGPIOD->OTYPER |= (u32) ( Copy_u8OutPutType << ( Copy_u8PinNum )) ; break;
	  case _GPIOE_PORT : MGPIOE->OTYPER |= (u32) ( Copy_u8OutPutType << ( Copy_u8PinNum )) ; break;
	  case _GPIOH_PORT : MGPIOH->OTYPER |= (u32) ( Copy_u8OutPutType << ( Copy_u8PinNum )) ; break;
	  default : /*ERROR*/ break ;
     }
	
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/* Function Set The Speed (LOW , Meduim , High ,VeryHaigh):		
*					                                 - OUTPUT_SPEED_LOW      
*					                                 - OUTPUT_SPEED_MEDUIM   
*					                                 - OUTPUT_SPEED_HIGH     
*					                                 - OUTPUT_SPEED_VERY_HIGH	
*/
void MGPIO_vSetPinOutSpeed(u8 Copy_u8PortName ,u32 Copy_u8PinNum ,u32 Copy_u8OutSpeed ){
	
	switch(Copy_u8PortName)
	{
	  case _GPIOA_PORT : MGPIOA->OSPEEDR |= (u32) ( Copy_u8OutSpeed << ( 2U* Copy_u8PinNum )) ; break;
	  case _GPIOB_PORT : MGPIOB->OSPEEDR |= (u32) ( Copy_u8OutSpeed << ( 2U* Copy_u8PinNum )) ; break;
	  case _GPIOC_PORT : MGPIOC->OSPEEDR |= (u32) ( Copy_u8OutSpeed << ( 2U* Copy_u8PinNum )) ; break;
	  case _GPIOD_PORT : MGPIOD->OSPEEDR |= (u32) ( Copy_u8OutSpeed << ( 2U* Copy_u8PinNum )) ; break;
	  case _GPIOE_PORT : MGPIOE->OSPEEDR |= (u32) ( Copy_u8OutSpeed << ( 2U* Copy_u8PinNum )) ; break;
	  case _GPIOH_PORT : MGPIOH->OSPEEDR |= (u32) ( Copy_u8OutSpeed << ( 2U* Copy_u8PinNum )) ; break;
	  default : /*ERROR*/ break ;
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function Set The PULL :			
*					      - PULL_OFF
*					      - PULL_UP
*					      - PULL_DOWN
*/
void MGPIO_vSetPullType(u8 Copy_u8PortName ,u32 Copy_u8PinNum ,u32 Copy_u8PullType )
{
	
		switch(Copy_u8PortName)
	{
	  case _GPIOA_PORT : MGPIOA->PUPDR   |= (u32) ( Copy_u8PullType << ( 2U* Copy_u8PinNum )) ; break;
	  case _GPIOB_PORT : MGPIOB->PUPDR   |= (u32) ( Copy_u8PullType << ( 2U* Copy_u8PinNum )) ; break;
	  case _GPIOC_PORT : MGPIOC->PUPDR   |= (u32) ( Copy_u8PullType << ( 2U* Copy_u8PinNum )) ; break;
	  case _GPIOD_PORT : MGPIOD->PUPDR   |= (u32) ( Copy_u8PullType << ( 2U* Copy_u8PinNum )) ; break;
	  case _GPIOE_PORT : MGPIOE->PUPDR   |= (u32) ( Copy_u8PullType << ( 2U* Copy_u8PinNum )) ; break;
	  case _GPIOH_PORT : MGPIOH->PUPDR   |= (u32) ( Copy_u8PullType << ( 2U* Copy_u8PinNum )) ; break;
	  default : /*ERROR*/ break ;
	}
	
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*		
 *Function To Read Data From IDR
 */

u8 MGPIO_u8ReadData(u8 Copy_u8PORT ,u8 Copy_u8PIN)
{
	u8 L_u8Data = 0 ;
	switch(Copy_u8PORT)
	{ 
	  case _GPIOA_PORT :L_u8Data= GET_BIT(MGPIOA->IDR,Copy_u8PIN ) ; break;
	  
	  case _GPIOB_PORT :L_u8Data= GET_BIT(MGPIOB->IDR,Copy_u8PIN ) ; break;
	  
	  case _GPIOC_PORT :L_u8Data= GET_BIT(MGPIOC->IDR,Copy_u8PIN ) ; break;
	  
	  case _GPIOD_PORT :L_u8Data= GET_BIT(MGPIOD->IDR,Copy_u8PIN) ; break;
	  
	  case _GPIOE_PORT :L_u8Data= GET_BIT(MGPIOE->IDR,Copy_u8PIN) ; break;
	  
	  case _GPIOH_PORT :L_u8Data= GET_BIT(MGPIOH->IDR,Copy_u8PIN) ; break;
	  default : /*ERROR*/ break ;
		
	}
	return L_u8Data;
	
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*		
* Function To Write Data At ODR	Value :
*									  - HIGH  
*									  - LOW	
*/
void MGPIO_vWriteData(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8State)
{
	if(Copy_u8State==HIGH)
	{
		switch(Copy_u8PortName)
		{
		case _GPIOA_PORT :  SET_BIT(MGPIOA ->ODR,Copy_u8PinNum); break;
		
		case _GPIOB_PORT :  SET_BIT(MGPIOB ->ODR,Copy_u8PinNum); break;
		
		case _GPIOC_PORT :  SET_BIT(MGPIOC ->ODR,Copy_u8PinNum); break;
		
		case _GPIOD_PORT :  SET_BIT(MGPIOD ->ODR,Copy_u8PinNum); break;
		
		case _GPIOE_PORT :  SET_BIT(MGPIOE ->ODR,Copy_u8PinNum); break;
		
		case _GPIOH_PORT :  SET_BIT(MGPIOH ->ODR,Copy_u8PinNum); break;
		
		default : /*ERROR*/ break ;
		}
		
	}
	else{
		switch(Copy_u8PortName)
		{
		case _GPIOA_PORT :  CLR_BIT(MGPIOA ->ODR,Copy_u8PinNum); break;
		
		case _GPIOB_PORT :  CLR_BIT(MGPIOB ->ODR,Copy_u8PinNum); break;
		
		case _GPIOC_PORT :  CLR_BIT(MGPIOC ->ODR,Copy_u8PinNum); break;
		
		case _GPIOD_PORT :  CLR_BIT(MGPIOD ->ODR,Copy_u8PinNum); break;
		
		case _GPIOE_PORT :  CLR_BIT(MGPIOE ->ODR,Copy_u8PinNum); break;
		
		case _GPIOH_PORT :  CLR_BIT(MGPIOH ->ODR,Copy_u8PinNum); break;
		
		default : /*ERROR*/ break ;
		}
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*
- Function to Lock pin :
				        1)Set Pin 
						2)Set Pin 16
						3)Wait bit 16 =high
*/
void MGPIO_vPinLock(u8 Copy_u8PortNum ,u8 Copy_u8PinNum )
{
  switch(Copy_u8PortNum)	
  {
	  case _GPIOA_PORT  : 
							SET_BIT(MGPIOA->LCKR,Copy_u8PinNum );
							SET_BIT(MGPIOA->LCKR,_LUCKED_PIN );
							while(!(GET_BIT(MGPIOA->LCKR,_LUCKED_PIN)));
	  
	  break ; 
	  /*************************************************/
	  case _GPIOB_PORT  : 
							SET_BIT(MGPIOB->LCKR,Copy_u8PinNum );
							SET_BIT(MGPIOB->LCKR,_LUCKED_PIN );
							while(!(GET_BIT(MGPIOB->LCKR,_LUCKED_PIN)));
	  
	  break ; 
	  /*************************************************/
	    case _GPIOC_PORT  : 
							SET_BIT(MGPIOC->LCKR,Copy_u8PinNum );
							SET_BIT(MGPIOC->LCKR,_LUCKED_PIN );
							while(!(GET_BIT(MGPIOC->LCKR,_LUCKED_PIN)));
	  
	  break ; 
	  /*************************************************/
	  case _GPIOD_PORT  : 
							SET_BIT(MGPIOD->LCKR,Copy_u8PinNum );
							SET_BIT(MGPIOD->LCKR,_LUCKED_PIN );
							while(!(GET_BIT(MGPIOD->LCKR,_LUCKED_PIN)));
	  
	  break ;
     /*************************************************/	 
	case _GPIOE_PORT  : 
							SET_BIT(MGPIOE->LCKR,Copy_u8PinNum );
							SET_BIT(MGPIOE->LCKR,_LUCKED_PIN );
							while(!(GET_BIT(MGPIOE->LCKR,_LUCKED_PIN)));
	  
	  break ;
	  /*************************************************/	
	  case _GPIOH_PORT  : 
							SET_BIT(MGPIOH->LCKR,Copy_u8PinNum );
							SET_BIT(MGPIOH->LCKR,_LUCKED_PIN );
							while(!(GET_BIT(MGPIOH->LCKR,_LUCKED_PIN)));
	  
	  break ;
	  /*************************************************/	
  }
	
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void MGPIO_vSetPinAltFn( u8 Copy_u8PortNum ,u8 Copy_u8PinNum, u8 Copy_u8ALF )
{
	if(Copy_u8PinNum <=7U)
	{
		switch(Copy_u8PortNum )
		{
			 case _GPIOA_PORT  : MGPIOA->AFRL |=(u32)(Copy_u8ALF <<(4U* Copy_u8PinNum)); break ;
			 case _GPIOB_PORT  : MGPIOB->AFRL |=(u32)(Copy_u8ALF <<(4U* Copy_u8PinNum)); break ;
			 case _GPIOC_PORT  : MGPIOC->AFRL |=(u32)(Copy_u8ALF <<(4U* Copy_u8PinNum)); break ;
			 case _GPIOD_PORT  : MGPIOD->AFRL |=(u32)(Copy_u8ALF <<(4U* Copy_u8PinNum)); break ;
			 case _GPIOE_PORT  : MGPIOE->AFRL |=(u32)(Copy_u8ALF <<(4U* Copy_u8PinNum)); break ;
			 case _GPIOH_PORT  : MGPIOH->AFRL |=(u32)(Copy_u8ALF <<(4U* Copy_u8PinNum)); break ;
			 default : break ;
		}
		
	}
	// 8 : 15
	// i need 8 = 0 & 15 = 7
	
	else
	{
	switch(Copy_u8PortNum )
		{
			 case _GPIOA_PORT  : MGPIOA->AFRH |=(u32)(Copy_u8ALF <<(4U* (Copy_u8PinNum % 8U))); break ;
			 case _GPIOB_PORT  : MGPIOB->AFRH |=(u32)(Copy_u8ALF <<(4U* (Copy_u8PinNum % 8U ))); break ;
			 case _GPIOC_PORT  : MGPIOC->AFRH |=(u32)(Copy_u8ALF <<(4U* (Copy_u8PinNum % 8U))); break ;
			 case _GPIOD_PORT  : MGPIOD->AFRH |=(u32)(Copy_u8ALF <<(4U* (Copy_u8PinNum % 8U ))); break ;
			 case _GPIOE_PORT  : MGPIOE->AFRH |=(u32)(Copy_u8ALF <<(4U* (Copy_u8PinNum % 8U ))); break ;
			 case _GPIOH_PORT  : MGPIOH->AFRH |=(u32)(Copy_u8ALF <<(4U* (Copy_u8PinNum % 8U))); break ;
			 default : break ;
		}	
		
		
	}

	
}

/*====================================================   END_ FUNCTION   ====================================================*/

void MGPIO_vPortOutputOneByte(u8 Copy_u8Port, u8 Copy_u8Data, u8 Copy_u8StartBit)
{
	switch(Copy_u8Port){
		case _GPIOA_PORT :
			MGPIOA->ODR = (MGPIOA->ODR & ~(0xff << (Copy_u8StartBit ))) | (Copy_u8Data << (Copy_u8StartBit));
			break;
		case _GPIOB_PORT :
			MGPIOB->ODR = (MGPIOB->ODR & ~(0xff << (Copy_u8StartBit))) | (Copy_u8Data << (Copy_u8StartBit));
			break;
		case _GPIOC_PORT :
			MGPIOC->ODR = (MGPIOC->ODR & ~(0xff << (Copy_u8StartBit ))) | (Copy_u8Data << (Copy_u8StartBit));
			break;
		case _GPIOD_PORT :
			MGPIOD->ODR = (MGPIOD->ODR & ~(0xff << (Copy_u8StartBit))) | (Copy_u8Data << (Copy_u8StartBit));
			break;
		case _GPIOE_PORT :
			MGPIOE->ODR = (MGPIOE->ODR & ~(0xff << (Copy_u8StartBit))) | (Copy_u8Data << (Copy_u8StartBit));
			break;
		case _GPIOH_PORT :
			MGPIOH->ODR = (MGPIOH->ODR->ODR & ~(0xff << (Copy_u8StartBit ))) | (Copy_u8Data << (Copy_u8StartBit));
			break;
	}

}
/*====================================================   END_ FUNCTION   ====================================================*/
