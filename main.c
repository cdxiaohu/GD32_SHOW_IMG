/*!
    \file  main.c
    \brief SPI tft lcd driver demo
*/

/*
    Copyright (C) 2016 GigaDevice

    2016-01-15, V1.0.0, demo for GD32F1x0(x=3,5)
    2016-05-13, V2.0.0, demo for GD32F1x0(x=3,5)
*/
#include <stdio.h>
#include "gd32f1x0.h"
#include "gd32f1x0_eval.h"
#include "lcd_driver.h"
#include "tft_test.h"
#include "delay.h"
#include "systick.h"
#include "pic.h"
#include "gui.h"

void test_status_led_init(void);
void flash_led(uint32_t times);

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{     
	 /* SYSTICK configuration */
    systick_config();
	
    /* initialize test status led */ 
    test_status_led_init();
	
		/* USART initialize */
    gd_eval_COMinit(EVAL_COM1);

    /* configure the systick */
    delay_init(72);

    /* flash led for test */
    flash_led(1);

    /* enable the gpio clock */
    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_GPIOB);
    rcu_periph_clock_enable(RCU_GPIOC);
    rcu_periph_clock_enable(RCU_GPIOF);

    /* initialize lcd */
    lcd_init();
		printf("sys init success \n");
		//while (RESET == usart_flag_get(USART0 , USART_STAT_TC));
		lcd_clear(BLUE);
		/*gui_box(0,0,20,20,RED);
		gui_box2(20,20,20,20,BLACK);
		gui_circle(40,40,20,YELLOW);
		gui_draw_font_gbk16(20,0,GREEN,YELLOW,"hello world");
		gui_draw_font_gbk24(20,80,GREEN,BLACK,"hello world");
		gui_draw_font_num32(20,100,GREEN,BLACK,3);
		gui_draw_line(20,164,256,174,RED);
		gui_rect(20,180,50,200,GREEN);*/
	//	gui_draw_bmp16(30,30,gImage_qq);
	//	gui_draw_bmp16(90,30,gImage_qq);
	//	gui_draw_bmp16(150,30,gImage_qq_logo);
	//	gui_draw_pic(30,30,40,40,gImage_qq_logo);
		gui_draw_pic(0+14,14,106,80,gImage_10680);
		gui_draw_pic(107+14,14,106,80,gImage_10680_3);
		gui_draw_pic(0+14,14+81,106,80,gImage_10680_2);
		//gui_draw_pic(0+14+107,14+81,106,80,gImage_10680_4);
    while(1){
        /* clear the lcd to blue*/
        
        /* font display test*/
   //     font_test();
        /* num display test*/
   //     num_test();
        /* draw display test*/
 //       draw_test();
        /* color display test*/
  //	    color_test();
		//	display_button_down(0,30,50,50);
		//	display_button_up(0,30,50,50);
				
				//Pic_test();	
   }
}

/*!
    \brief      test status led initialize
    \param[in]  none
    \param[out] none
    \retval     none
*/
void test_status_led_init(void)
{
    /* initialize the leds */
    gd_eval_ledinit(LED1);
    gd_eval_ledinit(LED2);
    gd_eval_ledinit(LED3);
    gd_eval_ledinit(LED4);

    /* close all of leds */
    gd_eval_ledoff(LED1);
    gd_eval_ledoff(LED2);
    gd_eval_ledoff(LED3);
    gd_eval_ledoff(LED4);
}

/*!
    \brief      flash leds
    \param[in]  times: leds blink times
    \param[out] none
    \retval     none
*/
void flash_led(uint32_t times)
{
    int i;

    for(i = 0;i < times;i ++){
        /* insert 200 ms delay */
         delay_ms(200);

        /* turn on leds */
        gd_eval_ledon(LED1);
        gd_eval_ledon(LED2);
        gd_eval_ledon(LED3);
        gd_eval_ledon(LED4);

        /* insert 200 ms delay */
         delay_ms(200);

        /* turn off leds */
        gd_eval_ledoff(LED1);
        gd_eval_ledoff(LED2);
        gd_eval_ledoff(LED3);
        gd_eval_ledoff(LED4);
    }
}

/* retarget the C library printf function to the USART */
int fputc(int ch, FILE *f)
{
    usart_data_transmit(EVAL_COM1, (uint8_t) ch);
    while (RESET == usart_flag_get(EVAL_COM1,USART_STAT_TC));
    return ch;
}
