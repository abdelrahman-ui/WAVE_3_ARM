






#ifndef _NVIC_PRIVATE_H
#define _NVIC_PRIVATE_H

/* BASE ADDRESS*/

#define _NVIC_BASS_ADDRESS        0xE000E100 

typedef struct{

	volatile u32 ISER    [ 32 ];                  /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
	                                             
	volatile u32 ICER    [ 32 ];                  /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
	                                             
	volatile u32 ISPR    [ 32 ];                  /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
	                                             
	volatile u32 ICPR    [ 32 ];                  /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
	                                             
	volatile u32 IAPR    [ 32 ];                  /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
	                                             
	volatile u32 RESERVED[ 32 ];                  /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
	                                             
	volatile u8 IPR      [ 128];                  /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */

}NVIC;

/*
typedef struct
{
  __IOM uint32_t ISER[8U];              
        uint32_t RESERVED0[24U];
  __IOM uint32_t ICER[8U];              
        uint32_t RESERVED1[24U];
  __IOM uint32_t ISPR[8U];              
        uint32_t RESERVED2[24U];
  __IOM uint32_t ICPR[8U];              
        uint32_t RESERVED3[24U];
  __IOM uint32_t IABR[8U];              
        uint32_t RESERVED4[56U];
  __IOM uint8_t  IP[240U];              
        uint32_t RESERVED5[644U];
  __OM  uint32_t STIR;                  
}  NVIC_Type;



#define SCS_BASE            (0xE000E000UL)                            //< System Control Space Base Address 
#define NVIC_BASE           (SCS_BASE +  0x0100UL)                    //!< NVIC Base Address 
#define NVIC                ((NVIC_Type      *)     NVIC_BASE     )   //!< NVIC configuration struct 




/* Sof

*/










/* - Enable for External */
#define P_ISERx                          (((u32 *)(0xE000E100)))

#define NVIC_ISER_0                      (*((u32 *)(0xE000E100))) /* Enable External Interrputs from 0 to 31 */ 
#define NVIC_ISER_1                      (*((u32 *)(0xE000E104))) /* Enable External Interrputs from 32 to 63 */ 
#define NVIC_ISER_2                      (*((u32 *)(0xE000E108))) /* Enable External Interrputs from 64 to 85 */ 
/* - Disable for External */
#define P_ICERx                           (((u32 *)(0XE000E180))) 

#define NVIC_ICER_0                      (*((u32 *)(0XE000E180))) /* Disable External Interrputs from 0 to 31 */ 
#define NVIC_ICER_1                      (*((u32 *)(0XE000E184))) /* Disable External Interrputs from 32 to 63 */ 
#define NVIC_ICER_2                      (*((u32 *)(0XE000E188))) /* Disable External Interrputs from 64 to 85 */ 
/* - Set pendding External */

#define P_ISPRx                           (((u32 *)(0XE000E180))) 

#define NVIC_ISPR_0                      (*((u32 *)(0XE000E200))) /* Enable  for Pending Flag  0 to 31 */ 
#define NVIC_ISPR_1                      (*((u32 *)(0XE000E204))) /* Enable  for Pending Flag  from 32 to 63 */ 
#define NVIC_ISPR_2                      (*((u32 *)(0XE000E208))) /* Enable  for Pending Flag  from 64 to 85 */
/* - Set pendding External */
#define NVIC_ICPR_0                      (*((u32 *)(0XE000E280))) /* Enable  for Pending Flag  0 to 31 */ 
#define NVIC_ICPR_1                      (*((u32 *)(0XE000E284))) /* Enable  for Pending Flag  from 32 to 63 */ 
#define NVIC_ICPR_2                      (*((u32 *)(0XE000E288))) /* Enable  for Pending Flag  from 64 to 85 */

#define NVIC_IABR_0                      (*((volatile u32 *)(0XE000E300))) /* Enable  for Pending Flag  0 to 31 */ 
#define NVIC_IABR_1                      (*((volatile u32 *)(0XE000E304))) /* Enable  for Pending Flag  from 32 to 63 */ 
#define NVIC_IABR_2                      (*((volatile u32 *)(0XE000E308))) /* Enable  for Pending Flag  from 64 to 85 */


#define NVIC_IPR                        (((u8 *)(0XE000E400)))

 

#define SCB_BASS_ADDRESS    0xE000ED00  

#define SCB_AIRCR       (*((volatile u32 *)(SCB_BASS_ADDRESS+ 0X0C )))


#define GROUP_4_SUB_0            0U
#define GROUP_3_SUB_1            1U
#define GROUP_2_SUB_2            2U
#define GROUP_1_SUB_3            3U
#define GROUP_0_SUB_4            4U




#endif 