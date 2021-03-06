/******************** (C) COPYRIGHT 2011 野火嵌入式开发工作室 ********************
 * 文件名       ：isr.h
 * 描述         ：重新宏定义中断号，重映射中断向量表里的中断函数地址，
 *                使其指向我们所定义的中断服务函数。声明中断服务函数
 *                警告：只能在"vectors.c"包含，而且必须在"vectors.h"包含的后面！！！
 *
 * 实验平台     ：野火kinetis开发板
 * 库版本       ：
 * 嵌入系统     ：
 *
 * 作者         ：野火嵌入式开发工作室
 * 淘宝店       ：http://firestm32.taobao.com
 * 技术支持论坛 ：http://www.ourdev.cn/bbs/bbs_list.jsp?bbs_id=1008
**********************************************************************************/

/******************************************************************************* 
******************************************************************************** 
* 文件名称: isr.h
*
* 描    述: 中断服务程序头文件，重新宏定义中断号，重映射中断向量表里的中断函数地址，
*           使其指向我们所定义的中断服务函数。声明中断服务函数
*           警告：只能在"vectors.c"包含，而且必须在"vectors.h"包含的后面！！！
* 
* 
* 作    者: 秦战强
* 日    期: 2016/12/29
******************************************************************************** 
*******************************************************************************/ 




#ifndef __ISR_H
#define __ISR_H 1

#include  "include.h"

/*                          重新定义中断向量表
 *  先取消默认的中断向量元素宏定义       #undef  VECTOR_xxx
 *  在重新定义到自己编写的中断函数       #define VECTOR_xxx    xxx_IRQHandler
 *  例如：
 *       #undef  VECTOR_003
 *       #define VECTOR_003    HardFault_IRQHandler    重新定义硬件上访中断服务函数
 */
#undef  VECTOR_014
#undef  VECTOR_015
#if     USOC_EN > 0u                            //如果定义了用ucos系统  用ucos的滴答定时器中断服务函数
#define VECTOR_014    OS_CPU_PendSVHandler
#define VECTOR_015    OS_CPU_SysTickHandler
#else
#define VECTOR_014    PendSV_Handler
#define VECTOR_015    SysTick_Handler           //滴答定时器  OS用得到
#endif


#undef  VECTOR_003
#define VECTOR_003    HardFault_IRQHandler         //发生硬件上访 （就是程序跑飞了）     推荐调试程序时，用个LED显示来指示程序跑飞了

#undef  VECTOR_016
#define VECTOR_016    DMA0TransComplete_IRQHandler

#undef  VECTOR_017
#define VECTOR_017    DMA1TransComplete_IRQHandler

#undef  VECTOR_018
#define VECTOR_018    DMA2TransComplete_IRQHandler

#undef  VECTOR_019
#define VECTOR_019    DMA3TransComplete_IRQHandler

#undef  VECTOR_020
#define VECTOR_020    DMA4TransComplete_IRQHandler

#undef  VECTOR_021
#define VECTOR_021    DMA5TransComplete_IRQHandler

#undef  VECTOR_022
#define VECTOR_022    DMA6TransComplete_IRQHandler

#undef  VECTOR_023
#define VECTOR_023    DMA7TransComplete_IRQHandler

#undef  VECTOR_024
#define VECTOR_024    DMA8TransComplete_IRQHandler

#undef  VECTOR_025
#define VECTOR_025    DMA9TransComplete_IRQHandler

#undef  VECTOR_026
#define VECTOR_026    DMA10TransComplete_IRQHandler

#undef  VECTOR_027
#define VECTOR_027    DMA11TransComplete_IRQHandler

#undef  VECTOR_028
#define VECTOR_028    DMA12TransComplete_IRQHandler

#undef  VECTOR_029
#define VECTOR_029    DMA13TransComplete_IRQHandler

#undef  VECTOR_030
#define VECTOR_030    DMA14TransComplete_IRQHandler

#undef  VECTOR_031
#define VECTOR_031    DMA15TransComplete_IRQHandler

#undef  VECTOR_032
#define VECTOR_032    DMAError_IRQHandler

#undef  VECTOR_061                              //要先取消了，因为在vectors.h里默认是定义为 default_isr  
#define VECTOR_061    USART0_IRQHandler         //重新定义63号中断的ISR：UART0：Single interrupt vector for UART status sources

#undef  VECTOR_062                              
#define VECTOR_062    USART0Error_IRQHandler    

#undef  VECTOR_063                              //要先取消了，因为在vectors.h里默认是定义为 default_isr  
#define VECTOR_063    USART1_IRQHandler         //重新定义63号中断的ISR：UART1：Single interrupt vector for UART status sources

#undef  VECTOR_064                              
#define VECTOR_064    USART1Error_IRQHandler 

#undef  VECTOR_065                              //要先取消了，因为在vectors.h里默认是定义为 default_isr  
#define VECTOR_065    USART2_IRQHandler         //重新定义63号中断的ISR：UART2：Single interrupt vector for UART status sources

#undef  VECTOR_066                              
#define VECTOR_066    USART2Error_IRQHandler 

#undef  VECTOR_067                              //要先取消了，因为在vectors.h里默认是定义为 default_isr  
#define VECTOR_067    USART3_IRQHandler         //重新定义63号中断的ISR：UART3：Single interrupt vector for UART status sources

#undef  VECTOR_068                              
#define VECTOR_068    USART3Error_IRQHandler 

#undef  VECTOR_069                              //要先取消了，因为在vectors.h里默认是定义为 default_isr  
#define VECTOR_069    USART4_IRQHandler         //重新定义63号中断的ISR：UART4：Single interrupt vector for UART status sources

#undef  VECTOR_070                              
#define VECTOR_070    USART4Error_IRQHandler 

#undef  VECTOR_071                              //要先取消了，因为在vectors.h里默认是定义为 default_isr  
#define VECTOR_071    USART5_IRQHandler         //重新定义63号中断的ISR：UART5：Single interrupt vector for UART status sources

#undef  VECTOR_072                              
#define VECTOR_072    USART5Error_IRQHandler 

#undef  VECTOR_073                              
#define VECTOR_073    AD0_IRQHandler

#undef  VECTOR_074                              
#define VECTOR_074    AD1_IRQHandler 

#undef  VECTOR_075                              
#define VECTOR_075    CMP0_IRQHandler 

#undef  VECTOR_075                              
#define VECTOR_075    CMP1_IRQHandler 

#undef  VECTOR_075                              
#define VECTOR_075    CMP2_IRQHandler 

#undef  VECTOR_078
#define VECTOR_078    FTM0_IRQHandler           //FTM0输入捕捉中断 

#undef  VECTOR_079
#define VECTOR_079    FTM1_IRQHandler           //FTM1输入捕捉中断

#undef  VECTOR_080
#define VECTOR_080    FTM2_IRQHandler           //FTM2输入捕捉中断

#undef  VECTOR_081
#define VECTOR_081    CMT_IRQHandler 

#undef  VECTOR_082
#define VECTOR_082    RTC_IRQHandler 

#undef  VECTOR_084
#define VECTOR_084    PIT0_IRQHandler           //重新定义84号中断为PIT0_IRQHandler中断

#undef  VECTOR_085
#define VECTOR_085    PIT1_IRQHandler           //重新定义84号中断为PIT1_IRQHandler中断

#undef  VECTOR_086
#define VECTOR_086    PIT2_IRQHandler           //重新定义84号中断为PIT2_IRQHandler中断

#undef  VECTOR_087
#define VECTOR_087    PIT3_IRQHandler           //重新定义84号中断为PIT3_IRQHandler中断

#undef  VECTOR_103
#define VECTOR_103    PORTA_IRQHandler          //PORTA中断

#undef  VECTOR_104
#define VECTOR_104    PORTB_IRQHandler          //PORTB中断

#undef  VECTOR_105
#define VECTOR_105    PORTC_IRQHandler          //PORTC中断

#undef  VECTOR_106
#define VECTOR_106    PORTD_IRQHandler          //PORTD中断

#undef  VECTOR_107
#define VECTOR_107    PORTE_IRQHandler          //PORTE中断


extern void PendSV_Handler(void);               //可悬起的系统调用中断服务函数
extern void HardFault_Handler(void);            //发生硬件上访（程序跑飞）
extern void SysTick_Handler(void);              //滴答时钟(os 用到)
extern void USART1_IRQHandler();                //串口1 中断接收函数
extern void PIT0_IRQHandler();                  //PIT0 定时中断服务函数
extern void PORTA_IRQHandler();                 //PORTA中断服务函数
extern void PORTB_IRQHandler();                 //PORTB中断服务函数
extern void FTM0_IRQHandler();                  //FTM0输入捕捉中断
extern void FTM1_IRQHandler();                  //FTM0输入捕捉中断


#endif  //__ISR_H

/* End of "isr.h" */
