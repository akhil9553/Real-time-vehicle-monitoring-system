#include<lpc21xx.h>
#include"can.h"
#include"lcd.h"
#define EXT0_CHNO 14
#define EXT2_CHNO 16
#define EXT0 16
#define EXT1 14
unsigned char flag_1,flag_2;
extern CANF txF;
void ent0_isr(void)__irq {
	if(flag_2==0)
		flag_1^=1;
	if((flag_1==1)&&(flag_2==0)) {
		txF.Data[0]=6;
		CAN1_Tx(txF);
	}
	else if((!flag_2)&&(!flag_1)) {
		txF.Data[0]=7;
		CAN1_Tx(txF);
	}
	EXTINT = 1<<0;
  VICVectAddr=0;
}
void ent2_isr(void)__irq
{
	if(flag_1==0)
		flag_2^=1;
	if((flag_2==1)&&(flag_1==0)) {
	 txF.Data[0]=8;
	 CAN1_Tx(txF);
 }
 else if((!flag_2)&&(!flag_1)) {
	 txF.Data[0]=7;
	 CAN1_Tx(txF);
 }
  EXTINT = 1<<2;
  VICVectAddr=0;
}
void enable_int()
{
				PINSEL0|=0x0000C00C;
        VICIntEnable=(1<<EXT0_CHNO)|(1<<EXT2_CHNO);//|(1 << 26);
        VICVectCntl0=(1<<5)|EXT0_CHNO;
        VICVectAddr0=(unsigned int)ent0_isr;
				VICVectCntl1=(1<<5)|EXT2_CHNO;
        VICVectAddr1=(unsigned int)ent2_isr;
				//VICVectCntl2=(1<<5)|26;
        //VICVectAddr2=(unsigned int)can_isr;
        EXTMODE=(1<<0)|(1<<2);
				//C1IER=1<<0;
}
