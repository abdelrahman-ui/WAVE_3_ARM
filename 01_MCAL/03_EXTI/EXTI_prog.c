







void (*EXTI0_CallBack )(void);

/**/
void MEXTI_vEnableLine(u8 Copy_u8LineNUM)
{
	SET_BIT(EXTI->IMR ,Copy_u8LineNUM );
}

/**/
void MEXTI_vDisableLine(u8 Copy_u8LineNUM)
{
	CLR_BIT(EXTI->IMR ,Copy_u8LineNUM );
}

/**/
void MEXTI_vEventType(u8 Copy_u8LineNUM  )
{
	
#if _EVENT_TYPE == 	_RAISE_STATE
	SET_BIT(EXTI->RTSR ,Copy_u8LineNUM );
	CLR_BIT(EXTI->FTSR ,Copy_u8LineNUM ); 
#elif EVENT_TYPE ==  _FALL_STATE
	SET_BIT(EXTI->FTSR ,Copy_u8LineNUM );
	CLR_BIT(EXTI->RTSR ,Copy_u8LineNUM );
#elif EVENT_TYPE ==  _ON_CHANGE_STATE
	SET_BIT(EXTI->RTSR ,Copy_u8LineNUM );
	SET_BIT(EXTI->FTSR ,Copy_u8LineNUM ); 

#endif

	
}
/**/
void MEXTI_vTrigSW(u8 Copy_u8LineNUM  )
{
	SET_BIT(EXTI->SWIER ,Copy_u8LineNUM );
}
/**/
u8 MEXTI_vGetPending(u8 Copy_u8LineNUM  )
{
	u8 L_u8PendingState = 0U ;
	L_u8PendingState = GET_BIT( EXTI -> PR,Copy_u8LineNUM);
	return L_u8PendingState ; 
}

void MEXTI_vSelectPort(u8 Copy_u8LineNUM , u8 Copy_u8PortID  )
{
	if(Copy_u8LineNUM  <= 3U)
	{
		/* Safty --> 0000 */
		SYSCFG_EXTICR1 &=~(0b1111 <<(4U*Copy_u8LineNUM));
		/*  */
		SYSCFG_EXTICR1 |=(Copy_u8PortID <<(4U*Copy_u8LineNUM));
		
	}
	// 4 == 0
	else if (Copy_u8LineNUM  <= 7U)
	{
		Copy_u8LineNUM -=4 ;
		/* Safty --> 0000 */
		SYSCFG_EXTICR2 &=~(0b1111 <<(4U*Copy_u8LineNUM));
		/*  */
		SYSCFG_EXTICR2 |=(Copy_u8PortID <<(4U*Copy_u8LineNUM));
		
	}
	// 4 == 0
	else if (Copy_u8LineNUM  <= 11U)
	{
		Copy_u8LineNUM -=8 ;
		/* Safty --> 0000 */
		SYSCFG_EXTICR3 &=~(0b1111 <<(4U*Copy_u8LineNUM));
		/*  */
		SYSCFG_EXTICR3 |=(Copy_u8PortID <<(4U*Copy_u8LineNUM));
		
	}
		else if (Copy_u8LineNUM  <= 15U)
	{
		Copy_u8LineNUM -=12 ;
		/* Safty --> 0000 */
		SYSCFG_EXTICR4 &=~(0b1111 <<(4U*Copy_u8LineNUM));
		/*  */
		SYSCFG_EXTICR4 |=(Copy_u8PortID <<(4U*Copy_u8LineNUM));
		
	}
	
	
	
	
}


/********************************/
void EXTI0_vSetCallBack( void (*ptr)(void) )
{
	EXTI0_CallBack = ptr ;
}
/*********************************/

/*********************************/
/*static*/ void EXTI0_IRQHandler(void)
{
	SET_BIT(EXTI -> PR , 0);
	EXTI0_CallBack();
	
}

/**************************************/




