/* 文件编码格式为utf-8  */
/** $Id$ $DateTime$
 *  @file gpipControl.h
 *  @brief header file of gpio control
 *  @version 0.0.1
 *  @since 0.0.1
 *  @author gyg<guyuegang@supcon.com>
 *  @date 2021-10-14    Created it
 */
/******************************************************************************
*@note
    Copyright 2021, Zhejiang SUPCON Technology Co., Ltd.
                        ALL RIGHTS RESERVED
 Permission is hereby granted to licensees of Zhejiang SUPCON Technology Co., Ltd.
 products to use or abstract this computer program for the sole purpose of implementing
 a product based on Zhejiang SUPCON Technology Co., Ltd. products. No other rights to
 reproduce, use, or disseminate this computer program,whether in part or in
 whole, are granted. Zhejiang SUPCON Technology Co., Ltd. makes no representation or
 warranties with respect to the performance of this computer program, and
 specifically disclaims any responsibility for any damages, special or
 consequential, connected with the use of this program.
 For details, see http://www.supcon.com
******************************************************************************/
#ifndef _GPIO_CONTROL_H
#define _GPIO_CONTROL_H

static int gpioExport(int pin);  
static int gpioUnexport(int pin);  
static int gpioDirection(int pin, int dir,int pio);  
static int gpioWrite(int pin, int value);  
static int gpioRead(int pin);  
static int gpioEdge(int pin, int edge,int pio);
int gpioExecuteButton(); 
static int gpioInit();
static int gpioOpenInit(int pin,int pio,int dir,int edge);
#endif

