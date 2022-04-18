



#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_


/* USART1_Configuration */

#define USART1_STATUS            USART1_ENABLE      /*Enable or disable */

#define USART1_BAUD_RATE         0x0683             /* From table */

#define USART1_WORD_LENGTH       _8BIT_WORD_LENGTH  /* 8 bit or 9 bit */

#define USART1_PARITY            PARITY_DISABLE     /*even or odd*/

#define USART1_INTERRUPT         INT_DISABLE

#define USART1_TRANSMITTER       TRANSMITTER_ENABLE

#define USART1_RECEIVER          RECEIVER_ENABLE


#define USART1_STOP_BITS         TWO_STOP_BIT


#define OVER_SAMPE_MODE         SMAPLE_MODE_16





#endif /* USART_CONFIG_H_ */