#include"types.h"
void i2c_init(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_restart(void);
void i2c_write(u8 dat);
u8 i2c_nack(void);
u8 i2c_mack(void);
void i2c_eeprom_write(u8 slaveAddr,u8 wBuffAddr,u8 dat);
u8 i2c_eeprom_read(u8 slaveAddr,u8 rBuffAddr);
void i2c_eeprom_page_write(u8 slaveAddr,u8 wBuffStartAddr,u8 *p,u8 nBytes);
void i2c_eeprom_seq_read(u8 slaveAddr,u8 rBuffStartAddr,u8 *p,u8 nBytes);
int i2c_write_sensor(unsigned char slave_addr, unsigned char reg_addr, unsigned char data);
int i2c_read(unsigned char slave_addr, unsigned char reg_addr, signed int *data_out);
void MMA7660_Init(void);
