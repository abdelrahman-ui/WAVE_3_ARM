/***************************************************************************************
 *************************** - DMA_interface.h				 ***************************
***************************   - Created: 4/12/2022			 ****************************
***************************   -Author: Abdelrahman_Magdy     ***************************
***************************   -Version : _1_				 ***************************
***************************   -Note :
									*-
									*-
 **************************************************************************************/ 



/*************************************************************************************
		* What i sell To Customer
		*  The Archictect Give The API	
						- The Name Of Function 
						- What is The Input 
						- What Is The Output
						- Macro 
						 
*************************************************************************************/ 

/*************************************************************************************
******************* guard of file will call on time in .c		   *******************
*************************************************************************************/










#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

#include "STD_TYPE.h"

/* Function To Init DMA : */
void MDMA2_vStreamInit(void);
/* Function :	To Set Addrese Of Source & Distination , block size*/
void MDMA2_vSetAdresses(u32 * Ptr_SrcAdd ,u32 * Ptr_DisAdd , u32 Copy_u32Size );
/* Function :	To EN_DMA */
void MDMA_vEnable(void);




#endif
