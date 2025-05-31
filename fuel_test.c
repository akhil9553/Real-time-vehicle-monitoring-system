#include<lpc21xx.h>
#include"types.h"
#include"delay.h"
//defines for ADCR
#define CH1 (1<<1)
#define FOSC    12000000
#define CCLK    (5*FOSC)
#define PCLK    (CCLK/4)
#define ADCLK   3750000  //PCLK/4 (<=4.5MHZ)
#define CLKDIV  ((PCLK/ADCLK)-1)

#define PDN_BIT   21
#define CLKS      17
#define BRUST 16
#define ADC_START_BIT 24
//defines for ADDR
#define DONE_BIT   31
float eAr;
unsigned short int adcVal;
void Init_ADC(void) 
{
	ADCR=(1<<PDN_BIT)|(0<<CLKS)|(CLKDIV<<8); // PDN->1 ADC IN OPERATIONAL .. 0=CLKS=000 i.e 11 CLKS/CONVERSION  ..CLKDIV=(3+1)
}
float Read_ADC(unsigned char chNo)
{
	ADCR|=chNo;
	ADCR|=1<<ADC_START_BIT;// CONVERSION WILL START FROM NOW
	delay_us(3); //Wait for Conversion time (2.44us Minimun);	
	while(((ADDR>>DONE_BIT)&1)==0);
	ADCR&=~(1<<ADC_START_BIT);// Stop's Conversion After Conversion Completed
	adcVal=(ADDR>>6)&0x3FF; // 10 bit data
	eAr=adcVal*(3.3/1023);
	return eAr;
}
