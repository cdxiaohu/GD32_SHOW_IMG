/*!
    \file  gui.h
    \brief the header file of gui
*/

/*
    Copyright (C) 2016 GigaDevice

    2016-01-15, V1.0.0, demo for GD32F1x0(x=3,5)
    2016-05-13, V2.0.0, demo for GD32F1x0(x=3,5)
*/

#ifndef GUI_H
#define GUI_H

#include "gd32f1x0.h"
#include <stdlib.h>

/* bgr to rgb format conversion */
uint16_t lcd_bgr2rgb(uint16_t c);
/* gui circle */
void gui_circle(uint16_t x,uint16_t y,uint16_t r,uint16_t fc);
/* gui draw line */
void gui_draw_line(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t color);
/* gui box */
void gui_box(uint16_t x,uint16_t y,uint16_t w,uint16_t h,uint16_t bc);
/* gui box2 */
void gui_box2(uint16_t x,uint16_t y,uint16_t w,uint16_t h,uint8_t mode);
/* gui rect */
void gui_rect(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t fc);
/* display button down */
void display_button_down(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);
/* display button up */
void display_button_up(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);
/* gui draw font to gbk16 */
void gui_draw_font_gbk16(uint16_t x,uint16_t y,uint16_t fc,uint16_t bc,char *s);
/* gui draw font to gbk24 */
void gui_draw_font_gbk24(uint16_t x,uint16_t y,uint16_t fc,uint16_t bc,char *s);
/* gui draw font to num32 */
void gui_draw_font_num32(uint16_t x,uint16_t y,uint16_t fc,uint16_t bc,uint16_t num);

void gui_draw_bmp16(uint16_t x,uint16_t y,const unsigned char *p); //œ‘ æ40*40 QQÕº∆¨

void gui_draw_pic(uint16_t x,uint16_t y,uint16_t w,uint16_t h,const unsigned char *p);

#endif /* GUI_H */
