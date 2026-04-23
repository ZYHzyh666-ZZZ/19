/* rtos_tasks.h - RTOS task prototypes for Project */
#ifndef _RTOS_TASKS_H_
#define _RTOS_TASKS_H_

#include "SysConfig.h"

// FreeRTOS 任务接口
void vSchedulerTask(void *pvParameters);
void vTask10ms(void *pvParameters);
void vSendAttitudeTask(void *pvParameters);

#endif
