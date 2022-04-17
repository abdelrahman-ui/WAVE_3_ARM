/*======================================================================================
===========================   - NVIC_interface.h			     ===========================
===========================   - Created: /2021			     ===========================
===========================   - Author: Abdelrahman_Magdy    ===========================
===========================   - Version : _1_				 ===========================
===========================   - Note :
									  *-
									  *-
 ======================================================================================*/ 

/*=====================================================================================
		* What i sell To Customer
		*  The Archictect Give The API	
						- The Name Of Function 
						- What is The Input 
						- What Is The Output
						- Macro 
						 
======================================================================================*/ 

/*===================================================================================
===============     guard of file will call on time in .c		   ==================
=====================================================================================*/


#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

#include "STD_TYPES.h"
#include "NVIC_private.h"
#include "NVIC_config.h"




/*		 Enables an interrupt or exception.	   -------> ISERx		need Interrput Number	From Vector Table Referance Manual			*/
void MNVIC_vEnableINT(u8 Copy_u8IntNUM);
void MNVIC_vEnablePeripheral ( u8 Copy_u8INTID );
/*		Disables an interrupt or exception.				*/
void MNVIC_vDisableINT(u8 Copy_u8IntNUM);
void MNVIC_vDisablePeripheral ( u8 Copy_u8INTID );
/*Clears the pending status of interrupt or exception to 0.									*/

void MNVIC_vSetPendingFlag(u8 Copy_u8IntNUM);

void MNVIC_vClearPendingFlag ( u8 Copy_u8INTID );

void MNVIC_vConfigGroupSub(u8 Copy_u8ConfigGroupSub);



#define  _GROUP_4_SUB_0						0U
#define  _GROUP_3_SUB_1						1U
#define  _GROUP_2_SUB_2						2U
#define  _GROUP_1_SUB_3						3U
#define  _GROUP_0_SUB_4						4U




#endif