/***************************************************************************************
 ***************************  - STK_config.h				 ***************************
***************************   - Created: 5/24/2021			 ***************************
***************************   - Author: Abdelrahman_Magdy    ***************************
***************************   - Version : _1_				 ***************************
***************************   - Note :
									 *-
									 *-
 **************************************************************************************/ 


/**************************************************************************************
	- The Optiones Which Developer Choose From Which What Is Appropriate To App
 **************************************************************************************/

/**************************************************************************************
******************* guard of file will call on time in .c		   ********************
**************************************************************************************/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#include "SPI_private.h"

#define MSPI_NUM             MSPI1  
/* Enable SPI */
#define MSP1_STATUS          SPI_ENABLE 
/* CK to 1 when idle & The second clock transition is the first data capture edge */ 
#define MSPI1_CLOCK_MODE     SPI_MODE3 
/* */
#define MSPI1_MASTER_SLAVE   SPI_MASTER
/* */
#define MSPI1_PRESCALLER     SPI_FPCLK_DIVIDED_BY_2
/* */
#define MSPI1_DATA_ORDER     SPI_MSB_FIRST
/* */
#define MSPI1_SSM_MANAGE      SSM_SWITCH_OPEN 
/* */
#define MSPI_SSI_MODE         SSI_VCC

#define MSPI1_DATA_SIZE      SPI_8BIT_DATA
/* */
#define MSPI1_INT_STATUS     SPI_INT_DISABLE



#endif /* SPI_CONFIG_H_ */

/*************************************************************************************
*******************           End of guard of file  	  	       *******************
*************************************************************************************/ 
