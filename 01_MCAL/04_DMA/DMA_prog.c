/***********************************************************************************************
 ***************************  - DMA_program.c				 		 ***************************
***************************   - Created: 4/12/2022				 	 ****************************
***************************   - Author: Abdelrahman_Magdy			 ****************************
***************************   - Version : _1_				 		 ****************************
***************************   - Note :
									*-
									*-
 **************************************************************************************/ 


/****************************************************************************************
***************************   The Foundation Of Function   ***************************** 
****************************************************************************************/


/************** INCLUDE LIB **************/
		 #include "STD_TYPE.h"
		 #include "BIT_MATH.h"
		 
/*****************************************/	 

/************** INCLUDE MCAL**************/
		#include "DMA_private.h"
		#include "DMA_interface.h"
		#include "DMA_config.h"

		
/*****************************************/

/************** INCLUDE HALL**************/
			

/*****************************************/

/************** INCLUDEAPP***************/


/*****************************************/


/********************************************************** Start_FUNCTION  **********************************************************/
/*		Function To init DMA(2)--> Stream(0) By :

									1 - SoftWare Priority Stream : VeryHigh   	      .
									2 - Set DIR Mode             : ( M T M )    	  .
									3 - Set S & D SIZE BIT       : (Word) =32 bit	  . 
									4 - Disable Direct Mode to used FIFO              .
									5 - Set FIFO Threshold       :  (Use full)	      .
									6 - SRC & DIS Increament     : S & D              .
									7 - EN Interrput Of 		 : Transfer Complete  .
 												
					*/
void MDMA2_vStreamInit(void)
{
	/* 1- Before Any Config The Bit Of EN Must = 0 ,It must Be Disable*/
		if( (DMA_2->StreamID[0].CR) ==1)
		{
				/* Disable It*/
			DMA_2->StreamID[0].CR &=~(1U<<0);
			/*It Take Time To Be Disable So Wait Time */
			while((DMA_2->StreamID[0].CR) == 1){}
		
		}
		else { /* For Misra */}
	
	/*******************************************************************************/
	  /* 2- Select The Channel(Used For Conect Peripheral To Memory) In stream  But From Mermoery To Memory Not Use*/
	// (DMA2_BASS_ADDRESS-> StreamID[0].CR)|= ; // not used 
	
	/*******************************************************************************/
	/* 3-SoftWare Priority Stream :{ LOW , Medium , High , VeryHigh} BIT(16 , 17)---> VeryHigh  */
	(DMA_2->StreamID[0].CR)|=(1U<<16)|(1U<<17U); 
	/*******************************************************************************/
	/* 4- Set DIR Mode :{ ( MTM ) ,PTM ,MTP} BIT (6,7) */
	(DMA_2->StreamID[0].CR)&=~(1U<<6U);
	(DMA_2->StreamID[0].CR)|=(1U<<7U);
	/*******************************************************************************/
	/* 5- Set M & M SIZE BIT(13,14) ,(11,12) :{Byte , HaveWord , (Word)}*/
			/* 	As Word 32 For Source	*/ 
	(DMA_2->StreamID[0].CR)&=~(1U<<11U);
	(DMA_2->StreamID[0].CR)|=(1U<<12U);
			/* 	As Word 32 For Distination	*/
	(DMA_2->StreamID[0].CR)&=~(1U<<13U);
	(DMA_2->StreamID[0].CR)|=(1U<<14U);			
	/*******************************************************************************/
	/* 6- Disable Direct Mode to used FIFO  */
	(DMA_2->StreamID[0].FCR)|=(1U<<2U);	
	/*******************************************************************************/
	/* 7-Set FIFO Threshold {(1/4),(1/2),(3/4),full} */
				/* (Use full)*/
	(DMA_2->StreamID[0].FCR)|=(1U<<0U)|(1U<<1U);
	/*******************************************************************************/
	/* 8-SRC & DIS Increament For Both */
	(DMA_2->StreamID[0].CR)&=~(1U<<9U);
	(DMA_2->StreamID[0].CR)&=~(1U<<10U);
	/*******************************************************************************/
	/* 9- EN Interrput Of (Transfer Complete) or(   ,  ,  , )  */
	(DMA_2->StreamID[0].CR)&=~(1U<<4U);
	/*******************************************************************************/
					/**************************************/
					

}
/*********************************************************** END_ FUNCTION   *********************************************************/


/********************************************************** Start_FUNCTION  **********************************************************/

void MDMA_voidSetAdresses(u32* Ptr_SrcAdd ,u32* Ptr_DisAdd ,u32 Copy_u32Size  )
{
	/* 1- Set the Source port register address in the DMA_SxPAR register.*/
	DMA_2->StreamID[0].PAR=(u32)Ptr_SrcAdd;
	/* 2- Set the Distination  address in the DMA_SxMA0R register */
	DMA_2->StreamID[0].M0AR=(u32) Ptr_DisAdd;
	/* 3- Configure the total number of data items to be transferred in the DMA_SxNDTR register.   */
	DMA_2->StreamID[0].NDTR=(u32)Copy_u32Size;
	
	
}
/*********************************************************** END_ FUNCTION   *********************************************************/


/********************************************************** Start_FUNCTION  **********************************************************/
/*		Function :	Enable DMA  
*/
void MDMA_vEnable(void)
{
	/* All Flag == 0 or make them =0 */
	(DMA_2 ->LIFCR)|=((1U<<0)|(1U<<2)|(1U<<3)|(1U<<4)|(1U<<5));
	 /* EN Bit One Way To Stearm */
	 DMA_2->StreamID[0].CR|=(1U<<0);
}
/*********************************************************** END_ FUNCTION   *********************************************************/
