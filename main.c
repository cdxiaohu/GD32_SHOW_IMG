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
	
    while(1){
        /* clear the lcd to blue*/
        lcd_clear(BLUE);
        /* font display test*/
        font_test();
        /* num display test*/
        num_test();
        /* draw display test*/
        draw_test();
        /* color display test*/
  	    color_test();
	//	Pic_test();	
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
