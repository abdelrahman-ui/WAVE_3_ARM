/*==============================================================================================
===============================   - NVIC_private.h				 ===============================
===============================   - Created: 2021			     ===============================
===============================   - Author: Abdelrahman_Magdy    ===============================
===============================   - Version : _1_				 ===============================
===============================   - Note :
									     *-
									     *-
=================================================================================================*/ 

/*===============================================================================================
*	 - Developer can't Edit in it    
*	  - Register _ Defination		
*	  - Design : 
					- #define	:	YES
					- Union		:	NO
					- Struct	:	NO
					
===================================================================================================*/

/*=====================================================================================
===================    guard of file will call on time in .c	    ===================
=======================================================================================*/ 

#ifndef _NVIC_PRIVATE_H
#define _NVIC_PRIVATE_H

/*=================================================================================
	-----> Macros
			*  Base_Address NVIC				
=================================================================================*/
#define _NVIC_BASS_ADDRESS    0xE000E100 

/*=================================================================================
	-----> Macros
			  *  Register Map	NVIC	
===================================================================================*/
/* Enable External interrupts from 0  to 31 */   
#define NVIC_ISER_0              (*((u32*)0xE000E100)) /* Enable External interrupts from 0  to 31 */   
#define NVIC_ISER_1              (*((u32*)0xE000E104)) /* Enable External interrupts from 32 to 63 */
#define NVIC_ISER_2              (*((u32*)0xE000E108)) /* Enable External interrupts from 32 to 63 */  

#define P_ISER                    ((u32*)0xE000E100) /* Enable External interrupts from 0  to 31 */  

/**********************************************************************************/

#define NVIC_ICER0               (*((u32*)0xE000E180)) /* Enable External interrupts from 0  to 31 */  
#define NVIC_ICER1               (*((u32*)0xE000E184)) /* Enable External interrupts from 32 to 63 */
#define NVIC_ICER1               (*((u32*)0xE000E188)) /* Enable External interrupts from 32 to 63 */  

#define P_ICER                   ((u32*)0xE000E180) /* Enable External interrupts from 0  to 31 */  

/**********************************************************************************/

#define NVIC_ISPR0               (*((u32*)0xE000E200) )
#define NVIC_ISPR1               (*((u32*)0xE000E204) )
#define NVIC_ISPR2               (*((u32*)0xE000E208) )
 
#define P_ISPR                    ((u32*)0xE000E200)

/**********************************************************************************/
#define NVIC_ICPR0       		(*((u32*)0xE000E280))
#define NVIC_ICPR1       		(*((u32*)0xE000E284))
#define NVIC_ICPR1       		(*((u32*)0xE000E288))
								
/**********************************************************************************/

#define NVIC_IABR0       (*((volatile u32*)0xE000E300))
#define NVIC_IABR1       (*((volatile u32*)0xE000E304))
#define NVIC_IABR2       (*((volatile u32*)0xE000E308))


/**********************************************************************************/


#define NVIC_IPR               (( u8 * )0xE000E400)



/***********************************************************************************
	-----> Macros
			  *  Register Map	 SCB_BASE_ADDRESS
			  * PassWord 0x05FA
***************************************************/
#define  SCB_Base_Address			0xE000ED00	
/*			
 	-----> Macros
	*  Register Map --------->AIRCR To Submet The Group & SubGroup
	* Statuse Of Group And Sub Application interrupt and reset control register (AIRCR)
*/
#define  SCB_AIRCR 								(*((volatile u32 *) ( SCB_Base_Address + 0xC)))






#endif//_NVIC_PRIVATE_H