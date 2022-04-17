






void MSPI_vInit(void)
{
#if MSPI_1_STATUS == MSPI1_ENABLE 
/************************************/
		#if MSPI1_CLK_POL == IDLE_HIGH
		
		#elif MSPI1_CLK_POL == IDLE_LOW 
		
		#endif
/************************************/		
		#if MSPI1_CLK_PHA == READ_WRITE
		
		#elif MSPI1_CLK_PHA == WRITE_READ
		
		#endif
/************************************/			
		#if MSPI1_MASTER_SLAVE == MASTER
		
		#elif MSPI1_MASTER_SLAVE == SLAVE
		
		#endif
	
/************************************/		
		#if MSPI1_DATA_ORDER == MSB
		
		#elif MSPI1_DATA_ORDER == LSB
		
		#endif
/************************************/	
		#if MSPI1_SSM == SWITCH_ON
		
		#elif MSPI1_SSM == SWITCH_OFF
		
		#endif
/************************************/			
		#if MSPI1_SSI == VCC
		
		#elif MSPI1_SSI == GND
		
		#endif
/************************************/		
		#if MSPI1_DATA_SIZE == DATA_8
		
		#elif MSPI1_DATA_SIZE == DATA_16
		
		#endif
/***********************************/
		#if MSPI1_INT == DISABLE
		
		#elif MSPI1_INT == TX_EN

		#elif MSPI1_INT == RX_EN
		
		#endif 
		
/***********************************/
		SPI_1->CR1 &=0XFFC7 ;
		SPI_1->CR1 |=(MSPI_1_PESCALLER <<3U);
/***********************************/		
		/* Enable SPI1 */
#elif MSPI_1_STATUS == MSPI1_DISABLE
	/**/
#endif 

}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}