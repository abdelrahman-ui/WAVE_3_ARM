/***********************************************
 * NAME     : GPIO_interface
 * Author   : Hossam Mustafa
 * created  : 02/09/2022
 * Version  : v 1.0
 * Notes    :
 * *********************************************/

/***********************************************
             Guard
 * *********************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "00_LIB/STD_types.h"

typedef enum{
	GPIOA_PORT = 0,
	GPIOB_PORT,
	GPIOC_PORT,
	GPIOD_PORT,
	GPIOE_PORT,
	GPIOH_PORT,
}port_t;



typedef enum{
    INPUT = 0,
    OUTPUT,
    ALT,
    ANALOUGE
}pinmode_t;
void MGPIO_vSetPinMode(port_t copy_port, u8 copy_pin, pinmode_t copy_pin_mode);

typedef enum{
    PUSH_PULL = 0,
    OPEN_DRAIN
}outputType_t;
void MGPIO_vSetOutputType(port_t copy_port, u8 copy_pin, outputType_t copy_out_type);


typedef enum{
    LOW_SPEED = 0,
    MEDIUM_SPEED,
    HIGH_SPEED,
    VERY_HIGH_SPEED
}OutSpeed_t;
void MGPIO_vSetPinOutSpeed(port_t copy_port, u8 copy_pin, pinmode_t copy_pin_OutSpeed);


typedef enum{
    NORMAL = 0,
    PULL_UP,
    PULL_DOWN
}PullType_t;
void MGPIO_vSetPullType(port_t copy_port, u8 copy_pin, PullType_t copy_pull_type);


u16 MGPIO_u16ReadPortData(port_t copy_port);
u8 MGPIO_u8ReadPinValue(port_t copy_port, u8 copy_pin);

void MGPIO_vPortOutput(port_t copy_port,u16 copy_data);
void MGPIO_vPortOutputOneByte(port_t copy_port,u8 copy_data,u8 copy_start_bit);
void MGPIO_vPinOutput(port_t copy_port, u8 copy_pin, u8 copy_pin_value);

void MGPIO_vPinAltFun(port_t copy_port, u8 copy_pin, u8 copy_pin_Fun);
#endif // GPIO_INTERFACE_H
