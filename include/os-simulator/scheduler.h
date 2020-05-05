#ifndef OS_SIMULATOR_SCHEDULER_H
#define OS_SIMULATOR_SCHEDULER_H

#include <os-simulator/pcb.h>

void
scheduler_init(void);

void
scheduler_load_jobs(void);

void
scheduler_schedule_job(void);

struct pcb
scheduler_running_pcb_get(void);

void
scheduler_running_pcb_set(struct pcb pcb);

#endif // OS_SIMULATOR_SCHEDULER_H
