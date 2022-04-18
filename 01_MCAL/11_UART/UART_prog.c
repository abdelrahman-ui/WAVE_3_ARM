/*=======================================================================================
==========================  - UART_program.c				 ============================
==========================  - Created: 3/22/2022			 ============================
==========================  - Author: Abdelrahman_Magdy      ============================
==========================  - Version : _1_				     ============================
==========================  - Note :
									*-
									*-
=======================================================================================*/ 


/*=======================================================================================
============================   The Foundation Of Function   ============================= 
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "STD_TYPES.h"
		 #include "BIT_MATH.h"
/*======================================*/	 
/*===========  INCLUDE MCAL  ===========*/
		#include "UART_private.h"
		#include "UART_interface.h"
		#include "UART_config.h"
/*======================================*/	
/*===========  INCLUDE HAL   ===========*/
			

/*======================================*/	

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/	



/* */
void (*MUSART1_CallBack)(void);

/*====================================================   Start_FUNCTION   ====================================================*/
/******************************************************************************
* \Syntax          : void MUART_vInit(void)      
* \Description     :                                        
* \Sync\Async      :                              
* \Reentrancy      :                          
* \Parameters (in) :                     
* \Parameters (out):                                                       
* \Return value:   :                                  
*******************************************************************************/
void MUART_vInit(void){

	/*===========	UART_1	 ===========*/
#if (UART1_USED == U_ENABLE)
	/*1)   */
	UART1_REG->CR1.SBK = UART1_SEND_BREAK;
	/*2)  */
	UART1_REG->CR1.RE = UART1_RECEIVER;
	/*3)  */
	UART1_REG->CR1.TE = UART1_TRANSMITTER;
	/*4)  */
	UART1_REG->CR1.RXNEIE = UART1_RX_INT;
	/*5)  */
	UART1_REG->CR1.TCIE = UART1_T_COMP_INT;
	/*6)  */
	UART1_REG->CR1.PCE = UART1_PARITY_ENABLE;
	/*7)  */
	UART1_REG->CR1.PS = UART1_PARITY_MODE;
	/*8)  */
	UART1_REG->CR1.M = UART1_WORD_LEN;
	/*9)  */
	UART1_REG->CR1.OVER8	= UART1_OVER_SAMPLING;
    /*10)  */
	UART1_REG->BRR = UART1_BUAD_RATE;
    /*11)  */
	UART1_REG->CR2 |= (UART1_STOP_BITS << 12);
#endif

   /*===========	UART_2	 ===========*/
#if (UART2_USED == U_ENABLE)
	/*1)   */
	UART2_REG->CR1.SBK = UART1_SEND_BREAK;
	/*2)  */
	UART2_REG->CR1.RE = UART1_RECEIVER;
	/*3)  */
	UART2_REG->CR1.TE = UART1_TRANSMITTER;
	/*4)  */
	UART2_REG->CR1.RXNEIE = UART1_RX_INT;
	/*5)  */
	UART2_REG->CR1.TCIE = UART1_T_COMP_INT;
	/*6)  */
	UART2_REG->CR1.PCE = UART1_PARITY_ENABLE;
	/*7)  */
	UART2_REG->CR1.PS = UART1_PARITY_MODE;
	/*8)  */
	UART2_REG->CR1.M = UART1_WORD_LEN;
	/*9)  */
	UART2_REG->CR1.OVER8	= UART1_OVER_SAMPLING;
    /*10)  */
	UART2_REG->BRR = UART1_BUAD_RATE;
    /*11)  */
	UART2_REG->CR2 |= (UART1_STOP_BITS << 12);
#endif

   /*===========	UART_6	 ===========*/
#if (UART6_USED == U_ENABLE)
	/*1)   */
	UART6_REG->CR1.SBK = UART1_SEND_BREAK;
	/*2)  */
	UART6_REG->CR1.RE = UART1_RECEIVER;
	/*3)  */
	UART6_REG->CR1.TE = UART1_TRANSMITTER;
	/*4)  */
	UART6_REG->CR1.RXNEIE = UART1_RX_INT;
	/*5)  */
	UART6_REG->CR1.TCIE = UART1_T_COMP_INT;
	/*6)  */
	UART6_REG->CR1.PCE = UART1_PARITY_ENABLE;
	/*7)  */
	UART6_REG->CR1.PS = UART1_PARITY_MODE;
	/*8)  */
	UART6_REG->CR1.M = UART1_WORD_LEN;
	/*9)  */
	UART6_REG->CR1.OVER8	= UART1_OVER_SAMPLING;
    /*10)  */
	UART6_REG->BRR = UART1_BUAD_RATE;
    /*11)  */
	UART6_REG->CR2 |= (UART1_STOP_BITS << 12);

#endif
}

/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function :
*
*/
void MUART_vEnable(u8 copy_u8Index){
	/*1) */
	switch(copy_u8Index){
		/* */
		case 1: UART1_REG -> CR1.UE = 1; break;
		/* */
		case 2: UART2_REG -> CR1.UE = 1; break;
		/* */
		case 6: UART6_REG -> CR1.UE = 1; break;
		/* */
		default : /* */ break;
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function :
*
*/
void MUART_vDisable(u8 copy_u8Index){
	/* */
	switch (copy_u8Index)
	{   /* */
		case 1: UART1_REG -> CR1.UE = 0; break;
		/* */
		case 2: UART2_REG -> CR1.UE = 0; break;
		/* */
		case 6: UART6_REG -> CR1.UE = 0; break;
		/* */
		default : /* */ break;
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function :
*
*/
void MUART_u8SendData(u8 copy_u8Index, u8* copy_u8Data, u8 copy_u8Len){
     /* */
	UART_REG uhandler = MUART_GetHandler(copy_u8Index);
	/* */
	for(u8 counter = 0; counter < copy_u8Len; counter++){
		uhandler ->DR = copy_u8Data[counter];
		/* */
		while(!GET_BIT(uhandler->SR, 6));
	}
	 
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function :
*
*/
u8 MUART_u8ReadData(u8 copy_u8Index){
	/* */
	UART_REG uhandler = MUART_GetHandler(copy_u8Index);
	/* */
	return (u8) uhandler->DR;
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function :
*
*/
UART_REG MUART_GetHandler(u8 copy_u8Index){
	/* */
	UART_REG L_handle= (UART_REG) UART1_BASE_ADDRESS;
	switch (copy_u8Index)
	{   /* */
		case 1: L_handle =  (UART_REG) UART1_BASE_ADDRESS; break;
		/* */
		case 2: L_handle =  (UART_REG) UART2_BASE_ADDRESS; break;
		/* */
		case 6: L_handle =  (UART_REG) UART6_BASE_ADDRESS; break;
		default : /* */ break;
	}
	return L_handle;
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function :
*
*/

void MUSART1_VidSetCallBack( void (*ptr) (void) ){
    /* */
	MUSART1_CallBack = ptr ;

}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function :
*
*/
void USART1_IRQHandler(void){
    /* */
	UART1_REG -> SR = 0 ;
	/* */
	MUSART1_CallBack();

}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void MUART6_vSendChar (u8 Copy_u8Char)
{
	/*********** STEPS FOLLOWED *************

	1. Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this
		 for each data to be transmitted in case of single buffer.
	2. After writing the last data into the USART_DR register, wait until TC=1. This indicates
		 that the transmission of the last frame is complete. This is required for instance when
		 the USART is disabled or enters the Halt mode to avoid corrupting the last transmission.

	****************************************/

	UART6_REG->DR = Copy_u8Char;   // Load the Data
	while (!(UART6_REG->SR & (1<<6)));  // Wait for TC to SET.. This indicates that the data has been transmitted
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void MUART6_Send_String( char *string)
{
      short i =0;
	 while(string[i]!='\0')
	 {
		 MUART6_vSendChar (string[i]);
			i++;
	 }
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
u8  MUART6_u8Receive(void)
{
	//make sure you have data
	while(!(UART6_REG->SR&(1<<5)));
	return (u8) UART6_REG->DR;
}
/*====================================================   END_ FUNCTION   ====================================================*/

