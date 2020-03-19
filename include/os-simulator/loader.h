#ifndef OS_SIMULATOR_LOADER_H
#define OS_SIMULATOR_LOADER_H

#include "memory.h"

struct job
{
	int16_t* start, size;
};

struct job_list
{
	int32_t* size;
	struct job* _job;
};

struct job_details
{
	int16_t id, instruction, priority, input_buff_size, output_buff_size, temp_buff_size;
};

#endif // OS_SIMUALTOR_LOADER_H
