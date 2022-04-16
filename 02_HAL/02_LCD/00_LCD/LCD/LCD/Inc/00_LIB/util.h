#ifndef UTIL_H
#define UTIL_H

#define SET_BIT(REG, BIT_NUM) REG|=(1<<(BIT_NUM))
#define CLR_BIT(REG, BIT_NUM) REG&=~(1<<(BIT_NUM))
#define TOGGLE_BIT(REG, BIT_NUM) REG^=(1<<(BIT_NUM))
#define GET_BIT(REG, BIT_NUM) (((REG)>>(BIT_NUM))&1)
#define ASSIGN_REG(REG, VALUE) REG=(VALUE)
#define GET_LOW_NIB(REG) ((REG)&(0x0f))
#define SET_LOW_NIB(REG) REG|=0x0f
#define CLR_LOW_NIB(REG) REG&=0xf0
#define ASSIGN_LOW_NIB(REG, VALUE) REG=((REG)&0xf0)|((VALUE)&0x0f)
#define GET_HIGH_NIB(REG) ((REG)&(0xf0))
#define SET_HIGH_NIB(REG) REG|=0xf0
#define CLR_HIGH_NIB(REG) REG&=0x0f
#define ASSIGN_HIGH_NIB(REG, VALUE) REG=((REG)&0x0f)|((VALUE)&0xf0)
#define GET_REG(REG) (REG)
#define SET_REG(REG) REG=0xff
#define CLR_REG(REG) REG=0x00
#define TOGGLE_REG(REG) REG^=0xff

#endif
