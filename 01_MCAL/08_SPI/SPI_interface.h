/******************************************************************************************
 ***************************  - SPI_interface.h	 		 	    ***************************
***************************   - Created: 2/22/2022				***************************
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






#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/**********************

*********************/

#define MSPI_DISABLE                 0U
#define MSPI_ENABLE                  1U

/**********************
CPH =0 : The frist clock transition is the first data capture edge ( R   W )
CPH =1 : The second clock transition is the first data capture edge ( W  R )
*********************/

#define SPI_MODE0                   0U /* CPL =0   & CPH =0  */
#define SPI_MODE1                   1U /* CPL =0   & CPH =1  */
#define SPI_MODE2                   2U /* CPL =1   & CPH =0  */
#define SPI_MODE3                   3U /* CPL =1   & CPH =1  */
/**********************

*********************/
#define SPI_MASTER                  0U
#define SPI_SLAVE                   1U
/**********************

*********************/
#define SPI_FPCLK_DIVIDED_BY_2      0b000
#define SPI_FPCLK_DIVIDED_BY_4      0b001
#define SPI_FPCLK_DIVIDED_BY_8      0b010
#define SPI_FPCLK_DIVIDED_BY_16     0b011
#define SPI_FPCLK_DIVIDED_BY_32     0b100
#define SPI_FPCLK_DIVIDED_BY_64     0b101
#define SPI_FPCLK_DIVIDED_BY_128    0b110
#define SPI_FPCLK_DIVIDED_BY_256    0b111
/**********************

*********************/
#define SPI_MSB_FIRST                0U
#define SPI_LSB_FIRST 				 1U
/**********************
CLOSE : NSS connect  out
OPEN  :NSS not  connect out so i can used as DIO 
 * NSS not used in master So in master mode 
*********************/
/* NSS connect  out */
#define SSM_SWITCH_CLOSE            0U
#define SSM_SWITCH_OPEN             1U /* To used it as DIO Not Nss Mater not need NSS  */
/**********************
SSI_HIGH : Connect VCC
SSI_LOW  : Connect GROUND
*********************/
#define SSI_VCC                     1U
#define SSI_GROUND                  0U
/**********************

*********************/
#define SPI_8BIT_DATA               0U
#define SPI_16BIT_DATA              1U
/**********************

*********************/
#define SPI_INT_DISABLE             0U
#define SPI_TXE_INT_ENABLE          1U
#define SPI_RXNE_INT_ENABLE         2U

/*******************************************/




#define CPHA        0U
#define CPOL        1U
#define MSTR        2U
#define SPE         6U
#define LSBFIRST    7U     
#define SSI         8U
#define SSM         9U
#define RXONLY      10U
#define DFF         11U
#define BIDIMODE    15U

#define RXNEIE       6U
#define TXEIE        7U


#define BSY          7U








/*			Function */
void MSPI_VidInit         ( void               ) ;
/*			Function */
u8   MSPI1_VidSendDataU8  ( u8 Copy_u8Data     ) ;
/*			Function */
// u16   MSPI1_VidSendDataU8  ( u8 Copy_u8Data     ) ;
/*			Function */

void MSPI1_VidSetCallBack ( void (*ptr) (void) ) ;


#endif /* SPI_INTERFACE_H_ */


/*************************************************************************************
*******************           End of guard of file  	  	       *******************
*************************************************************************************/ 













