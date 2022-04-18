/***********************************************************************************************
 ***************************  - SPI_program.c				 		 ***************************
***************************   - Created: 2/24/2021					 ****************************
***************************   - Author : Abdelrahman_Magdy			 ****************************
***************************   - Version: _1_				 		 ****************************
***************************   - Note :
									*-
									*-
 **************************************************************************************/ 


/****************************************************************************************
***************************   The Foundation Of Function   ***************************** 
****************************************************************************************/


/************** INCLUDE LIB **************/
	
		 #include "STD_TYPES.h"
		 #include "BIT_MATH.h"
/*****************************************/	 

/************** INCLUDE MCAL**************/
		#include "UART_private.h"
		#include "UART_interface.h"
		#include "UART_config.h"
/*****************************************/

/************** INCLUDE HALL**************/
			

/*****************************************/

/************** INCLUDEAPP***************/


/*****************************************/



/* */
void (*MUSART1_CallBack)(void);


/********************************************************** Start_FUNCTION  **********************************************************/
void MUSART_VidInit ( void ){
	
	/*u32 LOC_u64Mantissa = ( F_CPU ) / ( 16 * USART1_BAUD_RATE ) ;

	u32 LOC_u64Fraction = ( ( ( F_CPU * 100 ) / ( 16 * USART1_BAUD_RATE )  ) % 100 ) * 16 ;

	if( LOC_u64Fraction > 1500 ){ LOC_u64Mantissa += 1 ; LOC_u64Fraction  = 0 ; }*/
	
     /* -if EN clear all flag from SR */
	#if USART1_STATUS == USART1_ENABLE
         /* 1-if EN clear all flag from SR */
		MUSART1 -> SR = 0 ;
         /* 2-Bit word lenght 8 | 9 */
		#if   USART1_WORD_LENGTH == _8BIT_WORD_LENGTH
            
					CLR_BIT( MUSART1 -> CR1 , M   );

		#elif USART1_WORD_LENGTH == _9BIT_WORD_LENGTH

					SET_BIT( MUSART1 -> CR1 , M  );

		#endif
/**********************************************************************************************/
         /* 3-Parity if used or not */
		#if   USART1_PARITY == PARITY_DISABLE

					CLR_BIT( MUSART1 -> CR1 , PCE: );

		#elif USART1_PARITY == EVEN_PARITY
					/* Parity control enabled */
					SET_BIT( MUSART1 -> CR1 , PCE: );
					/*  Even parity  */
					CLR_BIT( MUSART1 -> CR1 , PS);

		#elif USART1_PARITY == ODD_PARITY
                    /* Parity control enabled */
					SET_BIT( MUSART1 -> CR1 , PCE: );
					/*  Odd parity  */
					SET_BIT( MUSART1 -> CR1 , PS );

		#endif
/**********************************************************************************************/
          /* 4-To disable INT or EN (TXE , RXNE ,TC) */
		#if  USART1_INTERRUPT == INT_DISABLE

					CLR_BIT( MUSART1 -> CR1 , RXNEIE: );
					CLR_BIT( MUSART1 -> CR1 , TCIE );
					CLR_BIT( MUSART1 -> CR1 , TXEIE );

		#elif USART1_INTERRUPT == TXE_INT_ENABLE

					SET_BIT( MUSART1 -> CR1 , TXEIE );

		#elif USART1_INTERRUPT == TCE_INT_ENABLE

					SET_BIT( MUSART1 -> CR1 , TCIE );

		#elif USART1_INTERRUPT == RXNE_INT_ENABLE

					SET_BIT( MUSART1 -> CR1 , 5 RXNEIE: );

		#endif
/************************************************************************/
         /* 5-ENABLE OR DISABLE tx */
		#if   USART1_TRANSMITTER == TRANSMITTER_ENABLE

					SET_BIT( MUSART1 -> CR1 , TE );

		#elif USART1_TRANSMITTER == TRANSMITTER_DISABLE

					CLR_BIT( MUSART1 -> CR1 , TE );

		#endif
          /* 6-ENABLE OR DISABLE rx */
		#if   USART1_RECEIVER == RECEIVER_ENABLE

					SET_BIT( MUSART1 -> CR1 , RE );

		#elif USART1_RECEIVER == RECEIVER_DISBLE

					CLR_BIT( MUSART1 -> CR1 , RE );

		#endif
/************************************************************************/
          /* 7-The Num of Stop Bit */
		#if   USART1_STOP_BITS == ONE_STOP_BIT

					CLR_BIT( MUSART1 -> CR2 , 12 ); CLR_BIT( MUSART1 -> CR2 , 13 );

		#elif USART1_STOP_BITS == HALF_STOP_BIT

					SET_BIT( MUSART1 -> CR2 , 12 ); CLR_BIT( MUSART1 -> CR2 , 13 );

		#elif USART1_STOP_BITS == TWO_STOP_BIT

					CLR_BIT( MUSART1 -> CR2 , 12 ); SET_BIT( MUSART1 -> CR2 , 13 );

		#elif USART1_STOP_BITS == ONE_AND_HALF_STOP_BIT

					SET_BIT( MUSART1 -> CR2 , 12 ); SET_BIT( MUSART1 -> CR2 , 13 );


		#endif
	/************************************************************************/
	#if   OVER_SAMPE_MODE == SMAPLE_MODE_16
	   
				CLR_BIT( MUSART1 -> CR1 , OVER8);
		   
	#elif  OVER_SAMPE_MODE == SMAPLE_MODE_8
	            
				SET_BIT( MUSART1 -> CR1 , OVER8);
	
	#endif

	/************************************************************************/
         /* 8-Buad Rate in BRR*/
		MUSART1 -> BRR = USART1_BAUD_RATE ;
		//( LOC_u64Mantissa << 4  ) | ( LOC_u64Fraction / 100 ) ;
	/************************************************************************/
		 /* 9-Enable Uart */
		SET_BIT( MUSART1 -> CR1 , 13 );
/**************************************************************************************/
    /* Disable Uart */
	#elif USART1_STATUS == USART1_DISABLE
		CLR_BIT( MUSART1 -> CR1 , 13 );

	#endif

}
/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/

void MUSART1_VidSendCharSync ( u8 Copy_u8Char ){
	/*********** STEPS FOLLOWED *************
	
	1. Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this
		 for each data to be transmitted in case of single buffer.
	2. After writing the last data into the USART_DR register, wait until TC=1. This indicates
		 that the transmission of the last frame is complete. This is required for instance when
		 the USART is disabled or enters the Halt mode to avoid corrupting the last transmission.
	3. Clear the flag of transmit Complite 	 
	
	****************************************/

	 MUSART1 -> DR = Copy_u8Char ;   // LOad the Data
	while (!(USART2->SR & (1<<6)));  // Wait for TC to SET.. This indicates that the data has been transmitted
	CLR_BIT( MUSART1 -> SR , 6 );    // Clear the flag of transmit Complite 
}

/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/
void MUSART1_VidSendStringSynch ( u8 * Copy_ptrString ){
/* u8 var to ++ ptr */
	u8 LOC_u8Iterator = 0 ;
/* while value not = '\0' */  
	while ( Copy_ptrString[ LOC_u8Iterator ] != '\0' ){
/* send data of ptr[u8 var] */
		MUSART1_VidSendCharSync( Copy_ptrString[ LOC_u8Iterator ] );
/* var ++*/		
		LOC_u8Iterator++ ;

	}

}
/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/


u8 MUSART1_u8RecCharSynch ( void ){
	/*********** STEPS FOLLOWED *************
	
	1. Wait for the RXNE bit to set. It indicates that the data has been received and can be read.
	2. Read the data from USART_DR  Register. This also clears the RXNE bit
	
	****************************************/
	u8 Temp=0U;
	
	while (!(MUSART1->SR & (1<<5)));  // Wait for RXNE to SET.. This indicates that the data has been Received
	Temp = MUSART1->DR;  // Read the data. 
	return Temp;
}


/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/
void MUSART1_VidSetCallBack( void (*ptr) (void) ){

	MUSART1_CallBack = ptr ;

}
/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/
void USART1_IRQHandler(void){

	MUSART1 -> SR = 0 ;
	MUSART1_CallBack();

}
/*********************************************************** END_ FUNCTION   *********************************************************/


