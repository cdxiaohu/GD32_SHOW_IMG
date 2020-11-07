/*!
    \file  delay.c
    \brief delay functions
*/

/*
    Copyright (C) 2016 GigaDevice

    2016-01-15, V1.0.0, demo for GD32F1x0(x=3,5)
    2016-05-13, V2.0.0, demo for GD32F1x0(x=3,5)
*/

#include "gd32f1x0.h"
#include "delay.h"

static uint8_t  fac_us = 0;
static uint16_t fac_ms = 0;

/*!
    \brief      initialization time delay function
    \param[in]  sysclk: system clock
    \param[out] none
    \retval     none
*/
void delay_init(uint8_t sysclk)
{
    SysTick->CTRL &= 0xfffffffb;

    fac_us = sysclk / 8;

    fac_ms = (uint16_t)fac_us * 1000;
}

/*!
    \brief      delay to ms
    \param[in]  nms: specifie the delay time length
    \param[out] none
    \retval     none
*/
void delay_ms(uint16_t nms)
{
    uint32_t systick_clrl;

    /* load time */
    SysTick->LOAD = (uint32_t)nms * fac_ms;

    /* clear counter */
    SysTick->VAL = 0x00;

    SysTick->CTRL = 0x01;

    do{
        systick_clrl = SysTick->CTRL;
    }while(systick_clrl & 0x01 && !(systick_clrl & (1 << 16)));

    /* close the counter */
    SysTick->CTRL = 0x00;

    /* clear counter */
    SysTick->VAL = 0X00;
}

/*!
    \brief      delay to nus
    \param[in]  nus: specifie the delay time length
    \param[out] none
    \retval     none
*/
void delay_us(uint32_t nus)
{
    uint32_t systick_clrl;

    /* load time */
    SysTick->LOAD = nus * fac_us;

    /* clear counter */
    SysTick->VAL = 0x00;

    SysTick->CTRL = 0x01;

    do{
        systick_clrl = SysTick->CTRL;
    }while(systick_clrl & 0x01 && !(systick_clrl & (1 << 16)));

    /* close the counter */
    SysTick->CTRL = 0x00;

    /* clear counter */
    SysTick->VAL = 0X00;
}
