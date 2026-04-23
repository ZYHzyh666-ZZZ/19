/******************** (C) COPYRIGHT 2017 ANO Tech ********************************
 * 作者    ：匿名科创
 * 官网    ：www.anotc.com
 * 淘宝    ：anotc.taobao.com
 * 技术Q群 ：190169595
 * 描述    ：主循环
**********************************************************************************/
#include "SysConfig.h"
#include "Ano_Scheduler.h"
#include "rtos_tasks.h"
#include "FreeRTOS.h"
#include "task.h"

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
	while (1)
	{
		//当系统出错后，会进入这个死循环
	}
}
#endif
//=======================================================================================
//=======================================================================================
int main(void)
{
	//进行所有设备的初始化，并将初始化结果保存
	All_Init();
	//调度器初始化，系统为裸奔，这里人工做了一个时分调度器
	Scheduler_Setup();
	// 创建 RTOS 任务：调度器任务、10ms 定时任务、姿态发送任务
	xTaskCreate(vSchedulerTask, "SCH", 256, NULL, tskIDLE_PRIORITY + 3, NULL);
	xTaskCreate(vTask10ms, "T10ms", 256, NULL, tskIDLE_PRIORITY + 2, NULL);
	xTaskCreate(vSendAttitudeTask, "SendAtt", 256, NULL, tskIDLE_PRIORITY + 2, NULL);

	// 启动 FreeRTOS 调度器（不返回）
	vTaskStartScheduler();

	// 理论上不会运行到这里
	while (1)
	{
		//ok
		//Scheduler_Run();
	}
}
/******************* (C) COPYRIGHT 2014 ANO TECH *****END OF FILE************/
