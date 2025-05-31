#include "types.h"
#ifndef _DEFINES_H
#define _DEFINES_H
#define SETBIT(WORD,BITPOS) (WORD|=(1<<BITPOS))
#define CLRBIT(WORD,BITPOS) (WORD&=~(1<<BITPOS))
#define CPLBIT(WORD,BITPOS) (WORD^=(1<<BITPOS))
#define SSETBIT(WORD,BITPOS) (WORD=(1<<BITPOS))
#define SCLRBIT(WORD,BITPOS) (WORD=(1<<BITPOS))
#define WRITEBYTE(WORD,BITPOS,DATA) WORD=(WORD&~(0xFF<<BITPOS)) | (DATA<<BITPOS)
#define WRITENIBBLE(WORD,BITPOS,DATA) WORD=(WORD&~(0xF<<BITPOS)) | (DATA<<BITPOS)
#define WRITEBIT(WORD,BITPOS,DATA) WORD=(WORD&~(1<<BITPOS)) | (DATA<<BITPOS)
#define READBIT(WORD,BITPOS) ((WORD>>BITPOS)&1)
#define READNIBBLE(WORD,SBITPOS) ((WORD>>SBITPOS)&0xF)
#define READBYTE(WORD,SBITPOS) ((WORD>>SBITPOS)&0xFF)
#define READWRITEBIT(DWORD,DBIT,SWORD,SBIT) DWORD=(DWORD&~(1<<DBIT))|(((SWORD>>SBIT)&1)<<DBIT)
void SetDIR(u32 *,u8,u8);
void ssetbit(u32 *,u32);
void sclrbit(u32 *,u32);
void setbit(u32 *,u32);
void clrbit(u32 *,u32);
void writebit(u32 *,u8,u8);
void writenibble(u32 *,u8,u8);
void writebyte(u32 *,u8,u8);
u8 readpin(u32 *,u8); 
#endif
