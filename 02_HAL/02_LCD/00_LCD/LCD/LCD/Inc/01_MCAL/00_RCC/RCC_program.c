/****************************** *********************************************************
 ***************************  - RCC_program.c				 ****************************
***************************   - Created: 2/8/2021			 ****************************
***************************   - Author: Abdelrahman_Magdy     ***************************
***************************   - Version : _1_				 ****************************
***************************   - Note :
									*-
									*-
 **************************************************************************************/ 


/****************************************************************************************
***************************   The Foundation Of Function   ***************************** 
****************************************************************************************/


/************** INCLUDE LIB **************/
		 #include "00_LIB/STD_types.h"
		 #include "00_LIB/util.h"
/*****************************************/	 

/************** INCLUDE MCAL**************/
		#include "RCC_private.h"
		#include "RCC_interface.h"
		#include "RCC_config.h"
/*****************************************/

/************** INCLUDE HALL**************/
			

/*****************************************/

/************** INCLUDEAPP***************/


/*****************************************/





/************************************ Start_FUNCTION  ************************************/
/* About The Function :
	
				- CLK		: HSE | HSI |PLL	
				- PLLSrc	:PLL_HSE | PLL_HSI
				- HSESrc    :HSE_Crystal ,HSE_RC 
				- If not used send 0
 */
 void MRCC_voidInitSysClock( ClkSrcName_t ClkSrc , HSESrcName_t HSESrc , PllSrcName_t PLLSrc  , AHBPreName_t AHB_Prescaler , APB1PreName_t APB1_Prescaler  , APB2PreName_t APB2_Prescaler ) 
 {
		switch(ClkSrc)
		{
			//HSE
			case HSE_CLK 	: 
				switch (HSESrc)
				{	// HSE CRYSTAL 
					case  HSE_Crystal :
						SET_BIT(RCC_CR   , 16U) ;		// EN HSE
						CLR_BIT(RCC_CR   , 18U) ;		// Disable Byp
						SET_BIT(RCC_CFGR , 0U ) ;		// System Clk  HSE
						CLR_BIT(RCC_CFGR , 1U ) ;		// System Clk  HSE
					break; 
					// HSE RC
					case  HSE_RC :
						SET_BIT(RCC_CR   , 16U) ;				// EN HSE
						SET_BIT(RCC_CR   , 18U) ;				// Enable Byp
						SET_BIT(RCC_CFGR , 0U ) ;				// System Clk  HSE
						CLR_BIT(RCC_CFGR , 1U ) ;				// System Clk  HSE
					break;
					
					/*default		:  break;*/
						
						
					}
			
		  break ;
			 /*******************************************************************************/ 
			 // HSI  
			case HSI_CLK	: 
				SET_BIT(RCC_CR   , 0U   ) ;           // EN HSI
				CLR_BIT(RCC_CFGR , 0U   ) ;					 // System Clk  HSI
				CLR_BIT(RCC_CFGR , 1U   ) ;					 // System Clk  HSI
			 break; 
			/*********************************************************************************/
			// PLL 
			case PLL_CLK 	:
				 switch(PLLSrc)
				 {
					 // PLL HSE 
					 case PLL_HSE :
							 SET_BIT(RCC_CR , 16U) ;						// EN HSE
							 SET_BIT(RCC_CR , 24U) ;						//  EN PLL
							 SET_BIT(RCC_PLLCFGR ,22U) ;				//  PLL From HSE 
							 CLR_BIT(RCC_CFGR , 0U ) ;					// System Clk  PLL
							 SET_BIT(RCC_CFGR , 1U ) ;				  // System Clk  PLL
					 break ;
					 // PLL HSI
					 case PLL_HSI :
					     SET_BIT(RCC_CR ,   0U   ) ;            // EN HSI
							 SET_BIT(RCC_CR ,  24U)    ;					 	//  EN PLL
							 CLR_BIT(RCC_PLLCFGR ,22U) ;					  //  PLL From HSI
							 CLR_BIT(RCC_CFGR , 0U )   ;					  // System Clk  PLL
							 SET_BIT(RCC_CFGR , 1 )   ;				    // System Clk  PLL
							 
					 break ;
					 
					 	/*default		:  break;*/
					 
				 }
			
			break; 
		/*default		:  break;*/
			
			 }
			/****************************************************************************************/
				/*
	 ABP1_Pre1
	 ABP1_Pre2
	 ABP1_Pre4
	 ABP1_Pre8
	 ABP1_Pre16
	
	*/
	switch (APB1_Prescaler)
	{
		case ABP1_Pre1:
			CLR_BIT(RCC_CFGR , 10U) ;
			CLR_BIT(RCC_CFGR , 11U) ;
			CLR_BIT(RCC_CFGR , 12U) ;
		break; 
		case ABP1_Pre2:
			CLR_BIT(RCC_CFGR , 10U) ;
			CLR_BIT(RCC_CFGR , 11U) ;
			SET_BIT(RCC_CFGR,  12U) ;
		break;
		case ABP1_Pre4:
			SET_BIT(RCC_CFGR , 10U) ;
			CLR_BIT(RCC_CFGR , 11U) ;
			SET_BIT(RCC_CFGR,  12U) ;
		break;
		case ABP1_Pre8:
			CLR_BIT(RCC_CFGR , 10U) ;
			SET_BIT(RCC_CFGR , 11U) ;
			SET_BIT(RCC_CFGR,  12U) ;
		break;
		case ABP1_Pre16:
			SET_BIT(RCC_CFGR , 10U) ;
			SET_BIT(RCC_CFGR , 11U) ;
			SET_BIT(RCC_CFGR,  12U) ;
		break;
			/*default		:  break;*/
		
		
	}
/**************************************************************************************************/	
		/*
		* APB2_Prescaller 
		ABP2_Pre1
		ABP2_Pre2
		ABP2_Pre4
		ABP2_Pre8
		ABP2_Pre16
		13 , 14 ,15
		*/
		switch (APB2_Prescaler)
		{
			case  ABP2_Pre1 :
				CLR_BIT(RCC_CFGR , 13U) ;
				CLR_BIT(RCC_CFGR , 14U) ;
				CLR_BIT(RCC_CFGR , 15U) ;
			break;
			case  ABP2_Pre2 :
				CLR_BIT(RCC_CFGR , 13U) ;
				CLR_BIT(RCC_CFGR , 14U) ;
				SET_BIT(RCC_CFGR , 15U) ;
			break;
			case  ABP2_Pre4 :
				SET_BIT(RCC_CFGR , 13) ;
				CLR_BIT(RCC_CFGR , 14) ;
				SET_BIT(RCC_CFGR , 15) ;
			break;
			case  ABP2_Pre8 :
				CLR_BIT(RCC_CFGR , 13U) ;
				SET_BIT(RCC_CFGR , 14U) ;
				SET_BIT(RCC_CFGR , 15U) ;
			break;
			case  ABP2_Pre16 :
				SET_BIT(RCC_CFGR , 13U) ;
				SET_BIT(RCC_CFGR , 14U) ;
				SET_BIT(RCC_CFGR , 15U) ;
			break;
			
			/*default		:  break;*/
			
			
			
		}
	
			
			/*
					AHB_Pre1
					AHB_Pre2
					AHB_Pre4
					AHB_Pre8
					AHB_Pre16
					AHB_Pre32
					AHB_Pre64
					AHB_Pre128
					AHB_Pre256
					AHB_Pre512
			
			*/
			switch (AHB_Prescaler)
			{
				case AHB_Pre1 :
						CLR_BIT(RCC_CFGR , 4U ) ;
						CLR_BIT(RCC_CFGR , 5U ) ;
						CLR_BIT(RCC_CFGR , 6U ) ;
						CLR_BIT(RCC_CFGR , 7U ) ;
				break ;                 
				/***********/           
				case AHB_Pre2 :         
						CLR_BIT(RCC_CFGR , 4U ) ;
						CLR_BIT(RCC_CFGR , 5U ) ;
						CLR_BIT(RCC_CFGR , 6U ) ;
						SET_BIT(RCC_CFGR , 7U ) ;
				break ;                 
				/***********/           
				case AHB_Pre4 :         
						SET_BIT(RCC_CFGR , 4U ) ;
						CLR_BIT(RCC_CFGR , 5U ) ;
						CLR_BIT(RCC_CFGR , 6U ) ;
						SET_BIT(RCC_CFGR , 7U ) ;
				break ;                 
				/***********/           
				case AHB_Pre8 :       
					
						CLR_BIT(RCC_CFGR , 4U ) ;
						SET_BIT(RCC_CFGR , 5U ) ;
						CLR_BIT(RCC_CFGR , 6U ) ;
						SET_BIT(RCC_CFGR , 7U ) ;
				break ;                 
				/***********/     
				/* case AHB_Pre32 : */
				/***********/   
				case AHB_Pre16 :        
						SET_BIT(RCC_CFGR , 4U ) ;
						SET_BIT(RCC_CFGR , 5U ) ;
						CLR_BIT(RCC_CFGR , 6U ) ;
						SET_BIT(RCC_CFGR , 7U ) ;
				break ;                 
				/***********/           
				case AHB_Pre64 :        
						CLR_BIT(RCC_CFGR , 4U ) ;
						CLR_BIT(RCC_CFGR , 5U ) ;
						SET_BIT(RCC_CFGR , 6U ) ;
						SET_BIT(RCC_CFGR , 7U ) ;
				break ;                 
				/***********/           
				case AHB_Pre128 :       
						CLR_BIT(RCC_CFGR , 4U ) ;
						SET_BIT(RCC_CFGR , 5U ) ;
						SET_BIT(RCC_CFGR , 6U ) ;
						SET_BIT(RCC_CFGR , 7U ) ;
				break ;                 
				/***********/           
				case AHB_Pre512 :       
						SET_BIT(RCC_CFGR , 4U ) ;
						SET_BIT(RCC_CFGR , 5U ) ;
						SET_BIT(RCC_CFGR , 6U ) ;
						SET_BIT(RCC_CFGR , 7U ) ;
				break ;
				/***********/
					/*default		:  break;*/ 
				
			}
		 
 }



/*********************************************************** END_ FUNCTION   ***********************************************************/



\
/************************************ Start_FUNCTION  ************************************/

 void MRCC_voidEnableClock (BusName_t BusName ,u8 Copy_u8PerName  )
 {
	 switch(BusName) 
	 {
		 case AHB1_BUS :
			SET_BIT(RCC_AHB1ENR , Copy_u8PerName  ) ;
		 break ; 
		 
		 case AHB2_BUS  :
			SET_BIT(RCC_AHB2ENR , Copy_u8PerName  ) ;
		 break ;
		 
		 case AHB3_BUS  :
			 SET_BIT(RCC_AHB3ENR , Copy_u8PerName  ) ;
		 break ;
		 
		 case APB1_BUS  :
			SET_BIT(RCC_APB1ENR , Copy_u8PerName  ) ;
		 break ;
		 
		 case APB2_BUS  :
			SET_BIT(RCC_APB2ENR , Copy_u8PerName  ) ;
		 break ;
		 
			/*default		:  break;*/
		 
		 
	 }
 }

 
