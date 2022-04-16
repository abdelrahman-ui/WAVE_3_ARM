/*
 * LCD_cfg.h
 *
 *  Created on: Aug 31, 2018
 *      Author: homo9
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_


//Data registers
#define DIO_u8DataPort   GPIOA_PORT

/*Control register*/
#define DIO_u8ContPort   GPIOC_PORT

/*control Pins*/
//RS PIN
#define RS_PIN  7
//RW PIN
#define RW_PIN  6
//E PIN
#define E_PIN   5


#endif /* LCD_CFG_H_ */
