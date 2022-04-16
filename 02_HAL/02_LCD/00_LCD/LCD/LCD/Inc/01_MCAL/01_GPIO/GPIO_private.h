/***********************************************
 * NAME     : GPIO_private
 * Author   : Hossam Mustafa
 * created  : 02/08/2022
 * Version  : v 1.0
 * Notes    :
 * *********************************************/

/***********************************************
             Guard
 * *********************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#include "00_LIB/STD_types.h"

/* vendor AHB1 */
#define GPIOA_BASE_ADDRESS    0x40020000
#define GPIOB_BASE_ADDRESS    0x40020400
#define GPIOC_BASE_ADDRESS    0x40020800
#define GPIOD_BASE_ADDRESS    0x40020c00
#define GPIOE_BASE_ADDRESS    0x40021000
#define GPIOH_BASE_ADDRESS    0x40021c00

typedef struct 
{
    u32 MODER;
    u32 OTYPER;
    u32 OSPEEDER;
    u32 PUPDR;
    u32 IDR;
    u32 ODR;
    u32 BSRR;
    u32 LCKR;
    u32 AFR[2];
} GPIO_t;

#define   GPIOA_REG    ((volatile GPIO_t*)(GPIOA_BASE_ADDRESS))
#define   GPIOB_REG    ((volatile GPIO_t*)(GPIOB_BASE_ADDRESS))
#define   GPIOC_REG    ((volatile GPIO_t*)(GPIOC_BASE_ADDRESS))
#define   GPIOD_REG    ((volatile GPIO_t*)(GPIOD_BASE_ADDRESS))
#define   GPIOE_REG    ((volatile GPIO_t*)(GPIOE_BASE_ADDRESS))
#define   GPIOH_REG    ((volatile GPIO_t*)(GPIOH_BASE_ADDRESS))

#endif // GPIO_PRIVATE_H
