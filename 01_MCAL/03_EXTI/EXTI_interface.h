




#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_


#define _EXTI_LINE_0                 0U
#define _EXTI_LINE_1                 1U
#define _EXTI_LINE_2                 2U
#define _EXTI_LINE_3                 3U
#define _EXTI_LINE_4                 4U
#define _EXTI_LINE_5                 5U
#define _EXTI_LINE_6                 6U
#define _EXTI_LINE_7                 7U
#define _EXTI_LINE_8                 8U
#define _EXTI_LINE_9                 9U
#define _EXTI_LINE_10                10U
#define _EXTI_LINE_11                11U
#define _EXTI_LINE_12                12U
#define _EXTI_LINE_13                13U
#define _EXTI_LINE_14                14U
#define _EXTI_LINE_15                15U



#define _RAISE_STATE                    0U              
#define _FALL_STATE                     1U
#define _ON_CHANGE_STATE                2U



#define _PORT_A_EXTI                 (0b0000) 
#define _PORT_B_EXTI                 (0b0001) 
#define _PORT_C_EXTI                 (0b0010)
#define _PORT_D_EXTI                 (0b0011)
#define _PORT_E_EXTI                 (0b0100)
#define _PORT_H_EXTI                 (0b0111)



void MEXTI_vEnableLine(u8 Copy_u8LineNUM);

void MEXTI_vDisableLine(u8 Copy_u8LineNUM);

void MEXTI_vEventType(u8 Copy_u8LineNUM  );

void MEXTI_vTrigSW(u8 Copy_u8LineNUM  );


u8 MEXTI_vGetPending(u8 Copy_u8LineNUM  );

void MEXTI_vSelectPort(u8 Copy_u8LineNUM , u8 Copy_u8PortID  );







#endif