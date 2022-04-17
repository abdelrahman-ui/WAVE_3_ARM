











#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H


#define SPI_1_BASE_ADDRESS		0x40013000
#define SPI_2_BASE_ADDRESS		0x40003800
#define SPI_3_BASE_ADDRESS		0x40003C00
#define SPI_4_BASE_ADDRESS		0x40013400



/******************************/
#define _CR1_CPHA               0U
#define _CR1_CPOL				1U
#define _CR1_MSTR               2U
#define _CR1_BR                 3U
#define _CR1_SPE                6U
#define _CR1_LSBFRISRT          7U
#define _CR1_SSI                8U
#define _CR1_SSM                9U
#define _CR1_RXONLY             10U
#define _CR1_DFF                11U
#define _CR1_CRCNEXT            12U
#define _CR1_CRCEN              13U
#define _CR1_BIDIOE             14U  
#define _CR1_BIDIMODE           15U   








typedef struct
{
	
volatile u32 CR1    ;   
volatile u32 CR2    ; 
volatile u32 SR     ; 	
volatile u32 DR 	;
volatile u32 CRCPR 	;
volatile u32 RXCRCR	;
volatile u32 TXCRCR ;
volatile u32 I2SCFGR;
volatile u32 I2SPR  ;
	
}SPI_t;


#define SPI_1         ((SPI_t*)(SPI_1_BASE_ADDRESS))
#define SPI_2         ((SPI_t*)(SPI_2_BASE_ADDRESS))
#define SPI_3         ((SPI_t*)(SPI_3_BASE_ADDRESS))
#define SPI_4         ((SPI_t*)(SPI_4_BASE_ADDRESS))










#endif