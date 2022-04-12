







/*85 */
void MNVIC_vEnableINT(u8 Copy_u8IntNUM)
{
if(Copy_u8IntNUM <=31U )	
 {	
	 NVIC_ISER_0 =(1U<<Copy_u8IntNUM);
 }
 else if (Copy_u8IntNUM <=63U)
 {
	 Copy_u8IntNUM-=32;
	 NVIC_ISER_1 =(1U<<Copy_u8IntNUM);
 }
  else if (Copy_u8IntNUM <=85U)
 {
	 Copy_u8IntNUM-=64;
	 NVIC_ISER_2 =(1U<<Copy_u8IntNUM);
 }
  else
  {
   /* ERROR */
  }	  
	
	
}


/* EXTI0  --> 32*/
void NVIC_EnableIRQ(u8 IRQn)
{
	NVIC->ISER[IRQn / 32]= (1U << (IRQn %32 ));
	
}



/***********************************************************************************/


void MNVIC_vDisableINT(u8 Copy_u8IntNUM)
{
	if(Copy_u8IntNUM <=31U )	
 {
	 
	 NVIC_ICER_0 =(1U<<Copy_u8IntNUM);
 }
 else if (Copy_u8IntNUM <=63U)
 {
	 Copy_u8IntNUM-=32;
	 NVIC_ICER_1 =(1U<<Copy_u8IntNUM);
 }
  else if (Copy_u8IntNUM <=85U)
 {
	 Copy_u8IntNUM-=64;
	 NVIC_ICER_2 =(1U<<Copy_u8IntNUM);
 }
  else
  {
   /* ERROR */
  }	
	
}

void NVIC_DisableIRQ(u8 IRQn)
{
	P_ICERx[IRQn / 32]= (1U << (IRQn %32 ));
	
}

/*****************************************************************/

void MNVIC_vSetPendingFlag(u8 Copy_u8IntNUM)
{
	
	if(Copy_u8IntNUM <=31U )	
 {
	 NVIC_ISPR_0 =(1U<<Copy_u8IntNUM);
 }
 else if (Copy_u8IntNUM <=63U)
 {
	 Copy_u8IntNUM-=32;
	 NVIC_ISPR_1 =(1U<<Copy_u8IntNUM);
 }
  else if (Copy_u8IntNUM <=85U)
 {
	 Copy_u8IntNUM-=64;
	 NVIC_ISPR_2 =(1U<<Copy_u8IntNUM);
 }
  else
  {
   /* ERROR */
  }	
	

}


void NVIC_ClearPendingIRQ(u8 IRQn)
{
	NVIC->ISPR[IRQn / 32]= (1U << (IRQn %32 ));
	
}



/**********************************************************/

void MNVIC_vClearPendingFlag(u8 Copy_u8IntNUM)
{
	
		if(Copy_u8IntNUM <=31U )	
 {
	 NVIC_ICPR_0 =(1U<<Copy_u8IntNUM);
 }
 else if (Copy_u8IntNUM <=63U) /* 32 */
 {  
	 Copy_u8IntNUM-=32;
	 NVIC_ICPR_1 =(1U<<Copy_u8IntNUM);
 }
  else if (Copy_u8IntNUM <=85U)
 {
	 Copy_u8IntNUM-=64;
	 NVIC_ICPR_2 =(1U<<Copy_u8IntNUM);
 }
  else
  {
   /* ERROR */
  }	
	

	
}

u8 NVIC_GetPendingIRQ(u8 IRQn)
{
	
	NVIC->ICPR[IRQn / 32]= (1U << (IRQn %32 ));
	
}






u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNUM)
{
	u8 L_u8ActiveFlag = 0 ;
	if(Copy_u8IntNUM <=31U)
	{
		L_u8ActiveFlag = GET_BIT( NVIC_IABR_0 ,Copy_u8IntNUM );
	}
	else if (Copy_u8IntNUM <=31U)
	{
		Copy_u8IntNUM-=32;
		L_u8ActiveFlag = GET_BIT( NVIC_IABR_1 ,Copy_u8IntNUM );
	}
	else if (Copy_u8IntNUM <=63U)
	{
		Copy_u8IntNUM-=64;
		L_u8ActiveFlag = GET_BIT( NVIC_IABR_2 ,Copy_u8IntNUM );
	}
	else
	{
		/* Return Error */
	}
	return L_u8ActiveFlag ;
	
	
}


/****************************************************************************************/

/*

1- 0X05FA0300 (0XX)
2- 0X05FA0400
3- 0X05FA0500
4- 0X05FA0600
5- 0X05FA0700


*/


void MNVIC_vSetGroupSubGroupPriority(u8 Copy_u8IntNUM , u8 Copy_u8GroupPriority , u8 Copy_u8SubGroupPriority ,u32 Copy_PriorityCFG  )
{
	switch(Copy_PriorityCFG)
	{
	 case GROUP_4_SUB_0 :
				/* password + cnf*/
				SCB_AIRCR  |= 0X05FA0300;
				NVIC_IPR[Copy_u8IntNUM] = (u8) (Copy_u8GroupPriority<<4U );
				

	 break ;
	 case GROUP_3_SUB_1 :
				/* password + cnf*/
				SCB_AIRCR  |= 0X05FA0400;
				NVIC_IPR[Copy_u8IntNUM] = (u8) (Copy_u8GroupPriority<<5U )|(Copy_u8GroupPriority <<4U );

	 break ;
	 case GROUP_2_SUB_2 :
	 				/* password + cnf*/
				SCB_AIRCR  |= 0X05FA0500;
				NVIC_IPR[Copy_u8IntNUM] = (u8) (Copy_u8GroupPriority<<6U )|(Copy_u8GroupPriority <<4U );
				


	 break ;
	 case GROUP_1_SUB_3 :
	 	 				/* password + cnf*/
				SCB_AIRCR  |= 0X05FA0600;
				NVIC_IPR[Copy_u8IntNUM] = (u8) (Copy_u8GroupPriority<<7U )|(Copy_u8GroupPriority <<4U );


	 break ;
	 case GROUP_0_SUB_4 :
					 	 				/* password + cnf*/
				SCB_AIRCR  |= 0X05FA0700;
				NVIC_IPR[Copy_u8IntNUM] = (u8)(Copy_u8GroupPriority <<4U );

	 break ;
		
		
		
	
		
	}
	

	
}



void NVIC_vSetGroupSubGroupPriority(u8 Copy_u8IntNUM , u8 Copy_u8GroupPriority , u8 Copy_u8SubGroupPriority )
{
	#if CNF_GROUP_SUB == GROUP_4_SUB_0 
			/* password + cnf*/
			SCB_AIRCR  |= 0X05FA0300;
			NVIC_IPR[Copy_u8IntNUM] = (u8) (Copy_u8GroupPriority<<4U )|(Copy_u8SubGroupPriority << 0U  );

	#elif CNF_GROUP_SUB == GROUP_3_SUB_1 
						/* password + cnf*/
				SCB_AIRCR  |= 0X05FA0400;
				NVIC_IPR[Copy_u8IntNUM] = (u8) (Copy_u8GroupPriority<<5U )|(Copy_u8SubGroupPriority <<4U );
	
	
	#elif CNF_GROUP_SUB == GROUP_2_SUB_2 
						/* password + cnf*/
				SCB_AIRCR  |= 0X05FA0500;
				NVIC_IPR[Copy_u8IntNUM] = (u8) (Copy_u8GroupPriority<<6U )|(Copy_u8SubGroupPriority <<4U );
	
	
	#elif CNF_GROUP_SUB == GROUP_1_SUB_3 
						/* password + cnf*/
				SCB_AIRCR  |= 0X05FA0600;
				NVIC_IPR[Copy_u8IntNUM] = (u8) (Copy_u8GroupPriority<<7U )|(Copy_u8SubGroupPriority <<4U );
	
	
	#elif CNF_GROUP_SUB == GROUP_0_SUB_4
					 				/* password + cnf*/
				SCB_AIRCR  |= 0X05FA0700;
				NVIC_IPR[Copy_u8IntNUM] = (u8)(Copy_u8SubGroupPriority <<4U )|(Copy_u8GroupPriority<<0U);

	#endif 
	

}