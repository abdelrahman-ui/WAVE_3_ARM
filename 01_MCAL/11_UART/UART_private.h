
/*==============================================================================================
===============================   - UART_interface.h			 ===============================
===============================   - Created:3/22/2022			 ===============================
===============================   - Author: Abdelrahman_Magdy    ===============================
===============================   - Version : _1_				 ===============================
===============================   - Note :
									     *-
									     *-
=================================================================================================*/ 

/*===============================================================================================
*	 - Developer can't Edit in it    
*	  - Register _ Defination		
*	  - Design : 
					- #define	:	NO
					- Union		:	NO
					- Struct	:	YES
					
===================================================================================================*/

/*=====================================================================================
===================    guard of file will call on time in .c	    ===================
=======================================================================================*/ 
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#include "00_LIB/STD_types.h"
/*=================================================================================
	-----> Macros
			*  From Memory Map At Referance Manual Get 
										- Base_Address OF (6)UART
										- Bus OF UART 
=================================================================================*/
#define UART1_BASE_ADDRESS    0x40011000     /*!< - UART_1_BASE_ADDRESS , - BUS :   , - RCC_NUM : */ 
#define UART2_BASE_ADDRESS    0x40004400     /*!< - UART_2_BASE_ADDRESS , - BUS :   , - RCC_NUM : */ 
#define UART6_BASE_ADDRESS    0x40011400     /*!< - UART_6_BASE_ADDRESS , - BUS :   , - RCC_NUM : */ 

/*=================================================================================
-----> Bit 
=================================================================================*/                                                                                        
typedef struct{                              
    u32 SBK       :1;		/*!<  Send break This bit set is used to send break characters. It can be set and cleared by software. It should be set by software, and will be reset by hardware during the stop bit of break. */
    u32 RWU       :1;		/*!<  Receiver wakeup This bit determines if the USART is in mute mode or not. It is set and cleared by software and can be cleared by hardware when a wakeup sequence is recognized. */
    u32 RE        :1;		/*!<  Receiver enable This bit enables the receiver. It is set and cleared by software   */
    u32 TE        :1;		/*!<  Transmitter enable This bit enables the transmitter. It is set and cleared by software.    */
    u32 IDLEIE    :1;		/*!<  IDLE interrupt enable This bit is set and cleared by software.  */
    u32 RXNEIE    :1;		/*!<  RXNE interrupt enable This bit is set and cleared by software    */
    u32 TCIE      :1;		/*!<  Transmission complete interrupt enable This bit is set and cleared by software.    */
    u32 TXEIE     :1;		/*!<  TXE interrupt enable This bit is set and cleared by software.   */
    u32 PEIE      :1;		/*!<  PE interrupt enable This bit is set and cleared by software  */
    u32 PS        :1;		/*!<  Parity selection This bit selects the odd or even parity when the parity generation/detection is enabled (PCEbit set). It is set and cleared by software. The parity will be selected after the current byte   */
    u32 PCE       :1;		/*!<  Parity control enable This bit selects the hardware parity control (generation and detection)   */
    u32 WAKE      :1;		/*!<  Wakeup method This bit determines the USART wakeup method, it is set or cleared by software.    */
    u32 M         :1;		/*!<  Word length This bit determines the word length. It is set or cleared by software.   */
    u32 UE        :1;		/*!<  USART enable When this bit is cleared, the USART prescalers and outputs are stopped and the end of the current byte transfer in order to reduce power consumption. This bit is set and cleared by software*/
    u32 RESERVED  :1;		
    u32 OVER8     :1;		/*!<  Oversampling mode    */
    u32 RESERVED2 :16;
}UART_CR1;
/*=================================================================================
-----> STRUCT Register map for UART0 peripheral (UARTx)
=================================================================================*/ 
typedef struct{
    
    u32 SR;           /*!< USART Status register,                   Address offset: 0x00 */
    u32 DR;           /*!< USART Data register,                     Address offset: 0x04 */
    u32 BRR;          /*!< USART Baud rate register,                Address offset: 0x08 */
    UART_CR1 CR1;     /*!< USART Control register 1,                Address offset: 0x0C */
    u32 CR2;          /*!< USART Control register 2,                Address offset: 0x10 */
    u32 CR3;          /*!< USART Control register 3,                Address offset: 0x14 */
    u32 GTPR;         /*!< USART Guard time and prescaler register, Address offset: 0x18 */
}UART_t;

typedef    volatile UART_t* UART_REG ;
/*=================================================================================
*     --> Pointer To STRUCT From UARTx
=================================================================================*/
#define     UART1_REG    ((volatile UART_t*)(UART1_BASE_ADDRESS))    /*!< MUSART1  is Pointer To STRUCT From USART_t  */ 
#define     UART2_REG    ((volatile UART_t*)(UART2_BASE_ADDRESS))    /*!< MUSART2  is Pointer To STRUCT From USART_t  */ 
#define     UART6_REG    ((volatile UART_t*)(UART6_BASE_ADDRESS))    /*!< MUART6   is Pointer To STRUCT From USART_t  */ 

                                                             
#endif // UART_PRIVATE_H
/*=================================================================================
==================          End of guard of file  	  	       ====================
==================================================================================*/ 