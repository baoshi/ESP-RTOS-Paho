/**
  ******************************************************************************
  * @file    dmsg.h
  * @author  Baoshi <mail(at)ba0sh1(dot)com>
  * @version 0.1
  * @date    Nov 15, 2015
  * @brief   Some TX only functions for debug output,
  *          meant for use with ESP8266 UART.
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

#ifndef DMSG_H_
#define DMSG_H_

#define DMSG_ENABLED

#ifdef DMSG_ENABLED

#define DMSG_UART   0

/**
 * @brief   Initialize
 */
void dmsg_init(void);

/**
 * @brief   Output one character
 * @param   c Character to output
 */
void dmsg_putchar(char c);

/**
 * @brief   Output one string
 * @param   s String to output
 */
void dmsg_puts(const char *s);

/**
 * @brief   printf style output
 * @param   fmt printf format string
 */
void dmsg_printf(const char *fmt, ...);


#else

#define dmsg_init(x)
#define dmsg_putchar(x)
#define dmsg_puts(x)
#define dmsg_printf(fmt, ...)

#endif


#endif /* DMSG_H_ */
