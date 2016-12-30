/******************** (C) COPYRIGHT 2011 武汉理工大学秦战强 ********************
 * 文件名       ：main.c
 * 描述         ：工程模版实验
 *
 * 实验平台     ：野火kinetis开发板
 * 库版本       ：
 * 嵌入系统     ：
 *
 * 作者         ：武汉理工大学秦战强
**********************************************************************************/

#include "include.h"

//在这里定义任务堆栈，并在app_cfg.h中配置堆栈大小和任务优先级
static OS_STK startup_task_stk[STARTUP_TASK_STK_SIZE];
static OS_STK led_task_stk[LED_TASK_STK_SIZE];


OS_MEM *CommTxBuffer;                           //定义内存分区指针
INT8U commTxPart[50][64];                       //定义内存分区和内存块
INT8U err;
INT8U *BlkPtr;                                  //定义内存块指针


/******************************************************************************* 
******************************************************************************** 
* 函数名称: main()
* 
* 功    能: -- 
* 
* 作    者: 秦战强
* 日    期: 2016/12/19
******************************************************************************** 
*******************************************************************************/ 
void main(void) {  
  BSP_Init();    
  OSInit();
  
#if OS_MEM_EN == 1  
  CommTxBuffer = OSMemCreate(                   //创建一个内存分区
                             commTxPart,
                             50,
                             64,
                             &err
                             );
  
#endif  
  
#if OS_STK_GROWTH == 1                          //堆栈向下生长时
  
  OSTaskCreate(Task_Start,
               (void *)0,
               &startup_task_stk[STARTUP_TASK_STK_SIZE-1], 
               STARTUP_TASK_PRIO);
  
  OSTaskCreate(Task_LED,
               (void *)0,
               &led_task_stk[LED_TASK_STK_SIZE-1], 
               LED_TASK_PRIO);
#else                                           //堆栈向上生长时
  
  OSTaskCreate(Task_Start,
               (void *)0,
               &startup_task_stk[0], 
               STARTUP_TASK_PRIO);
  
  OSTaskCreate(Task_LED,
               (void *)0,
               &led_task_stk[0], 
               LED_TASK_PRIO);
  
#endif
  
  
  OSStart();                                    //开始任务调度之前必须创建至少一个任务

} 







  




