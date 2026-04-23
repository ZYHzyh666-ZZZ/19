/* Minimal Keil/ARMCM4F port.c — C stubs to allow ARMCC build (not a full port)
   This provides simple, non-functional implementations so the project compiles
   under ARMCC. Replace with real Keil port for production. */

#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"

/* Minimal critical nesting variable */
static UBaseType_t uxCriticalNesting = 0xaaaaaaaa;

void vPortSetupTimerInterrupt( void )
{
    /* Stub: user/system should implement SysTick setup */
}

BaseType_t xPortStartScheduler( void )
{
    /* Initialise and start scheduler — minimal stub */
    uxCriticalNesting = 0;
    vPortSetupTimerInterrupt();
    /* Not actually starting tasks here. Return success to satisfy callers. */
    return 0;
}

void vPortEndScheduler( void )
{
    /* Not implemented */
}

void vPortEnterCritical( void )
{
    uxCriticalNesting++;
}

void vPortExitCritical( void )
{
    if( uxCriticalNesting > 0 )
    {
        uxCriticalNesting--;
    }
}

uint32_t ulSetInterruptMaskFromISR( void )
{
    /* Stub: return dummy mask */
    return 0UL;
}

void vClearInterruptMaskFromISR( uint32_t ulMask )
{
    ( void ) ulMask;
}

void vPortYield( void )
{
    /* stub */
}

void vPortStartFirstTask( void )
{
    /* stub */
}

void vPortSVCHandler( void )
{
    /* stub */
}

void xPortPendSVHandler( void )
{
    /* stub */
}

void xPortSysTickHandler( void )
{
    /* stub */
}
