










#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H





void MSPI_vInit(u8 Copy_u8SPINUM , u8 Copy_u8DeviceMode , u8 Copy_u8CLKPol ,u8 Copy_u8CLKPase , u8 Copy_u8DataSize , u8 Copy_u8BoudRate , u8 Copy_u8DataDir );

void MSPI_vInit(void);


#define DIV_2                    0b000
#define DIV_4                    0b001
#define DIV_8                    0b010
#define DIV_16                   0b011
#define DIV_32                   0b100
#define DIV_64                   0b101
#define DIV_128                  0b110
#define DIV_256                  0b111











#endif