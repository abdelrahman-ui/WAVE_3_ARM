
/***************************************************************************************
 *************************** - DMA_private.h				 ***************************
***************************   -Created: 6/25/2021			 ***************************
***************************   -Author: Abdelrahman_Magdy     ***************************
***************************   -Version : _1_				 ***************************
***************************   -Note :
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


#define DMA_1_BASS_ADDRESS   0x40026000 
#define DMA_2_BASS_ADDRESS   0x40026400 /* M T M*/

typedef struct 
{
 volatile u32 CR      ;
 volatile u32 NDTR    ;
 volatile u32 PAR     ;
 volatile u32 M0AR    ;
 volatile u32 M1AR    ;
 volatile u32 FCR     ;
		
}DMA_Stream_t ;


typedef struct{
	
	volatile u32 LISR        ;  
	volatile u32 HISR        ;
	volatile u32 LIFCR       ;
	volatile u32 HIFCR       ;
	DMA_Stream_t StreamID[8] ;
	
}DMA_t;



 
#define DMA_1                  ((DMA_t      *)  (DMA_1_BASS_ADDRESS))
#define DMA_2                  ((DMA_t      *)  (DMA_2_BASS_ADDRESS))




#endif //_DMA_PRIVATE_H_
