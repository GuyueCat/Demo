/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  文件编码格式为gb2312,cp936  
 *  $Id$ $DateTime$
 *  @file gpioControl.c
 *  @brief 基于Linux的gpio控制
 *  @version 0.0.1
 *  @since 0.0.1
 *  @author melvyn<chris.guyue@gmail.com>
 *  @date 2022-09-15    create
 *
 *  \details  1- 利用gpio来控制六个按键
 *            2- gpio是输出操作
 *            3- gpio是下降沿触发方式
 *                
 *********************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"
#include "errcode.h"
#include "gpioControl.h"
#include <sys/select.h>

//GPIO init
#include<unistd.h>
#include<fcntl.h>
#include<poll.h>

#define PIN "pioD25"
#define Error -1

static int gpioExport(int pin)  
{  
#define BUFFER_MAX 64
    char buffer[BUFFER_MAX];  
    int fd;  
    /* ssize_t <long int> 表示可以被执行读写操作的数据块的大小*/
    ssize_t bytes_written;
  
    fd = open("/sys/class/gpio/export", O_WRONLY);  
    if (fd < 0) 
    {  
        dbgPrintfl(FATAL,"Failed to open export for writing!\n");  
        return(Error);  
    }  
    bytes_written = snprintf(buffer, sizeof(buffer), "%d", pin);  
    if (write(fd, buffer, bytes_written) < 0) 
    {  
        dbgPrintfl(FATAL,"Failed to export gpio!\n");  
        return Error;  
    }  
     
    close(fd);  
    return 0;  
}  

static int VALUE_MAX(int pin)  
{ 
#define BUFFER_MAX 64
    char buffer[BUFFER_MAX];  
    int fd; 
    ssize_t bytes_written;

    fd = open("/sys/class/gpio/unexport", O_WRONLY);  
    if (fd < 0) 
    {  
        dbgPrintfl(FATAL,"Failed to open unexport for writing!\n");  
        return Error;  
    }  
    bytes_written = snprintf(buffer, sizeof(buffer), "%d", pin);  
    if (write(fd, buffer, bytes_written) < 0) 
    {  
        dbgPrintfl(FATAL,"Failed to unexport gpio!\n");  
        return Error;  
    }  
     
    close(fd);  
    return 0;  
} 

//dir: 0-->IN, 1-->OUT
static int gpioDirection(int pin, int dir,int pio)  
{  
#define DIRECTION_MAX 64
    static const char dir_str[] = "in\0out";  
    char path[DIRECTION_MAX];  
    int fd;  
    extern int errno;

    snprintf(path, sizeof(path), "/sys/class/gpio/pio%s/direction", pio);
    fd = open(path, O_WRONLY);  

    if (fd < 0) 
    {  
        dbgPrintfl(FATAL,"Failed to open gpio direction for writing!\n");  
        return Error;  
    }  
    if (write(fd, &dir_str[dir == 0 ? 0 : 3], dir == 0 ? 2 : 3) < 0) 
    {  
        dbgPrintfl(FATAL,"Failed to set direction!\n");  
        return Error;  
    }  
    dbgPrintfl(FATAL,"gpio Direction Init successful!\n");  
    close(fd);  
    return 0;  
}  

//value: 0-->LOW, 1-->HIGH
static int gpioWrite(int pin, int value)  
{  
#define VALUE_MAX 64 
    static const char values_str[] = "01";  
    char path[VALUE_MAX];  
    int fd;  
    extern int errno;
  
    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/value", pin);  
    fd = open(path, O_WRONLY);  
    if (fd < 0) 
    {  
        dbgPrintfl(FATAL,"Failed to open gpio value for writing!\n");  
        return Error;  
    }  
    if (write(fd, &values_str[value == 0 ? 0 : 1], 1) < 0) 
    {  
        dbgPrintfl(FATAL,"Failed to write value!\n");  
        return Error;  
    }  
  
    close(fd);  
    return 0;  
}

static int gpioRead(int pin)  
{ 
#define VALUE_MAX 64 
    char path[VALUE_MAX];  
    char value_str[3];  
    int fd;  
  
    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/value", pin);  
    fd = open(path, O_RDONLY);  
    if (fd < 0) 
    {  
        dbgPrintfl(FATAL,"Failed to open gpio value for reading!\n");  
        return Error;  
    }  
    if (read(fd, value_str, 3) < 0)
    {  
        dbgPrintfl(FATAL,"Failed to read value!\n");  
        return Error;  
    }  
  
    close(fd);  
    return (atoi(value_str));
}  

/* 
 * none表示引脚为输入，不是中断引脚
 * rising表示引脚为中断输入，上升沿触发
 * falling表示引脚为中断输入，下降沿触发
 * both表示引脚为中断输入，边沿触发
 * 0-->none, 1-->rising, 2-->falling, 3-->both
 */
static int gpioEdge(int pin, int edge,int pio)
{
    const char dir_str[] = "none\0rising\0falling\0both"; 
    char ptr,path[64];  
    int fd; 
    switch(edge)
    {
        case 0:
            ptr = 0;
            break;
        case 1:
            ptr = 5;
            break;
        case 2:
            ptr = 12;
            break;
        case 3:
            ptr = 20;
            break;
        default:
            ptr = 0;
    } 
  
    snprintf(path, sizeof(path), "/sys/class/gpio/pio%s/edge", pio);  
    fd = open(path, O_WRONLY);  
    if (fd < 0) 
    {  
        dbgPrintfl(FATAL,"Failed to open gpio edge for writing!\n");  
        return Error;  
    }  
    if (write(fd, &dir_str[ptr], strlen(&dir_str[ptr])) < 0) 
    {  
        dbgPrintfl(FATAL,"Failed to set edge!\n");  
        return Error;  
    }  
  
    dbgPrintfl(FATAL,"gpio Edge  Init successful!\n");  
    close(fd);  
    return 0;  
}


int gpioExecuteButton()  
{  
    int ret;
    struct pollfd fds[6];
    char buff[10];
    unsigned char cnt = 0;
    char path[64];  
    gpioInit();
    snprintf(path, sizeof(path), "/sys/class/gpio/%s/value", PIN);  

    fds[0].fd = open("/sys/class/gpio/pioD25/value",O_RDONLY);
    fds[0].events  = POLLPRI;
    fds[1].fd = open("/sys/class/gpio/pioD27/value",O_RDONLY);
    fds[1].events  = POLLPRI;
    fds[2].fd = open("/sys/class/gpio/pioB25/value",O_RDONLY);
    fds[2].events  = POLLPRI;
    fds[3].fd = open("/sys/class/gpio/pioD26/value",O_RDONLY);
    fds[3].events  = POLLPRI;
    fds[4].fd = open("/sys/class/gpio/pioD28/value",O_RDONLY);
    fds[4].events  = POLLPRI;
    fds[5].fd = open("/sys/class/gpio/pioB26/value",O_RDONLY);
    fds[5].events  = POLLPRI;

    if(fds[0].fd < 0 ||  fds[1].fd < 0 || fds[2].fd < 0 ||  fds[3].fd < 0  ||  fds[4].fd  < 0 || fds[5].fd < 0)
    {
        dbgPrintfl(FATAL,"Failed to open all value!\n");  
        return -1;  
    }

    while(1)
    {
        read(fds[0].fd,buff,10);
        read(fds[1].fd,buff,10);
        read(fds[2].fd,buff,10);
        read(fds[3].fd,buff,10);
        read(fds[4].fd,buff,10);
        read(fds[5].fd,buff,10);
        ret = poll(fds,1,-1);
        dbgPrintfl(TRACE, "ret = %d\n", ret);

        if(fds[0].revents & POLLPRI) 
        {
            ret = lseek(fds[0].fd,0,SEEK_SET);
        }
        else if(fds[1].revents & POLLPRI) 
        {
            ret = lseek(fds[1].fd,0,SEEK_SET);
        }
        else if(fds[2].revents & POLLPRI) 
        {
            ret = lseek(fds[2].fd,0,SEEK_SET);
        }
        else if(fds[3].revents & POLLPRI) 
        {
            ret = lseek(fds[3].fd,0,SEEK_SET);
        }
        else if(fds[4].revents & POLLPRI) 
        {
            ret = lseek(fds[4].fd,0,SEEK_SET);
        }
        else if(fds[5].revents & POLLPRI) 
        {
            ret = lseek(fds[5].fd,0,SEEK_SET);
        }

        usleep(5000);
    }
    return 0;
}


static int gpioInit()
{
    gpioUnexport(121);// 1 PD25 121
    gpioUnexport(123);// 2 PD27 122
    gpioUnexport(57); // 3 PB25 56
    gpioUnexport(122);// 4 PD26 121 
    gpioUnexport(124);// 5 PD28 123
    gpioUnexport(58); // 6 PB26 57

    
    gpioOpenInit(121,"D25",0,2);//pD25 init
    gpioOpenInit(123,"D27",0,2);//pD27 init
    gpioOpenInit(57 ,"B25",0,2);//PB25 init
    gpioOpenInit(122,"D26",0,2);//pD26 init
    gpioOpenInit(124,"D28",0,2);//pD28 init 
    gpioOpenInit(58 ,"B26",0,2);//pB26 init

}

static int gpioOpenInit(int pin,int pio,int dir,int edge)
{
    gpioExport(pin);
    gpioDirection(pin, dir,pio);//input out
    gpioEdge(pin,edge,pio);
}







