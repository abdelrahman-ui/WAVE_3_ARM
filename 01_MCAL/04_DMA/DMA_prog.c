





/********************************************************** Start_FUNCTION  **********************************************************/
/* Use Stream NUM = 0 */
void MDMA2_vStreamInit(void)
{
	
	/* 1- Before Any Config The Bit Of EN Must = 0 ,It must Be Disable*/
		if( (DMA_2 ->StreamID[0].CR) ==1)
		{
				/* Disable It*/
			DMA_2 ->StreamID[0].CR &=~(1U<<0);
			/*It Take Time To Be Disable So Wait Time */
			while((DMA_2 ->StreamID[0].CR) == 1){}
		
		}
		
	/*else */
	
	/*******************************************************************************/
	  /* 2- Select The Channel(Used For Conect Peripheral To Memory) In stream  But From Mermoery To Memory Not Use*/
	// (DMA2_BASS_ADDRESS-> StreamID[0].CR)|= ; // not used 
	
	
	/*******************************************************************************/
	/* 3-SoftWare Priority Stream :{ LOW , Medium , High , VeryHigh} BIT(16 , 17)---> VeryHigh  */
	
	
	
	/*******************************************************************************/
	/* 4- Set DIR Mode :{ ( MTM ) ,PTM ,MTP} BIT (6,7) */
	
	
	
	/*******************************************************************************/
	/* 5- Set M & M SIZE BIT(13,14) ,(11,12) :{Byte , HaveWord , (Word)}*/
			/* 	As Word 32 For Source	*/ 
	
			
			/* 	As Word 32 For Distination	*/
			
			
	/*******************************************************************************/
	/* 6- Disable Direct Mode to used fifo  */


	/*******************************************************************************/
		/* 7-Set FIFO Threshold {(1/4),(1/2),(3/4),full} */
	/* (Use full)*/
	
	
	
	/*******************************************************************************/
	/* 8-SRC & DIS Increament For Both */
	
	
	/*******************************************************************************/
	/* 9- EN Interrput Of (Transfer Complete) or(   ,  ,  , )  */
	
	
	
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
	
	 /* EN Bit One Way To Stearm */
	
}