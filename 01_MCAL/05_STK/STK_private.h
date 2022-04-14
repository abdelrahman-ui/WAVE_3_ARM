






#ifndef _STK_PRIVATE_H
#define _STK_PRIVATE_H


typedef struct 
{
	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VAL   ;
	volatile u32 CALIB ;
	
}MSTK_t;

/**/
#define SYSTICK_BASS_ADDRESS  0xE000E010
/**/
#define MSTK               ((MSTK_t *)(SYSTICK_BASS_ADDRESS ))


#endif
