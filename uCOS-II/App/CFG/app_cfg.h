/******************** (C) COPYRIGHT 2011 野火嵌入式开发工作室 ********************
 * 文件名       ：app.c
 * 描述         ：uC/OS的用户任务函数配置头文件
 *
 * 实验平台     ：野火kinetis开发板
 * 库版本       ：
 * 嵌入系统     ：
 *
 * 作者         ：野火嵌入式开发工作室
 * 淘宝店       ：http://firestm32.taobao.com
 * 技术支持论坛 ：http://www.ourdev.cn/bbs/bbs_list.jsp?bbs_id=1008
**********************************************************************************/

#ifndef  _APP_CFG_H_
#define  _APP_CFG_H_



/*
*********************************************************************************************************
*                                            任务优先级
*********************************************************************************************************
*/

#define  STARTUP_TASK_PRIO       4                      //定义开始任务优先级
#define  LED_TASK_PRIO           5                      //定义LED任务优先级

#define  OS_TASK_TMR_PRIO        (OS_LOWEST_PRIO - 2u)


/*
*********************************************************************************************************
*                                     任务栈大小（单位为 OS_STK ）
*********************************************************************************************************
*/

#define STARTUP_TASK_STK_SIZE   128u                    //定义开始任务的堆栈长度
#define LED_TASK_STK_SIZE       128u                    //定义LED任务的堆栈长度






#endif  //_APP_CFG_H_
