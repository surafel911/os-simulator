#include <os-simulator/memory.h>
#include <os-simulator/loader.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void loader()
{
	int32_t* disk = disk_get_buff();
	struct job_list* list = (struct job_list*)malloc(sizeof(int32_t) + sizeof(struct job*));
	list->size = *disk;
	list->_job = (struct job*)malloc(disk + 1);

	list->size = 0;

	FILE* file = fopen("Datafile", "r");
	int32_t count = 32;

	while(!feof(file))
	{
		char* type = (char*)malloc(sizeof(char));

		int32_t code, job_id, instruction_count, priority;

		fscanf(file, "// %s %X %X %X\n", type, &job_id, &instruction_count, &priority);

		for (int32_t i = 0; i < instruction_count; i++)
		{
			fscanf(file, "%X\n", code);
			disk[i + count];
		}
		
		list->_job[list->size]->size = count;

		int data_id, data_count, priority;

		fscanf(file, "// %s %X %X %X\n", type, &data_id, &data_count, &priority);

		for (int32_t i = 0; i < data_count; i++)
		{
			fscanf(file, "%X\n", code);
			disk[i + count];
		}
	}
}
