/******************** (C) COPYRIGHT 2011 �人����ѧ��սǿ ********************
 * �ļ���       ��main.c
 * ����         ������ģ��ʵ��
 *
 * ʵ��ƽ̨     ��Ұ��kinetis������
 * ��汾       ��
 * Ƕ��ϵͳ     ��
 *
 * ����         ���人����ѧ��սǿ
**********************************************************************************/

#include "include.h"

//�����ﶨ�������ջ������app_cfg.h�����ö�ջ��С���������ȼ�
static OS_STK startup_task_stk[STARTUP_TASK_STK_SIZE];
static OS_STK led_task_stk[LED_TASK_STK_SIZE];


OS_MEM *CommTxBuffer;                           //�����ڴ����ָ��
INT8U commTxPart[50][64];                       //�����ڴ�������ڴ��
INT8U err;
INT8U *BlkPtr;                                  //�����ڴ��ָ��


/******************************************************************************* 
******************************************************************************** 
* ��������: main()
* 
* ��    ��: -- 
* 
* ��    ��: ��սǿ
* ��    ��: 2016/12/19
******************************************************************************** 
*******************************************************************************/ 
void main(void) {  
  BSP_Init();    
  OSInit();
  
#if OS_MEM_EN == 1  
  CommTxBuffer = OSMemCreate(                   //����һ���ڴ����
                             commTxPart,
                             50,
                             64,
                             &err
                             );
  
#endif  
  
#if OS_STK_GROWTH == 1                          //��ջ��������ʱ
  
  OSTaskCreate(Task_Start,
               (void *)0,
               &startup_task_stk[STARTUP_TASK_STK_SIZE-1], 
               STARTUP_TASK_PRIO);
  
  OSTaskCreate(Task_LED,
               (void *)0,
               &led_task_stk[LED_TASK_STK_SIZE-1], 
               LED_TASK_PRIO);
#else                                           //��ջ��������ʱ
  
  OSTaskCreate(Task_Start,
               (void *)0,
               &startup_task_stk[0], 
               STARTUP_TASK_PRIO);
  
  OSTaskCreate(Task_LED,
               (void *)0,
               &led_task_stk[0], 
               LED_TASK_PRIO);
  
#endif
  
  
  OSStart();                                    //��ʼ�������֮ǰ���봴������һ������

} 







  




