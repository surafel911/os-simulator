#ifndef OS_SIMULATOR_JOB_H
#define OS_SIMULATOR_JOB_H

#include <stdint.h>

struct job_control_card {
	uint32_t id, size, priority;
};

#endif // OS_SIMULATOR_JOB_H
