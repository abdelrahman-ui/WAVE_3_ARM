








#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H
/*		 Enables an interrupt 	   -------> ISERx		need Interrput Number	From Vector Table Referance Manual			*/
void MNVIC_vEnableINT(u8 Copy_u8IntNUM);
/*		Disables an interrupt 				*/
void MNVIC_vDisableINT(u8 Copy_u8IntNUM);

void MNVIC_vSetPendingFlag(u8 Copy_u8IntNUM);

void MNVIC_vClearPendingFlag(u8 Copy_u8IntNUM);

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNUM);

/**/ 
void MNVIC_vSetGroupSubGroupPriority();






#endif