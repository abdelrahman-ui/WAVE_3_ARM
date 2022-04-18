/******************************************************************************************
 ***************************  - UART_interface.h	 		 	 ***************************
***************************   - Created: 2/24/2022				***************************
***************************   - Author: Abdelrahman_Magdy		***************************
***************************   - Version : _1_				    ***************************
***************************   - Note :
									*-
									*-
 *******************************************************************************************/ 

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

#ifndef USART_REG_H_
#define USART_REG_H_

/************** INCLUDE LIB **************/
#include "STD_TYPES.h"
/***  DEFINE FOR CR1 REG BIT     ***/
#define SBK       0U      /*!<  Send break This bit set is used to send break characters. It can be set and cleared by software. It should be set by software, and will be reset by hardware during the stop bit of break. */
#define RWU       1U      /*!<  Receiver wakeup This bit determines if the USART is in mute mode or not. It is set and cleared by software and can be cleared by hardware when a wakeup sequence is recognized. */
#define RE        2U      /*!<  Receiver enable This bit enables the receiver. It is set and cleared by software   */
#define TE        3U      /*!<  Transmitter enable This bit enables the transmitter. It is set and cleared by software.    */
#define IDLEIE    4U      /*!<  IDLE interrupt enable This bit is set and cleared by software.  */
#define RXNEIE    5U      /*!<  RXNE interrupt enable This bit is set and cleared by software    */
#define TCIE      6U      /*!<  Transmission complete interrupt enable This bit is set and cleared by software.    */
#define TXEIE     7U      /*!<  TXE interrupt enable This bit is set and cleared by software.   */
#define PEIE      8U      /*!<  PE interrupt enable This bit is set and cleared by software  */
#define PS        9U      /*!<  Parity selection This bit selects the odd or even parity when the parity generation/detection is enabled (PCEbit set). It is set and cleared by software. The parity will be selected after the current byte   */
#define PCE       10U    /*!<  Parity control enable This bit selects the hardware parity control (generation and detection)   */
#define WAKE      11U     /*!<  Wakeup method This bit determines the USART wakeup method, it is set or cleared by software.    */
#define M         12U     /*!<  Word length This bit determines the word length. It is set or cleared by software.   */
#define UE        13U     /*!<  USART enable When this bit is cleared, the USART prescalers and outputs are stopped and the end of the current byte transfer in order to reduce power consumption. This bit is set and cleared by software*/
#define OVER8     15U     /*!<  Oversampling mode    */

/***********************************************************************************
-----> STRUCT Register map for UART0 peripheral (UARTx)
************************************************************************************/
typedef struct{

	volatile u32 SR;    /*!< USART Status register,                   Address offset: 0x00 */
	volatile u32 DR;    /*!< USART Data register,                     Address offset: 0x04 */
	volatile u32 BRR;   /*!< USART Baud rate register,                Address offset: 0x08 */
	volatile u32 CR1;   /*!< USART Control register 1,                Address offset: 0x0C */
	volatile u32 CR2;   /*!< USART Control register 2,                Address offset: 0x10 */
	volatile u32 CR3;   /*!< USART Control register 3,                Address offset: 0x14 */
	volatile u32 GTPR;  /*!< USART Guard time and prescaler register, Address offset: 0x18 */
}USART_t;

/***********************************************************************************
	-----> Macros
			*  From Memory Map At Referance Manual Get 
										- Base_Address OF (6)UART
										- Bus OF UART 
************************************************************************************/

#define UART_1_BASE_ADDRESS	  0x40013800	/*!< - UART_1_BASE_ADDRESS , - BUS :   , - RCC_NUM : */  
#define UART_2_BASE_ADDRESS	  0x40004400	/*!< - UART_2_BASE_ADDRESS , - BUS :   , - RCC_NUM : */  
#define UART_3_BASE_ADDRESS	  0x40004800	/*!< - UART_3_BASE_ADDRESS , - BUS :   , - RCC_NUM : */  
#define UART_4_BASE_ADDRESS	  0x40004C00	/*!< - UART_4_BASE_ADDRESS , - BUS :   , - RCC_NUM : */  
#define UART_5_BASE_ADDRESS	  0x40005000	/*!< - UART_5_BASE_ADDRESS , - BUS :   , - RCC_NUM : */  
#define UART_6_BASE_ADDRESS	  0x40011400	/*!< - UART_6_BASE_ADDRESS , - BUS :   , - RCC_NUM : */  

/***********************************************************************************
*     --> Pointer To STRUCT From UARTx
************************************************************************************/
#define MUSART1 ( ( volatile USART_t * ) UART_1_BASE_ADDRESS ) /*!< MUSART1  is Pointer To STRUCT From USART_t  */ 
#define MUSART2 ( ( volatile USART_t * ) UART_2_BASE_ADDRESS ) /*!< MUSART2  is Pointer To STRUCT From USART_t  */ 
#define MUSART3 ( ( volatile USART_t * ) UART_3_BASE_ADDRESS ) /*!< MUSART3  is Pointer To STRUCT From USART_t  */ 
#define MUART4  ( ( volatile USART_t * ) UART_4_BASE_ADDRESS ) /*!< MUART4   is Pointer To STRUCT From USART_t  */ 
#define MUART5  ( ( volatile USART_t * ) UART_5_BASE_ADDRESS ) /*!< MUART5   is Pointer To STRUCT From USART_t  */ 
#define MUART6  ( ( volatile USART_t * ) UART_6_BASE_ADDRESS ) /*!< MUART6   is Pointer To STRUCT From USART_t  */ 
#endif /* USART_REG_H_ */

/*************************************************************************************
*******************           End of guard of file  	  	       *******************
*************************************************************************************/ 