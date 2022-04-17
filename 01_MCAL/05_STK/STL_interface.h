/****************************************************************
 ************   - STK_interface.h                  ******************
 ***********					   		       ******************
 ***********   -Created: 2/9/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********  -								   ******************
 ****************************************************************/

/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/

/**************		The Archictect Give The API		**************/
/**************  Application Public Interface   **************/
/*****************************************************************
		*  The Archictect Give The API
						- The Name Of Function
						- What is The Input
						- What Is The Output
******************************************************************/



#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

#include "STD_TYPES.h"

#define _MSTK_CLK_AHB        0U
#define _MSTK_CLK_AHB_8      1U
/**/
#define _MSTK_SINGLE_        0U
#define _MSTK_PERIODIC       1U



/*	1- Function Only Apply The Clock From Configer ( AHB or( AHB/8---> 1MHZ) So 1 = 1Msec & Disable SysTick Interrupt & Disa-ble SysTick  */
void MSTK_voidInit(void);







#endif //STK_INTERFACE_H