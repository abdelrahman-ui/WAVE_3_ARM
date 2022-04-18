/***************************************************************************************
 ***************************  - SPI_config.h				 ***************************
***************************   - Created: 			 ***************************
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

typedef enum{
    READ_WRITE, /*WRITE Then READ */
    WRITE_READ
}Phase_t;
#define SPI_PHASE 		WRITE_READ

typedef enum{
    IDLE_0,
    IDLE_1
}Polarity_t;
#define SPI_POLARITY 	IDLE_0

typedef enum{
    SLAVE,
    MASTER
}Master_slave_t;
#define SPI_MASTER_SLAVE	MASTER

typedef enum{
	GND ,
	VCC	
}SSI_t;
#define SSI_STATE 		VCC

typedef enum{
	SWITCH_CLOSE ,
	SWITCH_OPEN	
}SSM_t;
#define SSI_STATE 		SWITCH_OPEN

typedef enum{
    B_2,
    B_4,
    B_8,
    B_16,
    B_32,
    B_64,
    B_128,
    B_256,
}Baud_rate_t;
#define BUAD_RATE  B_4

typedef enum{
    MSB_FIRST,
    LSB_FIRST
}Frame_format_t;
#define  DATA_ORDER  MSB_FIRST

typedef enum{
    S_8_BIT,
    S_16_BIT
}Data_sizet_t;
#define DATA_FORMAT S_8_BIT




#endif /* SPI_CONFIG_H_ */

/*************************************************************************************
*******************           End of guard of file  	  	       *******************
*************************************************************************************/ 
