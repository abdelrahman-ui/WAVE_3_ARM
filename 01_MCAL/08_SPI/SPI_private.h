


/***************************************************************************************
 ***************************  - SPI_private.h				  ***************************
***************************   - Created: 			  ***************************
***************************   - Author: Abdelrahman_Magdy     ***************************
***************************   - Version : _1_				  ***************************
***************************   - Note :
									  *-
									  *-
 **************************************************************************************/ 

/**************************************************************************************
*	 - Developer can't Edit in it    
*	  - Register _ Defination		
*	  - Design : 
					- #define	:	YES
					- Union		:	NO
					- Struct	:	YES
**************************************************************************************/

/*************************************************************************************
******************* guard of file will call on time in .c		   *******************
*************************************************************************************/ 


#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/***********************************************************************************
----->STRUCT
*  Register Map :SPI
************************************************************************************/

typedef struct {

	volatile u32 CR1     ;    /*!< SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */
	volatile u32 CR2     ;    /*!< SPI control register 2,                             Address offset: 0x04 */
	volatile u32 SR      ;    /*!< SPI status register,                                Address offset: 0x08 */
	volatile u32 DR      ;    /*!< SPI data register,                                  Address offset: 0x0C */
	volatile u32 CRCPR   ;    /*!< SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
	volatile u32 RXCRCR  ;    /*!< SPI RX CRC register (not used in I2S mode),         Address offset: 0x14 */
	volatile u32 TXCRCR  ;    /*!< SPI TX CRC register (not used in I2S mode),         Address offset: 0x18 */
	volatile u32 I2SCFGR ;    /*!< SPI_I2S configuration register,                     Address offset: 0x1C */
	volatile u32 I2SPR   ;    /*!< SPI_I2S prescaler register,                         Address offset: 0x20 */

}SPI_t;

/***********************************************************************************
	-----> Macros
			*  Base_Address SPI				
************************************************************************************/

#define SPI1_Bass_ADD         0x40013000
#define SPI2_Bass_ADD         0x40003800
#define SPI3_Bass_ADD         0x40003C00
#define SPI4_Bass_ADD         0x40013400

/***********************************************************************************
*     --> Pointer To STRUCT From SPI_t
************************************************************************************/

#define MSPI1		  ( ( volatile SPI_t* ) SPI1_Bass_ADD  )   
#define MSPI2         ( ( volatile SPI_t* ) SPI2_Bass_ADD  )     
#define MSPI3         ( ( volatile SPI_t* ) SPI3_Bass_ADD  )    
#define MSPI4         ( ( volatile SPI_t* ) SPI4_Bass_ADD  )    
  

/***********************************************************************************
	-----> Macros
			*  From Memory Map At Referance Manual Get 
										- Base_Address OF (4)SPI
										- Bus OF SPI 
************************************************************************************/
#define _SPI_1_BASE_ADDRESS    0x40013000      /*!< - SPI_1 Base_Address , - BUS : APB2  , - RCC_NUM : 12 */    
#define _SPI_2_BASE_ADDRESS    0x40003800      /*!< - SPI_2 Base_Address , - BUS : APB1  , - RCC_NUM : 14 */  
#define _SPI_3_BASE_ADDRESS    0x40003C00      /*!< - SPI_3 Base_Address , - BUS : APB1  , - RCC_NUM : 15 */  
#define _SPI_4_BASE_ADDRESS    0x40013400      /*!< - SPI_4 Base_Address , - BUS : APB2  , - RCC_NUM : 13 */  
/***********************************************************************************
*     --> Pointer To STRUCT From SPI_t
************************************************************************************/
#define _MSPI_1      (( _SPI_t   *) _SPI_1_BASE_ADDRESS) /*!< _MSPI_1  is Pointer To STRUCT From SPI_t  */  
#define _MSPI_2      (( _SPI_t   *) _SPI_2_BASE_ADDRESS) /*!< _MSPI_2  is Pointer To STRUCT From SPI_t  */  
#define _MSPI_3      (( _SPI_t   *) _SPI_3_BASE_ADDRESS) /*!< _MSPI_3  is Pointer To STRUCT From SPI_t  */  
#define _MSPI_4      (( _SPI_t   *) _SPI_4_BASE_ADDRESS) /*!< _MSPI_4  is Pointer To STRUCT From SPI_t  */  
/***********************************************************************************
-----> Macros
*  Register Map : SPI1_Register

************************************************************************************/
#define SPI1_CR1           (*((volatile)  u32*)(_SPI_1_BASE_ADDRESS+0x00)) /*!< SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */
#define SPI1_CR2           (*((volatile)  u32*)(_SPI_1_BASE_ADDRESS+0x04)) /*!< SPI control register 2,                             Address offset: 0x04 */
#define SPI1_SR            (*((volatile)  u32*)(_SPI_1_BASE_ADDRESS+0x08)) /*!< SPI status register,                                Address offset: 0x08 */
#define SPI1_DR            (*((volatile)  u32*)(_SPI_1_BASE_ADDRESS+0x0C)) /*!< SPI data register,                                  Address offset: 0x0C */
#define SPI1_CRCPR         (*((volatile)  u32*)(_SPI_1_BASE_ADDRESS+0x10)) /*!< SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
#define SPI1_RXCRCR        (*((volatile)  u32*)(_SPI_1_BASE_ADDRESS+0x14)) /*!< SPI RX CRC register (not used in I2S mode),         Address offset: 0x14 */
#define SPI1_TXCRCR        (*((volatile)  u32*)(_SPI_1_BASE_ADDRESS+0x18)) /*!< SPI TX CRC register (not used in I2S mode),         Address offset: 0x18 */
#define SPI1_I2SCFGR       (*((volatile)  u32*)(_SPI_1_BASE_ADDRESS+0x1C)) /*!< SPI_I2S configuration register,                     Address offset: 0x1C */
#define SPI1_I2SPR         (*((volatile)  u32*)(_SPI_1_BASE_ADDRESS+0x20)) /*!< SPI_I2S prescaler register,                         Address offset: 0x20 */
/***********************************************************************************
-----> Macros
*  Register Map : SPI2_Register

************************************************************************************/
#define SPI2_CR1           (*((volatile)  u32*)(_SPI_2_BASE_ADDRESS+0x00))/*!< SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */
#define SPI2_CR2           (*((volatile)  u32*)(_SPI_2_BASE_ADDRESS+0x04))/*!< SPI control register 2,                             Address offset: 0x04 */ 
#define SPI2_SR            (*((volatile)  u32*)(_SPI_2_BASE_ADDRESS+0x08))/*!< SPI status register,                                Address offset: 0x08 */
#define SPI2_DR            (*((volatile)  u32*)(_SPI_2_BASE_ADDRESS+0x0C))/*!< SPI data register,                                  Address offset: 0x0C */
#define SPI2_CRCPR         (*((volatile)  u32*)(_SPI_2_BASE_ADDRESS+0x10))/*!< SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
#define SPI2_RXCRCR        (*((volatile)  u32*)(_SPI_2_BASE_ADDRESS+0x14))/*!< SPI RX CRC register (not used in I2S mode),         Address offset: 0x14 */
#define SPI2_TXCRCR        (*((volatile)  u32*)(_SPI_2_BASE_ADDRESS+0x18))/*!< SPI TX CRC register (not used in I2S mode),         Address offset: 0x18 */
#define SPI2_I2SCFGR       (*((volatile)  u32*)(_SPI_2_BASE_ADDRESS+0x1C))/*!< SPI_I2S configuration register,                     Address offset: 0x1C */
#define SPI2_I2SPR         (*((volatile)  u32*)(_SPI_2_BASE_ADDRESS+0x20))/*!< SPI_I2S prescaler register,                         Address offset: 0x20 */
/***********************************************************************************
-----> Macros
*  Register Map : SPI3_Register

************************************************************************************/
#define SPI3_CR1           (*((volatile)  u32*)(_SPI_3_BASE_ADDRESS+0x00))/*!< SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */
#define SPI1_CR3           (*((volatile)  u32*)(_SPI_3_BASE_ADDRESS+0x04))/*!< SPI control register 2,                             Address offset: 0x04 */
#define SPI3_SR            (*((volatile)  u32*)(_SPI_3_BASE_ADDRESS+0x08))/*!< SPI status register,                                Address offset: 0x08 */
#define SPI3_DR            (*((volatile)  u32*)(_SPI_3_BASE_ADDRESS+0x0C))/*!< SPI data register,                                  Address offset: 0x0C */
#define SPI3_CRCPR         (*((volatile)  u32*)(_SPI_3_BASE_ADDRESS+0x10))/*!< SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
#define SPI3_RXCRCR        (*((volatile)  u32*)(_SPI_3_BASE_ADDRESS+0x14))/*!< SPI RX CRC register (not used in I2S mode),         Address offset: 0x14 */
#define SPI3_TXCRCR        (*((volatile)  u32*)(_SPI_3_BASE_ADDRESS+0x18))/*!< SPI TX CRC register (not used in I2S mode),         Address offset: 0x18 */
#define SPI3_I2SCFGR       (*((volatile)  u32*)(_SPI_3_BASE_ADDRESS+0x1C))/*!< SPI_I2S configuration register,                     Address offset: 0x1C */
#define SPI3_I2SPR         (*((volatile)  u32*)(_SPI_3_BASE_ADDRESS+0x20))/*!< SPI_I2S prescaler register,                         Address offset: 0x20 */
/***********************************************************************************
-----> Macros
*  Register Map : SPI4_Register

************************************************************************************/
#define SPI4_CR1           (*((volatile)  u32*)(_SPI_4_BASE_ADDRESS+0x00))/*!< SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */
#define SPI4_CR2           (*((volatile)  u32*)(_SPI_4_BASE_ADDRESS+0x04))/*!< SPI control register 2,                             Address offset: 0x04 */
#define SPI4_SR            (*((volatile)  u32*)(_SPI_4_BASE_ADDRESS+0x08))/*!< SPI status register,                                Address offset: 0x08 */
#define SPI4_DR            (*((volatile)  u32*)(_SPI_4_BASE_ADDRESS+0x0C))/*!< SPI data register,                                  Address offset: 0x0C */
#define SPI4_CRCPR         (*((volatile)  u32*)(_SPI_4_BASE_ADDRESS+0x10))/*!< SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
#define SPI4_RXCRCR        (*((volatile)  u32*)(_SPI_4_BASE_ADDRESS+0x14))/*!< SPI RX CRC register (not used in I2S mode),         Address offset: 0x14 */
#define SPI4_TXCRCR        (*((volatile)  u32*)(_SPI_4_BASE_ADDRESS+0x18))/*!< SPI TX CRC register (not used in I2S mode),         Address offset: 0x18 */
#define SPI4_I2SCFGR       (*((volatile)  u32*)(_SPI_4_BASE_ADDRESS+0x1C))/*!< SPI_I2S configuration register,                     Address offset: 0x1C */
#define SPI4_I2SPR         (*((volatile)  u32*)(_SPI_4_BASE_ADDRESS+0x20))/*!< SPI_I2S prescaler register,                         Address offset: 0x20 */
#endif //SPI_PRIVATE_H

/*************************************************************************************
*******************           End of guard of file  	  	       *******************
*************************************************************************************/ 