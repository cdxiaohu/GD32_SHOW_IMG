/*!
    \file  delay.h
    \brief the header file of delay
*/

/*
    Copyright (C) 2016 GigaDevice

    2016-01-15, V1.0.0, demo for GD32F1x0(x=3,5)
    2016-05-13, V2.0.0, demo for GD32F1x0(x=3,5)
*/ 

#ifndef DELAY_H
#define DELAY_H

#include "gd32f1x0.h"

/* initialization time delay function */
void delay_init(uint8_t sysclk);
/* delay ms function */
void delay_ms(uint16_t nms);
/* delay us function */
void delay_us(uint32_t nus);

#endif /* DELAY_H */
