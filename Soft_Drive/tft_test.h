/*!
    \file  tft_test.h
    \brief the header file of tft lcd test
*/

/*
    Copyright (C) 2016 GigaDevice

    2016-01-15, V1.0.0, demo for GD32F1x0(x=3,5)
    2016-05-13, V2.0.0, demo for GD32F1x0(x=3,5)
*/

#ifndef TFT_TEST_H
#define TFT_TEST_H

#include "gd32f1x0.h"

/* font display test */
void font_test(void);
/* number display test */
void num_test(void);
/* gui draw test */
void draw_test(void);
/* color display test */
void color_test(void);

void Pic_test(void);

#endif /* TFT_TEST_H */
