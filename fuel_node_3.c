#include<lpc21xx.h>
#include"can.h"
#include"delay.h"
#include"lcd.h"
#define MAX_VAL 1.925
#define MIN_VAL 0.280
CANF txFrame;
float AR1;
u32 fuel,x;
int main()
{
        Init_CAN1();
        Init_ADC();
        while(1)
				{
					AR1=Read_ADC((1<<0));
                fuel=((AR1-MIN_VAL)/(MAX_VAL-MIN_VAL))*100;
                if(fuel!=x)
                {
                        txFrame.BFV.DLC=4;
                        txFrame.ID=1;
                        txFrame.BFV.RTR=0;
                        txFrame.Data[0]=fuel;
												txFrame.Data[1]=fuel>>8;
												txFrame.Data[2]=fuel>>16;
												txFrame.Data[3]=fuel>>24;
                        CAN1_Tx(txFrame);
												x=fuel;
									delay_s(1);
								}
   
				}
}
