#include <lpc21xx.h>
#include "can.h"
#include"delay.h"
#include"lcd.h"
#include"can_defines.h"
#include"i2c.h"
#include "i2c_definesh.h"
CANF txF,rxF;
float fuel=0;
volatile extern unsigned char flag_1,flag_2;
unsigned char arr[]={0X01,0X03,0X07,0X1F,0X1F,0X07,0X03,0X01,0X08,0X0C,0X0E,0X0F,0X0F,0X0E,0X0C,0X08};
int check_collision(int x,int y)
{
	if(x<=-20||y<=-25)
	{
		return 1;
	}
	return 0;
}
int main(void)
{
	short int i;
	signed int axis[3],tilt_status;
	IODIR0|=1<<6;
	IOSET0=1<<6;
	Init_CAN1();
	InitLCD();
	i2c_init();
  MMA7660_Init();
	build_cgrom(arr,24);
	enable_int();
	txF.BFV.RTR=0;
  txF.BFV.DLC=1;
	txF.ID=2;
	//Intro();
	StrLCD("VECTOR DASHBOARD");
   while(1)
   {
		 for(i=0;i<3;i++)
		 {
			 i2c_read(MMA7660_I2C_ADDR,0x00+i,&axis[i]);
			 if((axis[i]>>5&1)==1)
				{
					axis[i]=-(axis[i]&0x1f);
				}				else
				{
					axis[i]=(axis[i]&0x1f);
				}
		 }
		 i2c_read(MMA7660_I2C_ADDR,MMA7660_TILT_REG,&tilt_status);
		 if(tilt_status&(1<<7))
		 {
			if(check_collision(axis[0],axis[1]))
			{
				IOCLR0=1<<6;
			}
		}
		if((C1GSR&(1<<0))==1)
		{
			CAN1_Rx(&rxF);
			fuel=(rxF.Data[0])|(rxF.Data[1]>>8)|(rxF.Data[2]>>16)|(rxF.Data[3]>>24);
		}
		ideal_dashboard(fuel);
		  if(flag_1==1)
      {
				right_blink(fuel);						
      }
      else if(flag_2==1)
      {
				left_blink(fuel);
			}
			delay_ms(16);
	}
}
