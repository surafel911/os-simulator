#include <os-simulator/memory.h>
#include <os-simulator/loader.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void loader()
{
	int32_t* disk = disk_get_buff();
	
	// list of all the jobs
	struct job_list list = {.size = disk, ._job = (struct job*)(disk + 1)};

	FILE* file = fopen("Datafile(30)", "r");
	int32_t count = 32;

	while(!feof(file))
	{
		char* type = (char*)malloc(5 * sizeof(char));

		unsigned int code, job_id, instruction_count, priority;

		// strips job instructions 
		fscanf(file, "// %s %X %X %X\n", type, &job_id, &instruction_count, &priority);

		if (!strcmp(type, "END"))
		{
			//printf("// END\n");
		}
		else if (!strcmp(type, ""))
		{
			fscanf(file, "%X\n", &code);
			//printf("Code: %d\n", code);
			continue;
		}
		else
		{		
			disk[count] = (int32_t)type;
			//printf("Type: %d (%s)\n", disk[count], type);
			disk[count + 1] = job_id;
			//printf("Job ID: %d\n", disk[count + 1]);
			disk[count + 2] = instruction_count;
			//printf("Instruction count: %d\n", disk[count + 2]);
			disk[count + 3] = priority;
			//printf("Priority: %d\n", disk[count + 3]);

			//printf("%s %d %d %d\n", type, code, instruction_count, priority);
			// strips instructions and adds to disk
			for (int32_t i = 0; i < instruction_count; i++)
			{
				fscanf(file, "%X\n", &code);
				disk[i + count] = code;
				//printf("Code: %X\n", disk[i + count]);
			}
			
			count += instruction_count;
		
			list._job[*list.size].size = instruction_count;
			unsigned int data_id, data_count;

			fscanf(file, "// %s %X %X %X\n", type, &data_id, &data_count, &priority);
			disk[count] = (int32_t)type;
			//printf("Type: %d (%s)\n", disk[count], type);
			disk[count + 1] = data_id;
			//printf("ID: %d\n", disk[count + 1]);
			disk[count + 2] = data_count;
			//printf("Count: %d\n", disk[count + 2]);
			disk[count + 3] = priority;
			//printf("Priority: %d\n", disk[count + 3]);

			//printf("%s %X %X %X\n", type, data_id, data_count, priority);

			for (int32_t i = 0; i < data_count; i++)
			{
				fscanf(file, "%X\n", &code);
				disk[i + count] = code;
				//printf("Code: %X\n", disk[i + count]);
			}
			count += data_count;
		}
	}
}
