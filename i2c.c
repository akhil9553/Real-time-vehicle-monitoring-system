//I2C.c
#include<lpc21xx.h>
#include "i2c_definesh.h"
#include "types.h"
void i2c_init(void)
{
	//make p0.2 and p0.3 as scl&sda 
	//PINSEL0|=0x00000055;
	PINSEL0|=0x00000050;
	//CFGPIN(PINSEL0,2,FUN2);
	//CFGPIN(PINSEL0,3,FUN2);
	
	//clock speed
	I2SCLL=LOADVAL;
	I2SCLH=LOADVAL;
	
	//enable the i2c peripheral
	I2CONSET=1<<I2EN;
}

void i2c_start(void)
{
	// start condition
	I2CONSET=1<<STA;
	
	//wait for SI bit status
	while(((I2CONSET>>SI)&1)==0);
	
	// clear start condition
	I2CONCLR=1<<STAC;
}

void i2c_stop(void)
{
	 // issue stop condition
	 I2CONSET=1<<STO;
	
	 // clear SI bit status
	 I2CONCLR=1<<SIC;
	
	 //stop will cleared automatically
	 while(((I2CONSET>>STO)&1));
}

void i2c_restart(void)
{
	// start condition
	I2CONSET=1<<STA;
	
	//clear SI_BIT
	I2CONCLR=1<<SIC;
	
	//wait for SI bit status
	while(((I2CONSET>>SI)&1)==0);
	
	// clear start condition
		I2CONCLR=1<<STAC;
}

void i2c_write(u8 dat)
{
	//put data into I2DAT
		I2DAT=dat;
	
	//clear SI_BIT
		I2CONCLR=1<<SIC;
	
	//wait for SI bit status
		while(((I2CONSET>>SI)&1)==0);
}

u8 i2c_nack(void)
{
	//Assert Not of Ack
	 I2CONSET=0<<AA;
	
	//Clear SI bit
		I2CONCLR=1<<SIC;
	
	//wait for byte reception
		while(((I2CONSET>>SI)&1)==0);
	
	//read received byte;
		return I2DAT; 
}

u8 i2c_mack(void)
{
	
	//Assert Ack
		I2CONSET=1<<AA;
	
	//Clear SI bit
		I2CONCLR=1<<SIC;
	
	//Wait for SI Bit

	while(((I2CONSET>>SI)&1)==0);
	
	//Clear Assert Ack
		I2CONCLR=1<<AAC;
	
	//read read byte
    return I2DAT;

}
int i2c_write_sensor(unsigned char slave_addr, unsigned char reg_addr, unsigned char data) {
    // Your I2C write implementation here
    // This typically involves:
    i2c_start();// 1. Send START condition.
    i2c_write(slave_addr|0);// 2. Send slave_addr (with write bit).
    i2c_write(reg_addr);// 3. Send reg_addr.
    i2c_write(data);// 4. Send data.
    i2c_stop();// 5. Send STOP condition
    return 0; // Placeholder
}

int i2c_read(unsigned char slave_addr, unsigned char reg_addr, signed int *data_out) {
    // Your I2C read implementation here
    // This typically involves:
  i2c_start();  // 1. Send START condition.
    i2c_write(slave_addr|0);// 2. Send slave_addr (with write bit).
    i2c_write(reg_addr);// 3. Send reg_addr.
    i2c_restart();// 4. Send REPEATED START condition.
    i2c_write(slave_addr|1);// 5. Send slave_addr (with read bit).
    *data_out=i2c_nack();// 6. Read data.
    i2c_stop();
    return 0;
}
void MMA7660_Init()
{
	i2c_write_sensor(MMA7660_I2C_ADDR,MMA7660_MODE,MMA7660_MODE_STANDBY);
	i2c_write_sensor(MMA7660_I2C_ADDR,MMA7660_SR,MMA7660_SR_60HZ);
	i2c_write_sensor(MMA7660_I2C_ADDR,MMA7660_INTSU_REG,SHAKE_ALL_AXES_ENABLE);
	i2c_write_sensor(MMA7660_I2C_ADDR,MMA7660_MODE, MMA7660_MODE_ACTIVE);
}


