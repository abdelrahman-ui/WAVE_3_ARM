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
	
    while ( GET_BIT( /*MSPI_NUM*/ MSPI1 -> SR , BSY ) == 1 );             
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

u16 MSPI1_u16SendDataU16 ( u16 Copy_u16Data ){
                 /* Write data in DR */
	/*MSPI_NUM*/ MSPI1 -> DR = Copy_u16Data;
	while ( GET_BIT( /*MSPI_NUM*/ MSPI1 -> SR , BSY ) == 1 );
      /* Wait BSY : SPIis busy in communication or Tx buffer is not empty
             This flag is set and cleared by hardware */
	while ( GET_BIT( /*MSPI_NUM*/ MSPI1 -> SR , BSY ) == 1 );
     /* Return data From DR */
	return (u8)/*MSPI_NUM*/  MSPI1 -> DR ;

}
/*********************************************************** END_ FUNCTION   *********************************************************/


/********************************************************** Start_FUNCTION  **********************************************************/

void SPI_Transmit (u8 *data, int size)
{
	
	/************** STEPS TO FOLLOW *****************
	1. Wait for the TXE bit to set in the Status Register
	2. Write the data to the Data Register
	3. After the data has been transmitted, wait for the BSY bit to reset in Status Register
	4. Clear the Overrun flag by reading DR and SR
	************************************************/		
	
	int i=0;
	while (i<size)
	{
	   while (!((SPI1->SR)&(1<<1))) {};  // wait for TXE bit to set -> This will indicate that the buffer is empty
	   SPI1->DR = data[i];  // load the data into the Data Register
	   i++;
	}	
	
	SPI_Transmit (&address, 1);  // send address Transmit 1byte
	SPI_Receive (RxData, 6);  // receive 6 bytes data
	
/*During discontinuous communications, there is a 2 APB clock period delay between the
write operation to the SPI_DR register and BSY bit setting. As a consequence it is
mandatory to wait first until TXE is set and then until BSY is cleared after writing the last
data.
*/
	while (!((SPI1->SR)&(1<<1))) {};  // wait for TXE bit to set -> This will indicate that the buffer is empty
	while (((SPI1->SR)&(1<<7))) {};  // wait for BSY bit to Reset -> This will indicate that SPI is not busy in communication	
	
	//  Clear the Overrun flag by reading DR and SR
	uint8_t temp = SPI1->DR;
					temp = SPI1->SR;
	
}
/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/

void SPI_Receive (uint8_t *data, int size)
{
	/************** STEPS TO FOLLOW *****************
	1. Wait for the BSY bit to reset in Status Register
	2. Send some Dummy data before reading the DATA
	3. Wait for the RXNE bit to Set in the status Register
	4. Read data from Data Register
	************************************************/		

	while (size)
	{
		while (((SPI1->SR)&(1<<7))) {};  // wait for BSY bit to Reset -> This will indicate that SPI is not busy in communication
		SPI1->DR = 0;  // send dummy data
		while (!((SPI1->SR) &(1<<0))){};  // Wait for RXNE to set -> This will indicate that the Rx buffer is not empty
	  *data++ = (SPI1->DR);
		size--;
	}	
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
