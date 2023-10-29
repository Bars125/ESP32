#ifndef I2S_Init_H
#define I2S_Init_H

#define SAMPLE_BUFFER_SIZE 512
#define SAMPLE_RATE 8000
#define I2S_MIC_SERIAL_CLOCK GPIO_NUM_32
#define I2S_MIC_LEFT_RIGHT_CLOCK GPIO_NUM_25
#define I2S_MIC_SERIAL_DATA GPIO_NUM_33

#include <Arduino.h>
#include <driver/i2s.h>

#endif