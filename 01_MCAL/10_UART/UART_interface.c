









#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_




#define USART1_DISABLE          0U
#define USART1_ENABLE           1U

#define _8BIT_WORD_LENGTH       0U
#define _9BIT_WORD_LENGTH       1U

#define PARITY_DISABLE          0U
#define EVEN_PARITY             1U
#define ODD_PARITY              2U

#define INT_DISABLE             0U
#define TXE_INT_ENABLE          1U
#define TCE_INT_ENABLE          3U
#define RXNE_INT_ENABLE         5U

#define TRANSMITTER_DISABLE     0U
#define TRANSMITTER_ENABLE      1U

#define RECEIVER_DISBLE         0U
#define RECEIVER_ENABLE         1U

#define ONE_STOP_BIT            0U
#define HALF_STOP_BIT           1U
#define TWO_STOP_BIT            2U
#define ONE_AND_HALF_STOP_BIT   3U

#define SMAPLE_MODE_16          0U
#define SMAPLE_MODE_8           1U


void MUSART_vInit               ( void                ) ;
void MUSART1_vSendCharSync      ( u8 Copy_u8Char      ) ;
void MUSART1_vSendStringSynch   ( u8 * Copy_ptrString ) ;
u8   MUSART1_u8RecCharSynch     ( void                ) ;
u8 * MUSART1_PtrReadStringSynch ( void                ) ;
void MUSART1_vdSetCallBack      ( void (*ptr) (void)  ) ;
u8 UART1_u8GetChar (void);
void UART1_vSendChar (u8 Copy_u8Char);








#endif /* USART_INTERFACE_H_ */
