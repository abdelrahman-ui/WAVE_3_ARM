/***********************************************
 * NAME     : GPIO_programe
 * Author   : Hossam Mustafa
 * created  : 02/10/2022
 * Version  : v 1.0
 * Notes    :
 * *********************************************/


#include "GPIO_private.h"
#include "GPIO_config.h"
#include "GPIO_interface.h"
#include "00_LIB/util.h"




/*						Start function				*/
void MGPIO_vSetPinMode(port_t copy_port, u8 copy_pin, pinmode_t copy_pin_mode){

	switch(copy_port){
		case GPIOA_PORT :
			GPIOA_REG->MODER |= (copy_pin_mode << (2*copy_pin));
			break;
		case GPIOB_PORT :
			GPIOB_REG->MODER |= (copy_pin_mode << (2*copy_pin));
			break;
		case GPIOC_PORT :
			GPIOC_REG->MODER |= (copy_pin_mode << (2*copy_pin));
			break;
		case GPIOD_PORT :
			GPIOD_REG->MODER |= (copy_pin_mode << (2*copy_pin));
			break;
		case GPIOE_PORT :
			GPIOE_REG->MODER |= (copy_pin_mode << (2*copy_pin));
			break;
		case GPIOH_PORT :
			GPIOH_REG->MODER |= (copy_pin_mode << (2*copy_pin));
			break;
	}
}
/*						End function				*/



/*						Start function				*/
void MGPIO_vSetOutputType(port_t copy_port, u8 copy_pin, outputType_t copy_out_type){
	switch(copy_port){
		case GPIOA_PORT :
			GPIOA_REG->OTYPER |= (copy_out_type << (copy_pin));
			break;
		case GPIOB_PORT :
			GPIOB_REG->OTYPER |= (copy_out_type << (copy_pin));
			break;
		case GPIOC_PORT :
			GPIOC_REG->OTYPER |= (copy_out_type << (copy_pin));
			break;
		case GPIOD_PORT :
			GPIOD_REG->OTYPER |= (copy_out_type << (copy_pin));
			break;
		case GPIOE_PORT :
			GPIOE_REG->OTYPER |= (copy_out_type << (copy_pin));
			break;
		case GPIOH_PORT :
			GPIOH_REG->OTYPER |= (copy_out_type << (copy_pin));
			break;
	}
}
/*						End function				*/






/*						Start function				*/
void MGPIO_vSetPinOutSpeed(port_t copy_port, u8 copy_pin, pinmode_t copy_pin_OutSpeed){
	switch(copy_port){
		case GPIOA_PORT :
			GPIOA_REG->OSPEEDER &= ~(0b11 << (2*copy_pin)); //Clear first before write
			GPIOA_REG->OSPEEDER |= (copy_pin_OutSpeed << (2*copy_pin));
			break;
		case GPIOB_PORT :
			GPIOB_REG->OSPEEDER &= ~(0b11 << (2*copy_pin)); //Clear first before write
			GPIOB_REG->OSPEEDER |= (copy_pin_OutSpeed << (2*copy_pin));
			break;
		case GPIOC_PORT :
			GPIOC_REG->OSPEEDER &= ~(0b11 << (2*copy_pin)); //Clear first before write
			GPIOC_REG->OSPEEDER |= (copy_pin_OutSpeed << (2*copy_pin));
			break;
		case GPIOD_PORT :
			GPIOD_REG->OSPEEDER &= ~(0b11 << (2*copy_pin)); //Clear first before write
			GPIOD_REG->OSPEEDER |= (copy_pin_OutSpeed << (2*copy_pin));
			break;
		case GPIOE_PORT :
			GPIOE_REG->OSPEEDER &= ~(0b11 << (2*copy_pin)); //Clear first before write
			GPIOE_REG->OSPEEDER |= (copy_pin_OutSpeed << (2*copy_pin));
			break;
		case GPIOH_PORT :
			GPIOH_REG->OSPEEDER &= ~(0b11 << (2*copy_pin)); //Clear first before write
			GPIOH_REG->OSPEEDER |= (copy_pin_OutSpeed << (2*copy_pin));
			break;
	}
}

/*						End function				*/


/*						Start function				*/
void MGPIO_vSetPullType(port_t copy_port, u8 copy_pin, PullType_t copy_pull_type){
	switch(copy_port){
		case GPIOA_PORT :
			GPIOA_REG->PUPDR &= ~(0b11 << (2*copy_pin)); //Clear first before write
			GPIOA_REG->PUPDR |= (copy_pull_type << (2*copy_pin));
			break;
		case GPIOB_PORT :
			GPIOB_REG->PUPDR &= ~(0b11 << (2*copy_pin)); //Clear first before write
			GPIOB_REG->PUPDR |= (copy_pull_type << (2*copy_pin));
			break;
		case GPIOC_PORT :
			GPIOC_REG->PUPDR &= ~(0b11 << (2*copy_pin)); //Clear first before write
			GPIOC_REG->PUPDR |= (copy_pull_type << (2*copy_pin));
			break;
		case GPIOD_PORT :
			GPIOD_REG->PUPDR &= ~(0b11 << (2*copy_pin)); //Clear first before write
			GPIOD_REG->PUPDR |= (copy_pull_type << (2*copy_pin));
			break;
		case GPIOE_PORT :
			GPIOE_REG->PUPDR &= ~(0b11 << (2*copy_pin)); //Clear first before write
			GPIOE_REG->PUPDR |= (copy_pull_type << (2*copy_pin));
			break;
		case GPIOH_PORT :
			GPIOH_REG->PUPDR &= ~(0b11 << (2*copy_pin)); //Clear first before write
			GPIOH_REG->PUPDR |= (copy_pull_type << (2*copy_pin));
			break;
	}
}

/*						End function				*/





/*						Start function				*/
u16 MGPIO_u16ReadPortData(port_t copy_port){
	u16 L_u16data = 0;
	switch(copy_port){
		case GPIOA_PORT :
			L_u16data = (u16) GPIOA_REG->IDR;
			break;
		case GPIOB_PORT :
			L_u16data = (u16) GPIOB_REG->IDR;
			break;
		case GPIOC_PORT :
			L_u16data = (u16) GPIOC_REG->IDR;
			break;
		case GPIOD_PORT :
			L_u16data = (u16) GPIOD_REG->IDR;
			break;
		case GPIOE_PORT :
			L_u16data = (u16) GPIOE_REG->IDR;
			break;
		case GPIOH_PORT :
			L_u16data = (u16) GPIOH_REG->IDR;
			break;
	}
	return L_u16data;
}

/*						End function				*/





/*						Start function				*/
u8 MGPIO_u8ReadPinValue(port_t copy_port, u8 copy_pin){
	u8 L_u8data = 0;
	switch(copy_port){
		case GPIOA_PORT :
			L_u8data = GET_BIT( GPIOA_REG->IDR, copy_pin);
			break;
		case GPIOB_PORT :
			L_u8data = GET_BIT( GPIOB_REG->IDR, copy_pin);
			break;
		case GPIOC_PORT :
			L_u8data = GET_BIT( GPIOC_REG->IDR, copy_pin);
			break;
		case GPIOD_PORT :
			L_u8data = GET_BIT( GPIOD_REG->IDR, copy_pin);
			break;
		case GPIOE_PORT :
			L_u8data = GET_BIT( GPIOE_REG->IDR, copy_pin);
			break;
		case GPIOH_PORT :
			L_u8data = GET_BIT( GPIOH_REG->IDR, copy_pin);
			break;
	}
	return L_u8data;
}
/*						End function				*/




/*						Start function				*/
void MGPIO_vPortOutput(port_t copy_port, u16 copy_data){
	switch(copy_port){
		case GPIOA_PORT :
			GPIOA_REG->ODR = copy_data;
			break;
		case GPIOB_PORT :
			GPIOB_REG->ODR = copy_data;
			break;
		case GPIOC_PORT :
			GPIOC_REG->ODR = copy_data;
			break;
		case GPIOD_PORT :
			GPIOD_REG->ODR = copy_data;
			break;
		case GPIOE_PORT :
			GPIOE_REG->ODR = copy_data;
			break;
		case GPIOH_PORT :
			GPIOH_REG->ODR = copy_data;
			break;
	}

}

/*						End function				*/




/*						Start function				*/
void MGPIO_vPortOutputOneByte(port_t copy_port, u8 copy_data, u8 copy_start_bit){
	switch(copy_port){
		case GPIOA_PORT :
			GPIOA_REG->ODR = (GPIOA_REG->ODR & ~(0xff << (copy_start_bit ))) | (copy_data << (copy_start_bit));
			break;
		case GPIOB_PORT :
			GPIOB_REG->ODR = (GPIOB_REG->ODR & ~(0xff << (copy_start_bit))) | (copy_data << (copy_start_bit));
			break;
		case GPIOC_PORT :
			GPIOC_REG->ODR = (GPIOC_REG->ODR & ~(0xff << (copy_start_bit ))) | (copy_data << (copy_start_bit));
			break;
		case GPIOD_PORT :
			GPIOD_REG->ODR = (GPIOD_REG->ODR & ~(0xff << (copy_start_bit))) | (copy_data << (copy_start_bit));
			break;
		case GPIOE_PORT :
			GPIOE_REG->ODR = (GPIOE_REG->ODR & ~(0xff << (copy_start_bit))) | (copy_data << (copy_start_bit));
			break;
		case GPIOH_PORT :
			GPIOH_REG->ODR = (GPIOH_REG->ODR & ~(0xff << (copy_start_bit ))) | (copy_data << (copy_start_bit));
			break;
	}

}
/*						End function				*/



/*						Start function				*/
void MGPIO_vPinOutput(port_t copy_port, u8 copy_pin, u8 copy_pin_value){
	u32 L_u32RegesterValue = 0;
	if(copy_pin_value == 0){
		L_u32RegesterValue = (1 << (copy_pin + 16));
	}
	else{
		L_u32RegesterValue = (1 << (copy_pin));
	}

	switch(copy_port){
		case GPIOA_PORT :
			GPIOA_REG->BSRR = L_u32RegesterValue;
			break;
		case GPIOB_PORT :
			GPIOB_REG->BSRR = L_u32RegesterValue;
			break;
		case GPIOC_PORT :
			GPIOC_REG->BSRR = L_u32RegesterValue;
			break;
		case GPIOD_PORT :
			GPIOD_REG->BSRR = L_u32RegesterValue;
			break;
		case GPIOE_PORT :
			GPIOE_REG->BSRR = L_u32RegesterValue;
			break;
		case GPIOH_PORT :
			GPIOH_REG->BSRR = L_u32RegesterValue;
			break;
	}

}
/*						End function				*/


/*						Start function				*/
void MGPIO_vPinAltFun(port_t copy_port, u8 copy_pin, u8 copy_pin_Fun){
	switch(copy_port){
		case GPIOA_PORT :
			GPIOA_REG->AFR[copy_pin/8] |= copy_pin_Fun << ((copy_pin % 8)*4);
			break;
		case GPIOB_PORT :
			GPIOB_REG->AFR[copy_pin/8] |= copy_pin_Fun << ((copy_pin % 8)*4);
			break;
		case GPIOC_PORT :
			GPIOC_REG->AFR[copy_pin/8] |= copy_pin_Fun << ((copy_pin % 8)*4);
			break;
		case GPIOD_PORT :
			GPIOD_REG->AFR[copy_pin/8] |= copy_pin_Fun << ((copy_pin % 8)*4);
			break;
		case GPIOE_PORT :
			GPIOE_REG->AFR[copy_pin/8] |= copy_pin_Fun << ((copy_pin % 8)*4);
			break;
		case GPIOH_PORT :
			GPIOH_REG->AFR[copy_pin/8] |= copy_pin_Fun << ((copy_pin % 8)*4);
			break;
	}
}

/*						End function				*/
