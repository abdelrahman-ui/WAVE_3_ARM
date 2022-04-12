
/****************************************************************************************
***************************   - DMA_private.h				 ****************************
***************************   - Created: 4/12/2022			 ****************************
***************************   - Author: Abdelrahman_Magdy    ****************************
***************************   - Version : _1_				 ****************************
***************************   - Note :
									  *-
									  *-
 **************************************************************************************/ 

/**************************************************************************************

*	 - Developer can't Edit in it    
*	  - Register _ Defination		
*	  - Design : 
					- #define	:	NO
					- Union		:	NO
					- Struct	:	YES

**************************************************************************************/

/*************************************************************************************
******************* guard of file will call on time in .c		   *******************
*************************************************************************************/ 


#ifndef _DMA_PRIVATE_H_
#define _DMA_PRIVATE_H_
#include "STD_TYPE.h"
/***********************************************************************************
	-----> Macros
			*Struct For DMA Stream We Have 8 Stream  Every one have This Register/ 			
************************************************************************************/

typedef struct 
{
 volatile u32 CR      ;     /*!< DMA stream x configuration register      */
 volatile u32 NDTR    ;     /*!< DMA stream x number of data register     */
 volatile u32 PAR     ;     /*!< DMA stream x peripheral address register */
 volatile u32 M0AR    ;     /*!< DMA stream x memory 0 address register   */
 volatile u32 M1AR    ;     /*!< DMA stream x memory 1 address register   */
 volatile u32 FCR     ;     /*!< DMA stream x FIFO control register       */
		
}DMA_Stream_t ;

typedef struct{
	
	volatile u32 LISR        ;  /*!< DMA low interrupt status register,      Address offset: 0x00 */
	volatile u32 HISR        ;  /*!< DMA high interrupt status register,     Address offset: 0x04 */
	volatile u32 LIFCR       ;  /*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
	volatile u32 HIFCR       ;  /*!< DMA high interrupt flag clear register, Address offset: 0x0C */
	DMA_Stream_t StreamID[8] ;
	
}DMA_t;

/***********************************************************************************
	-----> Macros
			*  Base_Address DMA_1				
			*  Base_Address DMA_2
************************************************************************************/
#define DMA_1_BASS_ADDRESS   0x40026000 
#define DMA_2_BASS_ADDRESS   0x40026400 /* M T M --> Is plus than DMA_1*/
/***********************************************************************************
	-----> Macros
			* 				
			* 
************************************************************************************/
#define DMA_1                  ((DMA_t      *)  (DMA_1_BASS_ADDRESS))
#define DMA_2                  ((DMA_t      *)  (DMA_2_BASS_ADDRESS))

#endif //_DMA_PRIVATE_H_
