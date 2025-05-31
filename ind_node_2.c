#include <LPC21xx.h>
#include"can.h"
#include"delay.h"
#include"can_defines.h"
int main()
{
	CANF rxFrame;
  signed char i,temp=0;
  Init_CAN1();
  IODIR0|=0XFF;
  IOSET0=0XFF;
while(1)
{
	if(C1GSR&(1<<0))
		{ 
			CAN1_Rx(&rxFrame);
			if(rxFrame.ID==2)
			{
				temp=rxFrame.Data[0];
			}
		}
      if(temp==8)
			{				
				for(i=7;i>=0;i--)
				{
					IOCLR0=1<<i;
          delay_ms(50);
        }
        IOSET0=0XFF;
      }
      else if(temp==6)
      {
				for(i=0;i<=7;i++)
        {
          IOCLR0=1<<i;
          delay_ms(50);
        }
        IOSET0=0XFF;
      }
			else if(temp==7)
			{
				IOSET0=0XFF;
			}
	}
}

