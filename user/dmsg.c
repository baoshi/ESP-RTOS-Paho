/**
  ******************************************************************************
  * @file    dmsg.c
  * @author  Baoshi <mail(at)ba0sh1(dot)com>
  * @version 0.1
  * @date    Dec 16, 2014
  * @brief   Some TX only functions for debug output,
  *          meant for use with ESP8266 UART1.
  *
  ******************************************************************************
  * @copyright
  *
  * Copyright (c) 2015, Baoshi Zhu. All rights reserved.
  * Use of this source code is governed by a BSD-style license that can be
  * found in the LICENSE.txt file.
  *
  * THIS SOFTWARE IS PROVIDED 'AS-IS', WITHOUT ANY EXPRESS OR IMPLIED
  * WARRANTY.  IN NO EVENT WILL THE AUTHOR(S) BE HELD LIABLE FOR ANY DAMAGES
  * ARISING FROM THE USE OF THIS SOFTWARE.
  *
  */

#include <stdarg.h>
#include "esp_common.h"
#include "uart.h"
#include "xmit.h"
#include "dmsg.h"

#ifdef DMSG_ENABLED


/** @brief   Output callback for xmit.c */
LOCAL int ICACHE_FLASH_ATTR xout_cb(void *param, char c)
{
#if (DMSG_UART == 1)
    uart1_putchar(c);
#elif (DMSG_UART == 0)
    uart0_putchar(c);
#else
    #error "DMSG_UART must be 0 or 1"
#endif
    return 1;
}


LOCAL void ICACHE_FLASH_ATTR uartx_putchar_dummy(char c)
{
}


void ICACHE_FLASH_ATTR dmsg_init(void)
{
#if (DMSG_UART == 1)
    uart1_init();
    os_install_putc1((void *)(void *)uart1_putchar);
#elif (DMSG_UART == 0)
    uart_param_t uart_param;
    uart_param.uart_baud_rate = UART_BAUD_RATE_74880;
    uart_param.uart_xfer_bit = UART_XFER_8_BIT;
    uart_param.uart_parity_mode = UART_PARITY_NONE;
    uart_param.uart_stop_bit = UART_1_STOP_BIT;
    uart_param.uart_flow_ctrl = UART_NONE_FLOW_CTRL;
    os_install_putc1((void *)(void *)uart0_putchar);
#else
    #error "DMSG_UART must be 0 or 1"
#endif
}


void ICACHE_FLASH_ATTR dmsg_putchar(char c)
{
    xfputc(xout_cb, 0, c);
}


void ICACHE_FLASH_ATTR dmsg_puts(const char *s)
{
    xfputs(xout_cb, 0, s);
}


void ICACHE_FLASH_ATTR dmsg_printf(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    xvfprintf(xout_cb, 0, fmt, args);
    va_end(args);
}


#endif


