//I2C.h
//I2C-defines.h
//pin defines

#define SCL 2
#define SDA 3

//clock speed settings

#define FOSC 12000000
#define CCLK (FOSC*5)
#define pCLK (CCLK/4)
#define I2C_SPEED 100000
#define LOADVAL ((pCLK/I2C_SPEED)/2)

//SFRs
//I2CONSET

#define AA 2
#define SI 3
#define STA 5
#define STO 4
#define I2EN 6
//I2CONCLR

#define AAC 2
#define SIC 3
#define STAC 5
// --- MMA7660 Sensor Specific Definitions ---
#define MMA7660_I2C_ADDR (0x4C << 1) // 7-bit address 0x4C, shifted left for 8-bit R/W byte

// MMA7660 Registers
#define MMA7660_XOUT    0x00 // X-axis acceleration data
#define MMA7660_YOUT    0x01 // Y-axis acceleration data
#define MMA7660_ZOUT    0x02 // Z-axis acceleration data
#define MMA7660_MODE    0x07 // Mode register
#define MMA7660_SR      0x08 // Sample Rate register
#define SHAKE_INT_X_ENABLE      (1 << 7) // SHINTX: Bit 7 of INTSU [cite: 121, 133]
#define SHAKE_INT_Y_ENABLE      (1 << 6) // SHINTY: Bit 6 of INTSU [cite: 121, 133]
#define SHAKE_INT_Z_ENABLE      (1 << 5) // SHINTZ: Bit 5 of INTSU [cite: 121, 134]
#define SHAKE_ALL_AXES_ENABLE   (SHAKE_INT_X_ENABLE | SHAKE_INT_Y_ENABLE | SHAKE_INT_Z_ENABLE)
#define MMA7660_INTSU_REG       0x06  // Interrupt Setup Register [cite: 121, 131]
#define MMA7660_TILT_REG        0x03  // TILT Register [cite: 120, 123]

// MMA7660 Mode Register values
#define MMA7660_MODE_STANDBY    0x00
#define MMA7660_MODE_ACTIVE     0x01

// MMA7660 Sample Rate Register values (examples)
#define MMA7660_SR_120HZ        0x00 // 120 samples/sec
#define MMA7660_SR_60HZ         0x01 // 60 samples/sec
#define MMA7660_SR_30HZ         0x02 // 30 samples/sec
#define MMA7660_SR_16HZ         0x03 // 16 samples/sec
#define MMA7660_SR_8HZ          0x04 // 8 samples/sec
#define MMA7660_SR_4HZ          0x05 // 4 samples/sec
#define MMA7660_SR_2HZ          0x06 // 2 samples/sec

