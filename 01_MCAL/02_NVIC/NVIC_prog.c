/****************************** *********************************************************
 ***************************  - NVIC_program.c				 ****************************
***************************   - Created: /2021			 ****************************
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
		#include "NVIC_private.h"
		#include "NVIC_interface.h"
		#include "NVIC_config.h"
/*======================================*/	
/*===========  INCLUDE HAL   ===========*/
			

/*======================================*/	

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/	

void MNVIC_vEnableINT(u8 Copy_u8IntNUM)
{
	if( Copy_u8IntNUM <= 31U)
	{
		NVIC_ISER_0 =(1U<<Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM <= 63U)
	{
		Copy_u8IntNUM-=32;
		NVIC_ISER_1 =(1U<<Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM <= 85U)
	{
		Copy_u8IntNUM-=64;
		NVIC_ISER_2 =(1U<<Copy_u8IntNUM);
	}
	else
	{
		/* Return Error */
	}
}

void MNVIC_vEnablePeripheral ( u8 Copy_u8INTID ){

	P_ISER [ Copy_u8INTID / 32 ] = 1U << ( Copy_u8INTID % 32 ) ;
    
}



void MNVIC_vDisableINT(u8 Copy_u8IntNUM)
{
	if( Copy_u8IntNUM <= 31U)
	{
		NVIC_ICER0  =(1U<<Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM <= 63U)
	{
		Copy_u8IntNUM-=32;
		NVIC_ICER1  =(1U<<Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM <= 85U)
	{
		Copy_u8IntNUM-=64;
		NVIC_ICER2  =(1U<<Copy_u8IntNUM);
	}
	else
	{
		/* Return Error */
	}
}

/*
void MNVIC_vDisablePeripheral ( u8 Copy_u8INTID ){

	P_ICER [ Copy_u8INTID / 32 ] = 1U << ( Copy_u8INTID % 32 ) ;
    
}
*/

void MNVIC_vSetPendingFlag(u8 Copy_u8IntNUM)
{
if( Copy_u8IntNUM <= 31U)
	{
		NVIC_ISPR0   =(1U<<Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM <= 63U)
	{
		Copy_u8IntNUM-=32;
		NVIC_ISPR1   =(1U<<Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM <= 85U)
	{
		Copy_u8IntNUM-=64;
		NVIC_ISPR2   =(1U<<Copy_u8IntNUM);
	}
	else
	{
		/* Return Error */
	}

}

/*
void MNVIC_vSetPendingFlag(u8 Copy_u8IntNUM)
{
	
}

*/


void MNVIC_vClrPendingFlag(u8 Copy_u8IntNUM)
{
if( Copy_u8IntNUM <= 31U)
	{
		NVIC_ICPR0   =(1U<<Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM <= 63U)
	{
		Copy_u8IntNUM-=32;
		NVIC_ICPR1   =(1U<<Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM <= 85U)
	{
		Copy_u8IntNUM-=64;
		NVIC_ICPR2   =(1U<<Copy_u8IntNUM);
	}
	else
	{
		/* Return Error */
	}

}




u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNUM)
{
	u8 L_u8ActiveState =0;
	if( Copy_u8IntNUM <= 31U)
	{
		L_u8ActiveState= GET_BIT(NVIC_IABR0,Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM <= 63U)
	{
		Copy_u8IntNUM-=32;
		L_u8ActiveState= GET_BIT(NVIC_IABR1,Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM <= 85U)
	{
		Copy_u8IntNUM-=64;
		L_u8ActiveState= GET_BIT(NVIC_IABR2,Copy_u8IntNUM);
	}
	else
	{
		/* Return Error */
	}
	return L_u8ActiveState;
		
	
}

/*
u8   MNVIC_u8GetActive( u8 Copy_u8INTID ){

	u8 LOC_u8Active = GET_BIT( (MNVIC->IAPR[ Copy_u8INTID/32 ]) , ( Copy_u8INTID % 32 ) );
	return LOC_u8Active ;

}

*/




/********************************************************** Start_FUNCTION  **********************************************************/
/*		Function :	
                     * Handel Only External Int Priority .
					 * Divide REG From SCB From  And Put Your Priority In IPR Bit  ( 4 , 5 , 6 , 7 ) So Must << 4 bit.		 
*/
	
void MNVIC_vSetGroupSubGroupPriority(u8 Copy_u8IntID , u8 Copy_u8GroupPriority,u8 Copy_u8SubGroup  )
{
	#if CNF_GROUP_SUB ==_GROUP_4_SUB_0	
						if(Copy_u8GroupPriority <=16U )
						{
	                    /* PassWord (0x05FA)+ Case (  (4) For Group  &  (0) For SubGroub		*/
						     SCB_AIRCR |= 0x05FA0300;
						/*	At IPR[Indx] Put The Four Bit For Group  */	
					    /*  Index is The Peripheral ID From Vector Table*/
					 	  NVIC_IPR[Copy_u8IntID]=(Copy_u8GroupPriority<<4U)|(Copy_u8SubGroup <<0U);
						}
						else
						{
							/* ERROR Out of Range */
						}
	#elif CNF_GROUP_SUB ==_GROUP_3_SUB_1
						if((Copy_u8GroupPriority <=7U )&&(Copy_u8SubGroup <= 1U))
						{
						/*		PassWord + Case (  (3) For Group  &  (1) For SubGroub		*/
								SCB_AIRCR |= 0x05FA0400;
						/*	At IPR[Indx] Put The Four Bit For Group  */	
						/*  Index is The Peripheral ID From Vector Table*/	
						NVIC_IPR[Copy_u8IntNum]= (u8) (Copy_u8GroupPriority<<5U)|((u8)(Copy_u8SubGroupPriority << 4U))	;
						}
						else
						{
							/* ERROR Out of Range */
						}
    #elif CNF_GROUP_SUB ==_GROUP_2_SUB_2
						if((Copy_u8GroupPriority <=4U )&&(Copy_u8SubGroup <= 4U))
						{
						/*		PassWord + Case (  (2) For Group  &  (2) For SubGroub		*/
	                    		SCB_AIRCR |= 0x05FA0500;
	                    /*	At IPR[Indx] Put The Four Bit For Group  */	
	                    /*  Index is The Peripheral ID From Vector Table*/	
	                    NVIC_IPR[Copy_u8IntNum]= (u8) (Copy_u8GroupPriority<<6U)|((u8)(Copy_u8SubGroupPriority << 4U))	;
						}
						else
						{
							/* ERROR Out of Range */
						}
	#elif CNF_GROUP_SUB ==_GROUP_1_SUB_3
						if((Copy_u8GroupPriority <=1U )&&(Copy_u8SubGroup <= 7U))
						{
	                   /*		PassWord + Case (  (1) For Group  &  (3) For SubGroub		*/
	                   		SCB_AIRCR |= 0x05FA0600;
	                   /*	At IPR[Indx] Put The Four Bit For Group  */	
	                   /*  Index is The Peripheral ID From Vector Table*/	
	                   NVIC_IPR[Copy_u8IntNum]= (u8) (Copy_u8GroupPriority<<7U)|((u8)(Copy_u8SubGroupPriority << 4U))	;	
						}
						else
						{
							/* ERROR Out of Range */
						}
	#elif CNF_GROUP_SUB ==_GROUP_0_SUB_4
						if(Copy_u8SubGroup <= 15U)
						{
						/*		PassWord + Case (  (0) For Group  &  (4) For SubGroub		*/
	                           SCB_AIRCR |= 0x05FA0700;
	                    	NVIC_IPR[Copy_u8IntNum]=(u8)(Copy_u8SubGroupPriority << 4U)	|(Copy_u8SubGroup << 0U);
						}
						else
						{
							/* ERROR Out of Range */
						}

	#endif 
}
/*********************************************************** END_ FUNCTION   ***********************************************************/

/*
void MNVIC_VidSetPriority( s8 Copy_u8INTID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u32 Copy_u8Group ){

	u8 Priority =  Copy_u8SubPriority | Copy_u8GroupPriority << ( (Copy_u8Group - 0x05FA0300) / 256 )  ;
	//Core Peripheral
	if( Copy_u8INTID < 0  ){

		if( Copy_u8INTID == MEMORY_MANAGE || Copy_u8INTID == BUS_FAULT || Copy_u8INTID == USAGE_FAULT ){

			Copy_u8INTID += 3;
			SCB->SHPR1 = ( Priority ) << ( (8 * Copy_u8INTID) + 4 );

		}
		else if ( Copy_u8INTID == SV_CALL ){

			Copy_u8INTID += 7;
			SCB->SHPR2 = ( Priority ) << ( (8 * Copy_u8INTID) + 4 );

		}
		else if( Copy_u8INTID == PEND_SV || Copy_u8INTID == SYSTICK ){

			Copy_u8INTID += 8;

			SCB->SHPR3 = ( Priority ) << ( (8 * Copy_u8INTID) + 4 );

		}

	}
    //External Peripheral
	else if( Copy_u8INTID >= 0 ){

		MNVIC->IPR[ Copy_u8INTID ] = Priority << 4 ;

	}

	SCB->AIRCR = Copy_u8Group ;

}
*/
/*













*/