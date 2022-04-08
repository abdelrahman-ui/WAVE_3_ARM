/*======================================================================================
===========================   - GPIO_interface.h			 ===========================
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


#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H
/*===========  Include  ===========*/
#include "STD_TYPES.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

/*======== Macros Of Port ========*/
#define _GPIOA_PORT   		      (0U)            /*!< GPIO (A) PORT  */
#define _GPIOB_PORT   		      (1U)            /*!< GPIO (B) PORT  */
#define _GPIOC_PORT   		      (2U)            /*!< GPIO (C) PORT  */
#define _GPIOD_PORT   		      (3U)            /*!< GPIO (D) PORT  */
#define _GPIOE_PORT   		      (4U)            /*!< GPIO (E) PORT  */
#define _GPIOH_PORT   		      (5U)            /*!< GPIO (H) PORT  */

/*======== Macros Of Pins ========*/
#define GPIO_PIN_0                ((u16)0x0001)   /*!< Pin 0 selected    */
#define GPIO_PIN_1                ((u16)0x0002)   /*!< Pin 1 selected    */
#define GPIO_PIN_2                ((u16)0x0004)   /*!< Pin 2 selected    */
#define GPIO_PIN_3                ((u16)0x0008)   /*!< Pin 3 selected    */
#define GPIO_PIN_4                ((u16)0x0010)   /*!< Pin 4 selected    */
#define GPIO_PIN_5                ((u16)0x0020)   /*!< Pin 5 selected    */
#define GPIO_PIN_6                ((u16)0x0040)   /*!< Pin 6 selected    */
#define GPIO_PIN_7                ((u16)0x0080)   /*!< Pin 7 selected    */
#define GPIO_PIN_8                ((u16)0x0100)   /*!< Pin 8 selected    */
#define GPIO_PIN_9                ((u16)0x0200)   /*!< Pin 9 selected    */
#define GPIO_PIN_10               ((u16)0x0400)   /*!< Pin 10 selected   */
#define GPIO_PIN_11               ((u16)0x0800)   /*!< Pin 11 selected   */
#define GPIO_PIN_12               ((u16)0x1000)   /*!< Pin 12 selected   */
#define GPIO_PIN_13               ((u16)0x2000)   /*!< Pin 13 selected   */
#define GPIO_PIN_14               ((u16)0x4000)   /*!< Pin 14 selected   */
#define GPIO_PIN_15               ((u16)0x8000)   /*!< Pin 15 selected   */
#define GPIO_PIN_All              ((u16)0xFFFF)   /*!< All pins selected */

/*======== Macros Of Mode ========*/
#define _MODE_INPUT      	      (0b00)          /*!< MODE ---> INPUT     */
#define _MODE_OUTPUT     	      (0b01)          /*!< MODE ---> OUTPUT    */
#define _MODE_ALTF       	      (0b10)          /*!< MODE ---> ALTF      */
#define _MODE_ANALOG     	      (0b11)          /*!< MODE ---> ANALOG    */

/*======== Macros Of Output Type ========*/
#define _OUTPUT_TYPE_PUSH_PULL    (0U)           /*!< OUTPUT TYPE ---> PUSH PULL   */  
#define _OUTPUT_TYPE_OPEN_DRAIN   (1U)           /*!< OUTPUT TYPE ---> OPEN DRAIN  */
/*======== Macros Of Speed ========*/

#define _OUTPUT_SPEED_LOW         (0x00000000U)  /*!< IO works at 2 MHz, please refer to the product datasheet */
#define _OUTPUT_SPEED_MEDUIM      (0x00000001U)  /*!< range 12,5 MHz to 50 MHz, please refer to the product datasheet */
#define _OUTPUT_SPEED_HIGH        (0x00000002U)  /*!< range 25 MHz to 100 MHz, please refer to the product datasheet  */
#define _OUTPUT_SPEED_VERY_HIGH   (0x00000003U)  /*!< range 50 MHz to 200 MHz, please refer to the product datasheet  */

/*======== Macros Of PULL  ========*/
#define _PULL_OFF                 (0x00000000U)   /*!< No Pull-up or Pull-down activation  */
#define _PULL_UP                  (0x00000001U)   /*!< Pull-up activation                  */
#define _PULL_DOWN                (0x00000002U)   /*!< Pull-down activation                */

/*======== Macros Write Data  ========*/
#define _HIGH                     (0U)
#define _LOW	                  (1U)

/*======== Macros ALTF  ========*/
#define _ALTFN_0                  (0b0000)      /*!< ALTF  --> 0  */
#define _ALTFN_1                  (0b0001)      /*!< ALTF  --> 1  */
#define _ALTFN_2                  (0b0010)      /*!< ALTF  --> 2  */
#define _ALTFN_3                  (0b0011)      /*!< ALTF  --> 3  */
#define _ALTFN_4                  (0b0100)      /*!< ALTF  --> 4  */
#define _ALTFN_5                  (0b0101)      /*!< ALTF  --> 5  */
#define _ALTFN_6                  (0b0110)      /*!< ALTF  --> 6  */
#define _ALTFN_7                  (0b0111)      /*!< ALTF  --> 7  */
#define _ALTFN_8                  (0b1000)      /*!< ALTF  --> 8  */
#define _ALTFN_9                  (0b1001)      /*!< ALTF  --> 9  */
#define _ALTFN_10                 (0b1010)      /*!< ALTF  --> 10 */
#define _ALTFN_11                 (0b1011)      /*!< ALTF  --> 11 */
#define _ALTFN_12                 (0b1100)      /*!< ALTF  --> 12 */
#define _ALTFN_13                 (0b1101)      /*!< ALTF  --> 13 */
#define _ALTFN_14                 (0b1110)      /*!< ALTF  --> 14 */
#define _ALTFN_15                 (0b1111)      /*!< ALTF  --> 15 */

/*======== ENUM For PORT  ========*/
typedef enum{
	GPIOA_PORT = 0,                            /*!< GPIO (A) PORT */
	GPIOB_PORT,                                /*!< GPIO (B) PORT */
	GPIOC_PORT,                                /*!< GPIO (C) PORT */
	GPIOD_PORT,                                /*!< GPIO (D) PORT */
	GPIOE_PORT,                                /*!< GPIO (E) PORT */
	GPIOH_PORT,                                /*!< GPIO (H) PORT */
}port_t;
/*======== ENUM For MODE  ========*/
typedef enum{
    INPUT = 0,                                 /*!< MODE ---> INPUT     */
    OUTPUT,                                    /*!< MODE ---> OUTPUT    */
    ALT,                                       /*!< MODE ---> ALTF      */
    ANALOUGE                                   /*!< MODE ---> ANALOG    */
}pinmode_t;
/*======== ENUM For Output Type  ========*/
typedef enum{
    PUSH_PULL = 0,                             /*!< OUTPUT TYPE ---> PUSH PULL   */ 
    OPEN_DRAIN                                 /*!< OUTPUT TYPE ---> OPEN DRAIN  */
}outputType_t;
/*======== ENUM For Output Speed  ========*/
typedef enum{ 
    LOW_SPEED = 0,                             /*!< IO works at 2 MHz, please refer to the product datasheet */
    MEDIUM_SPEED,                              /*!< range 12,5 MHz to 50 MHz, please refer to the product datasheet */
    HIGH_SPEED,                                /*!< range 25 MHz to 100 MHz, please refer to the product datasheet  */
    VERY_HIGH_SPEED                            /*!< range 50 MHz to 200 MHz, please refer to the product datasheet  */
}OutSpeed_t;
/*======== ENUM Of Speed ========*/
typedef enum{
    NORMAL = 0,                               /*!< No Pull-up or Pull-down activation  */
    PULL_UP,                                  /*!< Pull-up activation                  */
    PULL_DOWN                                 /*!< Pull-down activation                */
}PullType_t;

/*===========================     Function Prototypes     ===========================*/

/*===============   1-Function Set The Mode Of Pin	 ===============*/
void MGPIO_vSetPinMode(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8Mode  );
/*===============   2-Function Set The Type Of OutPut (OpenDrain = 0 , PushPull = 1)  ===============*/
void MGPIO_vSetPinOutPutType(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8OutPutType  );
/*===============	3-Function Set The Speed Of output pin  (LOW , Meduim , High ,VeryHaigh	===============*/
void MGPIO_vSetPinOutSpeed(u8 Copy_u32PortName ,u32 Copy_u32PinNum ,u32 Copy_u32OutSpeed );
/*===============   4-Function Set The PULL ( Almost Input ) ( OFF , UP , DOWN )  ===============*/
void MGPIO_vSetPullType(u8 Copy_u32PortName ,u32 Copy_u32PinNum ,u32 Copy_u32PullType );
/*===============   5-Function To Read Data From IDR  ===============*/
u8 MGPIO_u8ReadData(u8 copy_u8PORT ,u8 copy_u8PIN);
/*===============   6-Function To Write Data At ODR	Value = HIGH , LOW  ===============*/
void MGPIO_vWriteData(u8 Copy_u32PortName ,u8 Copy_u8PinNum ,u8 Copy_u8State);
/*===============   7-Function To Locked   ===============*/
void MGPIO_vPinLock(u8 Copy_u8PortNum ,u8 Copy_u8PinNum );
/*===============   7-Function To Set ALTF   ===============*/
void MGPIO_vSetPinAltFn( u8 Copy_u8PortNum ,u8 Copy_u8PinNum, u8 Copy_u8ALF );
/*===============   7-Function To Send One Byte  ===============*/
void MGPIO_vPortOutputOneByte(u8 Copy_u8Port, u8 Copy_u8Data, u8 Copy_u8StartBit);
/*==========================================================================================================*/
#endif //_GPIO_INTERFACE_H
/*===================================================================================
===============     guard of file will call on time in .c		   ==================
=====================================================================================*/
/*



typedef struct
{
  uint32_t Pin;     
                    

  uint32_t Mode;    
                    

  uint32_t Pull;    
                    

  uint32_t Speed;   
                    

  uint32_t Alternate
                    
}GPIO_InitTypeDef;







*/