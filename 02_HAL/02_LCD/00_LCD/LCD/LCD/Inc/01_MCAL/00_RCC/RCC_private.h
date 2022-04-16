/***************************************************************************************
 *************************** - RCC_private.h				 ***************************
***************************  - Created: 2/8/2021			 ***************************
***************************   -Author: Abdelrahman_Magdy     ***************************
***************************   -Version : _1_				 ***************************
***************************   -Note :
									*-
									*-
 **************************************************************************************/ 

/**************************************************************************************

*	 - Developer can't Edit in it    
*	  - Register _ Defination		
*	  - Design : 
					- #define	:   Yes
					- Union		:	NO
					- Struct	:	NO

**************************************************************************************/

/*************************************************************************************
******************* guard of file will call on time in .c		   *******************
*************************************************************************************/ 


#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/***********************************************************************************
	*
	-----> Macros
			*  Base_Address is				0x40023800 
			*  Register Map
************************************************************************************/
    #define         RCC_BASE_ADDRESS                    0x40023800

	#define			 RCC_CR								(*((volatile u32*) (RCC_BASE_ADDRESS+0X00)))
	#define			 RCC_PLLCFGR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x04)))
	#define			 RCC_CFGR							(*((volatile u32*) (RCC_BASE_ADDRESS+0x08)))
	#define			 RCC_CIR							(*((volatile u32*) (RCC_BASE_ADDRESS+0x0C)))
	#define			 RCC_AHB1RSTR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x10)))
	#define			 RCC_AHB2RSTR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x14)))
	#define			 RCC_AHB3RSTR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x18)))
	#define			 RCC_APB1RSTR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x20)))
	#define			 RCC_APB2RSTR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x24)))
	#define			 RCC_AHB1ENR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x30)))
	#define			 RCC_AHB2ENR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x34)))
	#define			 RCC_AHB3ENR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x38)))
	#define			 RCC_APB1ENR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x40)))
	#define			 RCC_APB2ENR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x44)))
	#define			 RCC_AHB1LPENR				        (*((volatile u32*) (RCC_BASE_ADDRESS+0x50)))
	#define			 RCC_AHB2LPENR				        (*((volatile u32*) (RCC_BASE_ADDRESS+0x54)))
	#define			 RCC_AHB3LPENR				        (*((volatile u32*) (RCC_BASE_ADDRESS+0x58)))
	#define			 RCC_APB1LPENR				        (*((volatile u32*) (RCC_BASE_ADDRESS+0x60)))
	#define			 RCC_APB2LPENR				        (*((volatile u32*) (RCC_BASE_ADDRESS+0x64)))
	#define			 RCC_BDCR							(*((volatile u32*) (RCC_BASE_ADDRESS+0x70)))
	#define			 RCC_CSR							(*((volatile u32*) (RCC_BASE_ADDRESS+0x74)))
	#define			 RCC_SSCGR						    (*((volatile u32*) (RCC_BASE_ADDRESS+0x80)))
	#define			 RCC_PLLI2SCFGR				        (*((volatile u32*) (RCC_BASE_ADDRESS+0x84)))

	/* Macros Of :
			         
							- RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
	*/
#define PERIPHERAL_EN_GPIOA							0
#define PERIPHERAL_EN_GPIOB							1
#define PERIPHERAL_EN_GPIOC							2
#define PERIPHERAL_EN_GPIOD							3
#define PERIPHERAL_EN_GPIOE							4
#define PERIPHERAL_EN_GPIOF							5
#define PERIPHERAL_EN_GPIOG							6
#define PERIPHERAL_EN_GPIOH							7
#define PERIPHERAL_EN_GPIOI							8
#define PERIPHERAL_EN_CRC							12
#define PERIPHERAL_EN_FLITF                         15
#define PERIPHERAL_EN_BKPSRAM         	            18
#define PERIPHERAL_EN_CCMDATARAM      	            20
#define PERIPHERAL_EN_DMA1							21
#define PERIPHERAL_EN_DMA2							22
#define PERIPHERAL_EN_ETHMAC						25
#define PERIPHERAL_EN_ETHMACTX                      26
#define PERIPHERAL_EN_ETHMACRX                      27
#define PERIPHERAL_EN_ETHMACPTP                     28
#define PERIPHERAL_EN_OTGHS					  	    29
#define PERIPHERAL_EN_OTGHSULPI                     30


/* Macros Of :
			         
							- RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
	*/
	
#define PERIPHERAL_EN_DCMI 						 0
#define PERIPHERAL_EN_CRYP 						 4
#define PERIPHERAL_EN_HASH 						 5
#define PERIPHERAL_EN_RNG 	  				     6
#define PERIPHERAL_EN_OTGFS 					 7

	/* Macros Of :
			         
							- RCC APB1 peripheral clock enable register
	*/
		
#define PERIPHERAL_EN_TIM2						0
#define PERIPHERAL_EN_TIM3						1
#define PERIPHERAL_EN_TIM4						2
#define PERIPHERAL_EN_TIM5					    3
#define PERIPHERAL_EN_TIM6						4
#define PERIPHERAL_EN_TIM7						5
#define PERIPHERAL_EN_TIM12					    6
#define PERIPHERAL_EN_TIM13					    7
#define PERIPHERAL_EN_TIM14					    8
#define PERIPHERAL_EN_WWDG						11
#define PERIPHERAL_EN_SPI2						14
#define PERIPHERAL_EN_SPI3						15
#define PERIPHERAL_EN_UART2						17
#define PERIPHERAL_EN_UART3						18
#define PERIPHERAL_EN_UART4						19
#define PERIPHERAL_EN_UART5						20
#define PERIPHERAL_EN_I2C1						21
#define PERIPHERAL_EN_I2C2						22
#define PERIPHERAL_EN_I2C3						23
#define PERIPHERAL_EN_CAN1						25
#define PERIPHERAL_EN_CAN2						26
#define PERIPHERAL_EN_PWR						28
#define PERIPHERAL_EN_DAC						29

/* Macros Of :
			         
							- RCC AHB3 peripheral clock enable register (RCC_AHB3ENR)
	*/

#define PERIPHERAL_EN_FSMC					    0

/* Macros Of :
			         
							- RCC APB2 peripheral clock enable register (RCC_APB2ENR)
	*/

#define PERIPHERAL_EN_TIM1  				 0
#define PERIPHERAL_EN_TIM8					 1
#define PERIPHERAL_EN_USART1				 4
#define PERIPHERAL_EN_USART6				 5
#define PERIPHERAL_EN_ADC1					 8
#define PERIPHERAL_EN_ADC2					 9
#define PERIPHERAL_EN_ADC3					 10
#define PERIPHERAL_EN_SDIO					 11
#define PERIPHERAL_EN_SPI1					 12
#define PERIPHERAL_EN_SYSCFG				 14
#define PERIPHERAL_EN_TIM9					 16
#define PERIPHERAL_EN_TIM10					 17
#define PERIPHERAL_EN_TIM11 				 18
	 



#endif //RCC_PRIVATE_H

