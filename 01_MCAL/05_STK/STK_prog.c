







/**/
void (* MSTK_CallBack)(void);
/**/
void SysTick_Handler(void);
/**/
static volatile u8 G_u8Set_mode ;

void MSTK_vInit(void)
{
	_MSTK->CTRL=0;
	#if   _MSTK_CLK_SRC  == _MSTK_CLK_AHB
	/* Disable Count , Enable INT , Set CLK = AHB */
	SET_BIT(MSTK->CTRL , 2U);
	#elif _MSTK_CLK_SRC == _MSTK_CLK_AHB_8
	/* Disable Count , Disable INT , Set CLK = AHB/8 */
	_MSTK->CTRL=0;

	#endif

}


void MSTK_vBusyWait(u32 Copy_u32Ticks )
{
/*1) Load value in LOAD REG */
MSTK->LOAD = Copy_u32Ticks ;
/*2) Strat Count */	
MSTK->CTRL|=(1U<<0);
/*3) Wait The flag */	
while((GIT_BIT( MSTK->CTRL , 16U ))==0U );	
/*4) Stop Timer */
MSTK -> CRTL &=~(1U<<0);
MSTK -> LOAD =0U;
MSTK -> VAL  =0U;
	
}

u32 MSTK_u32GetRemainingTime(void)
{
	u32 L_32RamingTime = 0U ;
	L_32RamingTime=MSTK->VAL ;
	return L_32RamingTime;
}

u32 MSTK_u32GetElapsedTime(void)
{
		u32 L_32RamingTime = 0U ;
	L_32RamingTime=((MSTK->LOAD)-(MSTK->VAL)) ;
	return L_32RamingTime;
	
}


void MSTK_vSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_Ptr)(void) )
{
	/*1) Load value in LOAD REG */
		MSTK->LOAD = Copy_u32Ticks ;
	/*2) Set Call Back */
		MSTK_CallBack = Copy_Ptr;
	/*3) Set mode is periodic */
		G_u8Set_mode = _MSTK_PERIODIC ;
	/*4) Enable for the INT */
		SET_BIT(MSTK->CTRL,1U);
	/*5) Start Count  */
		SET_BIT(MSTK->CTRL,0U);

}
void MSTK_vSetIntervalSingle(u32 Copy_u32Ticks , void (*Copy_Ptr)(void) )
{
	/*1) Load value in LOAD REG */
		MSTK->LOAD = Copy_u32Ticks ;
	/*2) Set Call Back */
		MSTK_CallBack = Copy_Ptr;
	/*3) Set mode is SINGLE  */
		G_u8Set_mode = _MSTK_SINGLE ;
	/*4) Enable for the INT */
		SET_BIT(MSTK->CTRL,1U);
	/*5) Start Count  */
		SET_BIT(MSTK->CTRL,0U);
	
	
}

void MSTK_StopInterval(void)
{
	
	  /* Stop Timer */
		MSTK -> CRTL &=~(1U<<0);
		MSTK -> LOAD =0U;
		MSTK -> VAL  =0U;
		/* Disable For Int */
		CLR_BIT(MSTK->CTRL , 1U );
	
	
}

void SysTick_Handler(void)
{
	u8 L_u8Temp=0U ;
	
	if(G_u8Set_mode ==_MSTK_SINGLE )
	{
		/* Stop Timer */
		MSTK -> CRTL &=~(1U<<0);
		MSTK -> LOAD =0U;
		MSTK -> VAL  =0U;
		/* Disable For Int */
		CLR_BIT(MSTK->CTRL , 1U );
	}
	else{}
	
	/**/
	MSTK_CallBack();
	/*Clear Flag By Read it*/
	L_u8Temp=GET_BIT(MSTK->CTRL ,16U );
	
	
}