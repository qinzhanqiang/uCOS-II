/******************** (C) COPYRIGHT 2011 Ұ��Ƕ��ʽ���������� ********************
 * �ļ���       ��isr.h
 * ����         �����º궨���жϺţ���ӳ���ж�����������жϺ�����ַ��
 *                ʹ��ָ��������������жϷ������������жϷ�����
 *                ���棺ֻ����"vectors.c"���������ұ�����"vectors.h"�����ĺ��棡����
 *
 * ʵ��ƽ̨     ��Ұ��kinetis������
 * ��汾       ��
 * Ƕ��ϵͳ     ��
 *
 * ����         ��Ұ��Ƕ��ʽ����������
 * �Ա���       ��http://firestm32.taobao.com
 * ����֧����̳ ��http://www.ourdev.cn/bbs/bbs_list.jsp?bbs_id=1008
**********************************************************************************/

/******************************************************************************* 
******************************************************************************** 
* �ļ�����: isr.h
*
* ��    ��: �жϷ������ͷ�ļ������º궨���жϺţ���ӳ���ж�����������жϺ�����ַ��
*           ʹ��ָ��������������жϷ������������жϷ�����
*           ���棺ֻ����"vectors.c"���������ұ�����"vectors.h"�����ĺ��棡����
* 
* 
* ��    ��: ��սǿ
* ��    ��: 2016/12/29
******************************************************************************** 
*******************************************************************************/ 




#ifndef __ISR_H
#define __ISR_H 1

#include  "include.h"

/*                          ���¶����ж�������
 *  ��ȡ��Ĭ�ϵ��ж�����Ԫ�غ궨��       #undef  VECTOR_xxx
 *  �����¶��嵽�Լ���д���жϺ���       #define VECTOR_xxx    xxx_IRQHandler
 *  ���磺
 *       #undef  VECTOR_003
 *       #define VECTOR_003    HardFault_IRQHandler    ���¶���Ӳ���Ϸ��жϷ�����
 */
#undef  VECTOR_014
#undef  VECTOR_015
#if     USOC_EN > 0u                            //�����������ucosϵͳ  ��ucos�ĵδ�ʱ���жϷ�����
#define VECTOR_014    OS_CPU_PendSVHandler
#define VECTOR_015    OS_CPU_SysTickHandler
#else
#define VECTOR_014    PendSV_Handler
#define VECTOR_015    SysTick_Handler           //�δ�ʱ��  OS�õõ�
#endif


#undef  VECTOR_003
#define VECTOR_003    HardFault_IRQHandler         //����Ӳ���Ϸ� �����ǳ����ܷ��ˣ�     �Ƽ����Գ���ʱ���ø�LED��ʾ��ָʾ�����ܷ���

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

#undef  VECTOR_061                              //Ҫ��ȡ���ˣ���Ϊ��vectors.h��Ĭ���Ƕ���Ϊ default_isr  
#define VECTOR_061    USART0_IRQHandler         //���¶���63���жϵ�ISR��UART0��Single interrupt vector for UART status sources

#undef  VECTOR_062                              
#define VECTOR_062    USART0Error_IRQHandler    

#undef  VECTOR_063                              //Ҫ��ȡ���ˣ���Ϊ��vectors.h��Ĭ���Ƕ���Ϊ default_isr  
#define VECTOR_063    USART1_IRQHandler         //���¶���63���жϵ�ISR��UART1��Single interrupt vector for UART status sources

#undef  VECTOR_064                              
#define VECTOR_064    USART1Error_IRQHandler 

#undef  VECTOR_065                              //Ҫ��ȡ���ˣ���Ϊ��vectors.h��Ĭ���Ƕ���Ϊ default_isr  
#define VECTOR_065    USART2_IRQHandler         //���¶���63���жϵ�ISR��UART2��Single interrupt vector for UART status sources

#undef  VECTOR_066                              
#define VECTOR_066    USART2Error_IRQHandler 

#undef  VECTOR_067                              //Ҫ��ȡ���ˣ���Ϊ��vectors.h��Ĭ���Ƕ���Ϊ default_isr  
#define VECTOR_067    USART3_IRQHandler         //���¶���63���жϵ�ISR��UART3��Single interrupt vector for UART status sources

#undef  VECTOR_068                              
#define VECTOR_068    USART3Error_IRQHandler 

#undef  VECTOR_069                              //Ҫ��ȡ���ˣ���Ϊ��vectors.h��Ĭ���Ƕ���Ϊ default_isr  
#define VECTOR_069    USART4_IRQHandler         //���¶���63���жϵ�ISR��UART4��Single interrupt vector for UART status sources

#undef  VECTOR_070                              
#define VECTOR_070    USART4Error_IRQHandler 

#undef  VECTOR_071                              //Ҫ��ȡ���ˣ���Ϊ��vectors.h��Ĭ���Ƕ���Ϊ default_isr  
#define VECTOR_071    USART5_IRQHandler         //���¶���63���жϵ�ISR��UART5��Single interrupt vector for UART status sources

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
#define VECTOR_078    FTM0_IRQHandler           //FTM0���벶׽�ж� 

#undef  VECTOR_079
#define VECTOR_079    FTM1_IRQHandler           //FTM1���벶׽�ж�

#undef  VECTOR_080
#define VECTOR_080    FTM2_IRQHandler           //FTM2���벶׽�ж�

#undef  VECTOR_081
#define VECTOR_081    CMT_IRQHandler 

#undef  VECTOR_082
#define VECTOR_082    RTC_IRQHandler 

#undef  VECTOR_084
#define VECTOR_084    PIT0_IRQHandler           //���¶���84���ж�ΪPIT0_IRQHandler�ж�

#undef  VECTOR_085
#define VECTOR_085    PIT1_IRQHandler           //���¶���84���ж�ΪPIT1_IRQHandler�ж�

#undef  VECTOR_086
#define VECTOR_086    PIT2_IRQHandler           //���¶���84���ж�ΪPIT2_IRQHandler�ж�

#undef  VECTOR_087
#define VECTOR_087    PIT3_IRQHandler           //���¶���84���ж�ΪPIT3_IRQHandler�ж�

#undef  VECTOR_103
#define VECTOR_103    PORTA_IRQHandler          //PORTA�ж�

#undef  VECTOR_104
#define VECTOR_104    PORTB_IRQHandler          //PORTB�ж�

#undef  VECTOR_105
#define VECTOR_105    PORTC_IRQHandler          //PORTC�ж�

#undef  VECTOR_106
#define VECTOR_106    PORTD_IRQHandler          //PORTD�ж�

#undef  VECTOR_107
#define VECTOR_107    PORTE_IRQHandler          //PORTE�ж�


extern void PendSV_Handler(void);               //�������ϵͳ�����жϷ�����
extern void HardFault_Handler(void);            //����Ӳ���Ϸã������ܷɣ�
extern void SysTick_Handler(void);              //�δ�ʱ��(os �õ�)
extern void USART1_IRQHandler();                //����1 �жϽ��պ���
extern void PIT0_IRQHandler();                  //PIT0 ��ʱ�жϷ�����
extern void PORTA_IRQHandler();                 //PORTA�жϷ�����
extern void PORTB_IRQHandler();                 //PORTB�жϷ�����
extern void FTM0_IRQHandler();                  //FTM0���벶׽�ж�
extern void FTM1_IRQHandler();                  //FTM0���벶׽�ж�


#endif  //__ISR_H

/* End of "isr.h" */
