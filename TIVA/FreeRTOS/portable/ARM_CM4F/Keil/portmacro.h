/* Minimal Keil/ARMCC-compatible portmacro.h for build-only purposes */
#ifndef PORTMACRO_H
#define PORTMACRO_H

#include <stdint.h>
#include "FreeRTOS.h"

/* Type definitions. */
#define portSTACK_TYPE uint32_t
#define portBASE_TYPE long

typedef portSTACK_TYPE StackType_t;
typedef unsigned long UBaseType_t;
typedef long BaseType_t;

/* Architecture specifics */
#define portBYTE_ALIGNMENT 8

/* Minimal interrupt control macros (no-op for build) */
#define portDISABLE_INTERRUPTS()    do { /* stub */ } while(0)
#define portENABLE_INTERRUPTS()     do { /* stub */ } while(0)

/* ISR mask helpers (stub) */
#define portSET_INTERRUPT_MASK_FROM_ISR() ( 0 )
#define portCLEAR_INTERRUPT_MASK_FROM_ISR(x) ( (void)(x) )

/* Yield (stub) */
#define portYIELD_FROM_ISR() do { /* stub */ } while(0)

#endif /* PORTMACRO_H */
