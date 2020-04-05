#ifndef OS_SIMULATOR_SCHEDULER_H
#define OS_SIMULATOR_SCHEDULER_H

#include <os-simulator/pcb.h>

/*
 cycles scheduler
 */

void
scheduler_cycle(void);

/* Loads the next job  */
void
scheduler_pcb_load_next(void);

/*
 Gets job next in line to be executed. Either NULL or priority == 0
 if there is no next process 
 */
 uint16_t
scheduler_pcb_get_next(void);

/* Gets current job. Either NULL or priority == 0 if there isn't 
 a running process 
 */
 uint16_t
scheduler_pcb_get_current(void);

#endif // OS_SIMULATOR_SCHEDULER_H
