/*
 * IncFile1.h
 *
 * Created: 09/07/2023 10:53:20
 *  Author: GuilhermeRS
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#include "bno055.h"
#include <atmel_start.h>
#include <stdio.h>

/* This API is an example for reading sensor data
 *  \param: None
 *  \return: communication result
 */
s32 bno055_data_readout_template(void);

/*----------------------------------------------------------------------------*
 *  struct bno055_t parameters can be accessed by using BNO055
 *  BNO055_t having the following parameters
 *  Bus write function pointer: BNO055_WR_FUNC_PTR
 *  Bus read function pointer: BNO055_RD_FUNC_PTR
 *  Burst read function pointer: BNO055_BRD_FUNC_PTR
 *  Delay function pointer: delay_msec
 *  I2C address: dev_addr
 *  Chip id of the sensor: chip_id
 *---------------------------------------------------------------------------*/
struct bno055_t bno055;

void floatToString(float num, char* str, int precision);

/*
 * \Brief: I2C init routine
 */
s8 I2C_routine(void);

#define BNO055_I2C_BUS_WRITE_ARRAY_INDEX ((u8)1)

/*  \Brief: The API is used as I2C bus read
 *  \Return : Status of the I2C read
 *  \param dev_addr : The device address of the sensor
 *  \param reg_addr : Address of the first register,
 *   will data is going to be read
 *  \param reg_data : This data read from the sensor,
 *   which is hold in an array
 *  \param cnt : The no of byte of data to be read
 */
s8 BNO055_I2C_bus_read(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 cnt);

/*  \Brief: The API is used as SPI bus write
 *  \Return : Status of the SPI write
 *  \param dev_addr : The device address of the sensor
 *  \param reg_addr : Address of the first register,
 *   will data is going to be written
 *  \param reg_data : It is a value hold in the array,
 *  will be used for write the value into the register
 *  \param cnt : The no of byte of data to be write
 */
s8 BNO055_I2C_bus_write(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 cnt);


/*  Brief : The delay routine
 *  \param : delay in ms
 */
void BNO055_delay_msek(u32 msek);

struct io_descriptor *I2C_BNO055_io;


/* Variable used to return value of
    * communication routine*/
s32 comres;

/* variable used to set the power mode of the sensor*/
u8 power_mode;

/*********read raw accel data***********/
/* variable used to read the accel x data */
s16 accel_datax;

/* variable used to read the accel y data */
s16 accel_datay;

/* variable used to read the accel z data */
s16 accel_dataz;

/* variable used to read the accel xyz data */
struct bno055_accel_t accel_xyz;

/*********read raw mag data***********/
/* variable used to read the mag x data */
s16 mag_datax;

/* variable used to read the mag y data */
s16 mag_datay;

/* variable used to read the mag z data */
s16 mag_dataz;

/* structure used to read the mag xyz data */
struct bno055_mag_t mag_xyz;

/***********read raw gyro data***********/
/* variable used to read the gyro x data */
s16 gyro_datax;

/* variable used to read the gyro y data */
s16 gyro_datay;

/* variable used to read the gyro z data */
s16 gyro_dataz;

/* structure used to read the gyro xyz data */
struct bno055_gyro_t gyro_xyz;

/*************read raw Euler data************/
/* variable used to read the euler h data */
s16 euler_data_h;

/* variable used to read the euler r data */
s16 euler_data_r;

/* variable used to read the euler p data */
s16 euler_data_p;

/* structure used to read the euler hrp data */
struct bno055_euler_t euler_hrp;

/************read raw quaternion data**************/
/* variable used to read the quaternion w data */
s16 quaternion_data_w;

/* variable used to read the quaternion x data */
s16 quaternion_data_x;

/* variable used to read the quaternion y data */
s16 quaternion_data_y;

/* variable used to read the quaternion z data */
s16 quaternion_data_z;

/* structure used to read the quaternion wxyz data */
struct bno055_quaternion_t quaternion_wxyz;

/************read raw linear acceleration data***********/
/* variable used to read the linear accel x data */
s16 linear_accel_data_x;

/* variable used to read the linear accel y data */
s16 linear_accel_data_y;

/* variable used to read the linear accel z data */
s16 linear_accel_data_z;

/* structure used to read the linear accel xyz data */
struct bno055_linear_accel_t linear_acce_xyz;

/*****************read raw gravity sensor data****************/
/* variable used to read the gravity x data */
s16 gravity_data_x;

/* variable used to read the gravity y data */
s16 gravity_data_y;

/* variable used to read the gravity z data */
s16 gravity_data_z;

/* structure used to read the gravity xyz data */
struct bno055_gravity_t gravity_xyz;

/*************read accel converted data***************/
/* variable used to read the accel x data output as m/s2 or mg */
double d_accel_datax;

/* variable used to read the accel y data output as m/s2 or mg */
double d_accel_datay;

/* variable used to read the accel z data output as m/s2 or mg */
double d_accel_dataz;

/* structure used to read the accel xyz data output as m/s2 or mg */
struct bno055_accel_double_t d_accel_xyz;

/******************read mag converted data********************/
/* variable used to read the mag x data output as uT*/
double d_mag_datax;

/* variable used to read the mag y data output as uT*/
double d_mag_datay;

/* variable used to read the mag z data output as uT*/
double d_mag_dataz;

/* structure used to read the mag xyz data output as uT*/
struct bno055_mag_double_t d_mag_xyz;

/*****************read gyro converted data************************/
/* variable used to read the gyro x data output as dps or rps */
double d_gyro_datax;

/* variable used to read the gyro y data output as dps or rps */
double d_gyro_datay;

/* variable used to read the gyro z data output as dps or rps */
double d_gyro_dataz;

/* structure used to read the gyro xyz data output as dps or rps */
struct bno055_gyro_double_t d_gyro_xyz;

/*******************read euler converted data*******************/

/* variable used to read the euler h data output
    * as degree or radians*/
double d_euler_data_h;

/* variable used to read the euler r data output
    * as degree or radians*/
double d_euler_data_r;

/* variable used to read the euler p data output
    * as degree or radians*/
double d_euler_data_p;

/* structure used to read the euler hrp data output
    * as as degree or radians */
struct bno055_euler_double_t d_euler_hpr;

/*********read linear acceleration converted data**********/
/* variable used to read the linear accel x data output as m/s2*/
double d_linear_accel_datax ;

/* variable used to read the linear accel y data output as m/s2*/
double d_linear_accel_datay;

/* variable used to read the linear accel z data output as m/s2*/
double d_linear_accel_dataz;

/* structure used to read the linear accel xyz data output as m/s2*/
struct bno055_linear_accel_double_t d_linear_accel_xyz;

/********************Gravity converted data**********************/
/* variable used to read the gravity sensor x data output as m/s2*/
double d_gravity_data_x;

/* variable used to read the gravity sensor y data output as m/s2*/
double d_gravity_data_y;

/* variable used to read the gravity sensor z data output as m/s2*/
double d_gravity_data_z;

/* structure used to read the gravity xyz data output as m/s2*/
struct bno055_gravity_double_t d_gravity_xyz;

/* name RGB LED Macros */
#define RGB_LED_R				PIN_PA19
#define RGB_LED_G				PIN_PA28
#define RGB_LED_B				PIN_PA18

/**
 * Funções de liga e desliga dos LEDs RGB da placa
 */
void SET_R_LED_ON(void);
void SET_R_LED_OFF(void);
void SET_G_LED_ON(void);
void SET_G_LED_OFF(void);
void SET_B_LED_ON(void);
void SET_B_LED_OFF(void);

#endif /* INCFILE1_H_ */