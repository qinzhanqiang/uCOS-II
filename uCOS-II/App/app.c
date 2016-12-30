/******************** (C) COPYRIGHT 2011 武汉理工大学秦战强 ********************
 * 文件名       ：app.c
 * 描述         ：用户任务函数，目前只有一个启动任务
 *
 * 实验平台     ：野火kinetis开发板
 * 库版本       ：
 * 嵌入系统     ：uC/OS-II V2.92
 *
 * 作者         ：武汉理工大学秦战强
**********************************************************************************/

#include <app.h>
#include  "ucos_ii.h"  		                        
#include  "LED.h"
#include  "sysinit.h"          
#include <BSP.h>

/******************************************************************************* 
******************************************************************************** 
* 函数名称: uCOS-II函数调用
* 
* 功    能: 常用函数的调用 
* 
* 作    者: 秦战强
* 日    期: 2016/12/20
******************************************************************************** 
*******************************************************************************/
//OSTaskCreate(Task_Start,
//             (void *)0,
//             &startup_task_stk[STARTUP_TASK_STK_SIZE-1], 
//             STARTUP_TASK_PRIO);                        //创建任务
//OSTaskSuspend(prio);                                    //挂起任务
//OSTaskResume(prio);                                     //恢复任务
//OSTaskChangePrio(oldprio,newprio);                      //修改优先级
//OSTaskDel(prio);                                        //删除任务
//OSTaskQuery(prio,*pdata);                               //查询任务信息




/*************************************************************************
*                             武汉理工大学秦战强
*
*  函数名称：Task_Start
*  功能说明：启动任务,初始化滴答时钟
*  参数说明：p_arg       没用
*  函数返回：无
*  修改时间：2012-2-10
*  备    注：
*************************************************************************/
void Task_Start(void *p_arg)
{
    SysTick_init();

    #if (OS_TASK_STAT_EN > 0)
        /*       开启统计任务           */
        OSStatInit();
    #endif

    /******************* 用户任务区 ************************/

    while (1)
    {
        LED_turn(LED0);                                         //LED0闪烁
        OSTimeDlyHMSM(0, 0, 0, 100);
    }
}


/******************************************************************************* 
******************************************************************************** 
* 函数名称: Task_LED()
* 
* 功    能: -- 
* 
* 作    者: 秦战强
* 日    期: 2016/12/20
******************************************************************************** 
*******************************************************************************/ 
void Task_LED(void * pdata) 
{
  INT8U time = 0;
  
  # if OS_CRITICAL_METHOD == 3
    OS_CPU_SR cpu_sr;                           //声明变量cpu_sr
  # endif
    
  #if (OS_TASK_STAT_EN > 0)
    OSStatInit();                               //开启统计任务
  #endif
  
  for(;;)
  {        
    OS_ENTER_CRITICAL();                        //关中断
    //put your code here
    LED_turn(LED0);                             //LED0闪烁
    OSTimeDlyHMSM(0, 0, 0, 100);
    
    if(time == 20)
    {
      OSTaskSuspend(LED_TASK_PRIO);             //挂起任务
    }
    if(time ==40)
    {
      time = 0;
      OSTaskResume(LED_TASK_PRIO);              //恢复任务
    }
    
    time ++;
    OS_EXIT_CRITICAL();                 //开中断
  } 
} 


/******************************************************************************* 
******************************************************************************** 
* 函数名称: Task_MemGet()
* 
* 功    能: 请求一个内存块任务,等待一分钟，释放内存块。
*           需要在主函数中使用OSMemCreate函数创建一个内存分区，
*           请求内存块时不能超过定义内存块长度范围
*               
* 
* 作    者: 秦战强
* 日    期: 2016/12/30
******************************************************************************** 
*******************************************************************************/ 
void Task_MemGet(void * pdata) 
{
  extern OS_MEM *CommTxBuffer;                           //定义内存分区指针  
  extern INT8U commTxPart[50][64];                       //定义内存分区和内存块
  extern INT8U err;
  extern INT8U *BlkPtr;                                  //定义内存块指针


# if OS_CRITICAL_METHOD == 3
  OS_CPU_SR cpu_sr;                     //声明变量cpu_sr
# endif
  
#if (OS_TASK_STAT_EN > 0)
  OSStatInit();                         //开启统计任务
#endif
  
  for(;;)
  {        
    OS_ENTER_CRITICAL();                //关中断
    //put your code here
    
    BlkPtr = OSMemGet(                  //请求一个内存块
                      CommTxBuffer,
                      &err
                      );
    
    OSTimeDlyHMSM(0,1,0,0);
    
    OSMemPut(CommTxBuffer,              //释放一个内存块
             BlkPtr
             );
    
    OS_EXIT_CRITICAL();                 //开中断
  } 
} 

    
      

