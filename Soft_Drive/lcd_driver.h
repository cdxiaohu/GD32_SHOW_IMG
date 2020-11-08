/*!
    \file  lcd_driver.h
    \brief the header file of lcd driver
*/

/*
    Copyright (C) 2016 GigaDevice

    2016-01-15, V1.0.0, demo for GD32F1x0(x=3,5)
    2016-05-13, V2.0.0, demo for GD32F1x0(x=3,5)
*/

#ifndef LCD_DRIVER_H
#define LCD_DRIVER_H

#include <stdlib.h>
#include "gd32f1x0.h"

#define RED             (uint16_t)0xF800
#define GREEN           (uint16_t)0x07E0
#define BLUE            (uint16_t)0x001F
#define WHITE           (uint16_t)0xFFFF
#define BLACK           (uint16_t)0x0000
#define YELLOW          (uint16_t)0xFFE0

/* grays */
#define GRAY0           (uint16_t)0xEF7D
#define GRAY1           (uint16_t)0x8410
#define GRAY2           (uint16_t)0x4208

/* PF5 tft cs */
#define LCD_CS_SET      ((uint32_t)(GPIO_BOP(GPIOF) = GPIO_PIN_5))
#define LCD_CS_CLR      ((uint32_t)(GPIO_BC(GPIOF) = GPIO_PIN_5))

/* PC3 tft rs/dc */
#define LCD_RS_SET      ((uint32_t)(GPIO_BOP(GPIOC) = GPIO_PIN_3))
#define LCD_RS_CLR      ((uint32_t)(GPIO_BC(GPIOC) = GPIO_PIN_3))

/* PC4 tft rst */
#define LCD_RST_SET     ((uint32_t)(GPIO_BOP(GPIOC) = GPIO_PIN_4))
#define LCD_RST_CLR     ((uint32_t)(GPIO_BC(GPIOC) = GPIO_PIN_4))

#ifdef H_VIEW
    #define X_MAX_PIXEL         (uint16_t)320
    #define Y_MAX_PIXEL         (uint16_t)240
#else
    #define X_MAX_PIXEL         (uint16_t)240
    #define Y_MAX_PIXEL         (uint16_t)320
#endif

/* lcd init */
void lcd_init(void);
/* clear the lcd */
void lcd_clear(uint16_t color);
/* set the start display point of lcd */
void lcd_set_xy(uint16_t x,uint16_t y);
/* draw a point on the lcd */
void gui_draw_point(uint16_t x,uint16_t y,uint16_t data);
void lcd_set_region(uint16_t x_start,uint16_t y_start,uint16_t x_end,uint16_t y_end);
void lcd_write_data_16bit(uint8_t datah,uint8_t datal);
#endif /* LCD_DRIVER_H */
