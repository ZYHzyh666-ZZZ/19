#include "rtos_tasks.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Ano_Scheduler.h"
#include "ANO_DT_LX.h"

// 调度器任务：在 RTOS 下运行原有的合作式调度器
void vSchedulerTask(void *pvParameters)
{
    (void)pvParameters;
    for (;;)
    {
        Scheduler_Run();
        // 让出，避免完全占用 CPU
        vTaskDelay(pdMS_TO_TICKS(1));
    }
}

// 10ms 定时任务：每 10ms 执行一次，用于放置需要 100Hz 执行的逻辑
void vTask10ms(void *pvParameters)
{
    (void)pvParameters;
    TickType_t xLastWakeTime = xTaskGetTickCount();
    const TickType_t xFrequency = pdMS_TO_TICKS(10);
    for (;;)
    {
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
        // 示例：调用通信交换接口（原代码中有相关接口）
        ANO_LX_Data_Exchange_Task(0.01f);
    }
}

// 姿态发送任务：周期性发送姿态数据（默认 50ms）
void vSendAttitudeTask(void *pvParameters)
{
    (void)pvParameters;
    TickType_t xLastWakeTime = xTaskGetTickCount();
    const TickType_t xFrequency = pdMS_TO_TICKS(50);
    for (;;)
    {
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
        ANO_DT_Send_MY_DATA_1();
    }
}
