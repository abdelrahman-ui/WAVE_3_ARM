/***********************************************************************************************
 ***************************  - SPI_program.c				 		 ***************************
***************************   - Created: 2/22/2021					 ****************************
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
		#include "SPI_private.h"
		#include "SPI_interface.h"
		#include "SPI_config.h"
/*****************************************/

/************** INCLUDE HALL**************/
			

/*****************************************/

/************** INCLUDEAPP***************/


/*****************************************/






/* static */void (*MSPI1_CallBack) (void);




/********************************************************** Start_FUNCTION  **********************************************************/

void MSPI_VidInit ( void ){
	
#if   MSP1_STATUS == MSPI_ENABLE
/*****************       Clock ( phase & polarity )       *****************/
	#if		MSPI1_CLOCK_MODE == MSPI_MODE0

		CLR_BIT(/*MSPI_NUM*/ MSPI1 -> CR1 , CPHA  ); CLR_BIT( MSPI1 -> CR1 , CPOL );

	#elif	MSPI1_CLOCK_MODE == MSPI_MODE1

		SET_BIT(/*MSPI_NUM*/ MSPI1 -> CR1 , CPHA ); CLR_BIT( MSPI1 -> CR1 , CPOL );

	#elif	MSPI1_CLOCK_MODE == MSPI_MODE2

		CLR_BIT(/*MSPI_NUM*/  MSPI1 -> CR1 , CPHA ); SET_BIT( MSPI1 -> CR1 , CPOL );

	#elif	MSPI1_CLOCK_MODE == MSPI_MODE3

		SET_BIT(/*MSPI_NUM*/  MSPI1 -> CR1 , CPHA ); SET_BIT( MSPI1 -> CR1 , CPOL );

	#endif
/*****************       Master selection       *****************/
	#if    MSPI1_MASTER_SLAVE == MSPI_MASTER

		SET_BIT(/*MSPI_NUM*/ MSPI1 -> CR1 , MSTR );

	#elif  MSPI1_MASTER_SLAVE == MSPI_SLAVE

		CLR_BIT(/*MSPI_NUM*/  MSPI1 -> CR1 , MSTR );

	#endif
/*****************       Frame format       *****************/
	#if   MSPI1_DATA_ORDER == MSPI_MSB_FIRST

		CLR_BIT(/*MSPI_NUM*/  MSPI1 -> CR1 , LSBFIRST );

	#elif MSPI1_DATA_ORDER == MSPI_LSB_FIRST

		SET_BIT(/*MSPI_NUM*/  MSPI1 -> CR1 , LSBFIRST );

	#endif
/*****************       Software slave management       *****************/
	#if   MSPI1_SSM_MANAGE  == SSM_SWITCH_CLOSE

		CLR_BIT(/*MSPI_NUM*/  MSPI1 -> CR1 , SSM );

	#elif MSPI1_SSM_MANAGE == SSM_SWITCH_OPEN
       /* As master pin not connect out */
		SET_BIT(/*MSPI_NUM*/  MSPI1 -> CR1 , SSM );

	#endif
/*****************       SSI VCC OR GROUND only when SET ssm    *****************/
	#if   MSPI_SSI_MODE  == SSI_GROUND

		CLR_BIT(/*MSPI_NUM*/  MSPI1 -> CR1 , SSI );

	#elif MSPI_SSI_MODE == SSI_VCC

		SET_BIT(/*MSPI_NUM*/  MSPI1 -> CR1 , SSI  );

	#endif
/*****************       Data Size        *****************/
   #if   MSPI1_DATA_SIZE == MSPI_8BIT_DATA

		CLR_BIT(/*MSPI_NUM*/  MSPI1 -> CR1 , DFF  );

	#elif MSPI1_DATA_SIZE == MSPI_16BIT_DATA

		SET_BIT(/*MSPI_NUM*/  MSPI1 -> CR1 , DFF  );

	#endif
/*****************       Interrput enable | disabled      *****************/
	#if   MSPI1_INT_STATUS == MSPI_INT_DISABLE

		/*MSPI_NUM*/ MSPI1 -> CR2 = 0 ;

	#elif MSPI1_INT_STATUS == MSPI_TXE_INT_ENABLE

		SET_BIT(/*MSPI_NUM*/  MSPI1 -> CR2 , TXEIE );

	#elif MSPI1_INT_STATUS == MSPI_RXNE_INT_ENABLE

		SET_BIT(/*MSPI_NUM*/ MSPI1 -> CR2 , RXNEIE );

	#endif
/*****************       Baud rate control      *****************/
	/* 1111 1111 1000 0111*/
	/*MSPI_NUM*/ MSPI1 -> CR1 &= 0xFFC7 ;

	/*MSPI_NUM*/ MSPI1 -> CR1 |= ( MSPI1_PRESCALLER << 3 ) ;
/*****************       SPI enable       *****************/
	SET_BIT(/*MSPI_NUM*/  MSPI1 -> CR1 , SPE );
/*****************       SPI disabled       *****************/
#elif MSP1_STATUS == MSPI_DISABLE
CLR_BIT( /*MSPI_NUM*/ MSPI1 -> CR1 , SPE );

#endif
}

/*********************************************************** END_ FUNCTION   *********************************************************/




/********************************************************** Start_FUNCTION  **********************************************************/

u8 MSPI1_VidSendDataU8 ( u8 Copy_u8Data ){
                 /* Write data in DR */
	/*MSPI_NUM*/ MSPI1 -> DR = Copy_u8Data;
      /* Wait BSY : SPIis busy in communication or Tx buffer is not empty
             This flag is set and cleared by hardware */
	while ( GET_BIT( /*MSPI_NUM*/ MSPI1 -> SR , BSY ) == 1 );
     /* Return data From DR */
	return (u8)/*MSPI_NUM*/  MSPI1 -> DR ;

}

/*********************************************************** END_ FUNCTION   *********************************************************/


/********************************************************** Start_FUNCTION  **********************************************************/

void MSPI1_VidSetCallBack( void (*ptr) (void) ){

	MSPI1_CallBack = ptr;

}


/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/

void SPI1_IRQHandler(void){

	MSPI1_CallBack();

}
/*********************************************************** END_ FUNCTION   *********************************************************/
