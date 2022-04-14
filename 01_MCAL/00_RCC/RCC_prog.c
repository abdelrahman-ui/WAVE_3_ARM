/*=======================================================================================
============================   - RCC_program.c				 ============================
============================   - Created: 4/4/2022			 ============================
============================   - Author: Abdelrahman_Magdy   ============================
============================   - Version : _1_				 ============================
============================   - Note :  
									     *-
									     *-
=======================================================================================*/ 


/*=======================================================================================
============================   The Foundation Of Function   ============================= 
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "STD_TYPES.h"
		 #include "BIT_MATH.h"
/*======================================*/	 
/*===========  INCLUDE MCAL  ===========*/
		#include "RCC_private.h"
		#include "RCC_interface.h"
		#include "RCC_config.h"
/*======================================*/	
/*===========  INCLUDE HAL   ===========*/
			

/*======================================*/	

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/	




/*====================================================   Start_FUNCTION   ====================================================*/
 /*
	- Function To Enable Prepheral :
	
							       - BusName_t      :  The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One Detect Which REG To Choice Pripheral From It
							       - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg 
	
*/


void MRCC_vEnableClock(BusName_t BusName , u8 Copy_u8PerNum )
{
	
	switch(BusName)
	{
		case AHB1_BUS:  SET_BIT(RCC_AHB1ENR,Copy_u8PerNum );         break ;
		case AHB2_BUS:  SET_BIT(RCC_AHB2ENR,Copy_u8PerNum );         break ;
		case APB1_BUS:  SET_BIT(RCC_APB1ENR,Copy_u8PerNum );         break ;
		case APB2_BUS:  SET_BIT(RCC_APB2ENR,Copy_u8PerNum );         break ;
		default :     /*   ERROR   */          break ;
		
	}
	
	
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

 /*
	- Function To Disable Prepheral :
	
							       - BusName_t      :  The Bus Of The Prepheral ( AHB1 , AHB2  , APB1 , APB2 ) Every One Detect Which REG To Choice Pripheral From It
							       - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg 
	
*/

void MRCC_vDisableClock(BusName_t BusName , u8 Copy_u8PerNum )
{
	switch(BusName)
	{
		case AHB1_BUS:  CLR_BIT(RCC_AHB1ENR,Copy_u8PerNum );         break ;
		case AHB2_BUS:  CLR_BIT(RCC_AHB2ENR,Copy_u8PerNum );         break ;
		case APB1_BUS:  CLR_BIT(RCC_APB1ENR,Copy_u8PerNum );         break ;
		case APB2_BUS:  CLR_BIT(RCC_APB2ENR,Copy_u8PerNum );         break ;
		default :     /* ERROR */          break ;
		
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

/*
* Function To Enable Security System
*/

void MRCC_vEnableSecuritySystem(void)
{
	SET_BIT( RCC_CR  , CSSON);
	
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*
* Function To Disable Security System
*/

void MRCC_vDisableSecuritySystem(void)
{
	CLR_BIT( RCC_CR  , CSSON);
	
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/* About The Function :
	
				- CLK		: HSE | HSI |PLL	
				- PLLSrc	:PLL_HSE | PLL_HSI
				- HSESrc    :HSE_Crystal ,HSE_RC 
 */

void MRCC_vInitSystemCLK(void)
{
	/********** HSI **********/
#if CLKSRC == HSI 
	/* 1- EN HSI */
	SET_BIT(MRCC->CR , 0U);
	/* 2- CLK SYS --> HSI */
	CLR_BIT(MRCC->CFGR, 0U);
	CLR_BIT(MRCC->CFGR, 1U);
	/*
		while( ( ( GET_BIT( MRCC->CR , 1 ) ) == 0 ) && ( LOC_u32TimeOut < 100000 ) ){ LOC_u32TimeOut++; }
		if( LOC_u32TimeOut >= 100000 ){ TimeOut }*/
		
	/********** HSE **********/
#elif CLKSRC == HSE
	
	#if HSE_SRC == CRYSTAL 
	/* 1- EN HSE */
		SET_BIT(MRCC->CR , 16U);
		/* 2- Disable BYP */
		CLR_BIT(MRCC->CR,18U);
		/* 3- CLK SYS --> HSE */
		SET_BIT(MRCC->CFGR, 0U);
		CLR_BIT(MRCC->CFGR, 1U);
		/* Bit 17 -> Checking While The HSE Clock Is Stable 
		while( ( ( GET_BIT( MRCC->CR , 17 ) ) == 0 ) && ( LOC_u32TimeOut < 100000 ) ){ LOC_u32TimeOut++; }
		if( LOC_u32TimeOut >= 100000 ){ TimeOut}*/
		

	#elif HSE_SRC == RC 
		/* 1- EN HSE */
		SET_BIT(MRCC->CR , 16U);
		/* 2- Enable BYP */
		SET_BIT(MRCC->CR,18U);
		/* 3- CLK SYS --> HSE */
		SET_BIT(MRCC->CFGR, 0U);
		CLR_BIT(MRCC->CFGR, 1U);
	#else 
    /* Error*/
	#endif
	
	/********** PLL **********/
#elif CLKSRC == PLL	

    #if PLL_SRC == _HSE_PLL 
     /*1-Enable HSE */
			SET_BIT(MRCC->CR,16U);
			/* while ( GET_BIT(RCC_CR, 17)==0);*/
			/*2- Disable PLL*/
			CLR_BIT(MRCC->CR,24U);
			/* while ( GET_BIT(RCC_CR, 25)==0);*/
			/* 3- PLL From HSE */
			SET_BIT(MRCC->PLLCFGR, 22U);
			/*4- Enable PLL*/
			SET_BIT(MRCC->CR,24U);
			/* 5- System Clk  PLL */
			CLR_BIT(MRCC->CFGR,0U);
			SET_BIT(MRCC->CFGR,1U);
 
    #elif PLL_SRC == _HSI_PLL  
            /*Enable HSI */
		     SET_BIT(MRCC->CR,0U);
		     /*2- Disable PLL*/
		     CLR_BIT(MRCC->CR,24U);
			/* 3- PLL From HSI */
			CLR_BIT(MRCC->PLLCFGR, 22U);
			/*4- Enable PLL*/
			SET_BIT(MRCC->CR,24U);
			/* 5- System Clk  PLL */
			CLR_BIT(MRCC->CFGR,0U);
			SET_BIT(MRCC->CFGR,1U);
    #else 
            /* Error*/
	#endif
/****************************************************/

#else 
/* Error*/
#endif // The End Of Big IF	
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/


void MRCC_vOutMCO_1(u8 Copy_u8MC1_0SRC )
{
 switch(Copy_u8MC1_0SRC)
 {
	case MC0_1_LSE : 
	        CLR_BIT(RCC_CFGR , 22);
			SET_BIT(RCC_CFGR , 21);
	break  ;
	/*********/
	case MC0_1_HSE  :
	
	        CLR_BIT(RCC_CFGR , 21);
			SET_BIT(RCC_CFGR , 22);
	break  ;
	/*********/
	case MC0_1_HSI  :
			CLR_BIT(RCC_CFGR , 21);
			CLR_BIT(RCC_CFGR , 22);
	break  ;
	/*********/
	case  MC0_1_PLL :
	        SET_BIT(RCC_CFGR , 21);
			SET_BIT(RCC_CFGR , 22);
	break  ;
	default :   /* ERROR*/ break ;
	
	
 }

}



/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/


void MRCC_vOutMCO_1Pre(MCO_1_Pre_t Copy_tPreMco_1 )
{
	switch (Copy_tPreMco_1 )
	{
	 case MCO_1_Div_1 :	 
	       CLR_BIT(RCC_CFGR , 26);
	 break ; 
	 case MCO_1_Div_2 :	 
		   CLR_BIT(RCC_CFGR , 24);
		   CLR_BIT(RCC_CFGR , 25);
	       SET_BIT(RCC_CFGR , 26);
	 break ; 
	 case MCO_1_Div_3 :	 
		   SET_BIT(RCC_CFGR , 24);
		   CLR_BIT(RCC_CFGR , 25);
	       SET_BIT(RCC_CFGR , 26);
	 break ; 
	  case MCO_1_Div_4 :	 
		   CLR_BIT(RCC_CFGR , 24);
		   SET_BIT(RCC_CFGR , 25);
	       SET_BIT(RCC_CFGR , 26);
	 break ; 
	  case MCO_1_Div_5 :	 
		   SET_BIT(RCC_CFGR , 24);
		   SET_BIT(RCC_CFGR , 25);
	       SET_BIT(RCC_CFGR , 26);
	 break ; 
		
	}

}

/*====================================================   END_ FUNCTION   ====================================================*/


void MRCC_vInitSystemCLK_Systick(u8 Copy_u8Dev)
{
   /* 1- EN HSI */
	SET_BIT(MRCC->CR , 0U);
	/* 2- CLK SYS --> HSI */
	CLR_BIT(MRCC->CFGR, 0U);
	CLR_BIT(MRCC->CFGR, 1U);
	if(Copy_u8Dev == 1)
	{
		/* Div (AHB/2) */
		RCC_CFGR |=(0b1000<<4U);
		
	}
	else{/* - Misra */}
}