#include <os-simulator/loader.h>

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <os-simulator/dma.h>
#include <os-simulator/storage.h>

#define LOADER_INPUT_BUFF_SIZE	20

struct jcc {
	uint32_t id, size, priority;
};
struct job {
	uint32_t* buffer;
	struct jcc jcc;
};

struct job_list {
	struct job* jobs;
	int job_count;
};

static inline void
_loader_job_init(struct job* job)
{
	job->buffer = NULL;

	job->jcc.id = 0;
	job->jcc.size = 0;
	job->jcc.priority = 0;
}

static inline void
_loader_job_list_init(struct job_list* job_list)
{
	job_list->jobs = NULL;
	job_list->job_count = 0;
}

static inline void
_loader_job_list_free(struct job_list* job_list)
{
	for (int i = 0; i < job_list->job_count; i++) {
		free(job_list->jobs[i].buffer);
	}

	free(job_list->jobs);
}

static void
_loader_read_jcc(FILE* file, struct jcc* jcc)
{
	fscanf(file, "// JOB %X %X %X\n",
		&jcc->id, &jcc->size, &jcc->priority);
}

static void
_loader_read_job_instructions(FILE* file, struct job* job)
{
	job->buffer = malloc(sizeof(*job->buffer) * job->jcc.size);

	for (int i = 0; i < job->jcc.size; i++) {
		fscanf(file, "%X\n", job->buffer + i);
	}
}

static void
_loader_read_job_data(FILE* file, struct job* job)
{
	uint32_t* data;

	job->buffer = realloc(job->buffer, sizeof(*job->buffer) * 
		(job->jcc.size + LOADER_INPUT_BUFF_SIZE));

	data = job->buffer + job->jcc.size;

	for (int i = 0; i < LOADER_INPUT_BUFF_SIZE; i++) {
		fscanf(file, "%X\n", data + i);
	}
}

static void
_loader_read_job(FILE* file, struct job* job)
{
	char tmp[32];

	_loader_job_init(job);

	_loader_read_jcc(file, &job->jcc);
	_loader_read_job_instructions(file, job);

	fgets(tmp, sizeof(tmp), file);

	_loader_read_job_data(file, job);
		
	fgets(tmp, sizeof(tmp), file);

	while (strcmp(tmp, "0x00000000\n") == 0) {
		fgets(tmp, sizeof(tmp), file);
	}
}

static void
_loader_read_jobs(FILE* file, struct job_list* job_list)
{
	char tmp[32];

	while(true) {
		job_list->jobs = realloc(job_list->jobs, sizeof(*job_list->jobs) *
			(job_list->job_count + 1));

		_loader_read_job(file, job_list->jobs + job_list->job_count);
		job_list->job_count++;

		fgets(tmp, sizeof(tmp), file);
		if (feof(file) == 1) {
			break;
		}

		fseek(file, -strlen(tmp), SEEK_CUR);
	}
}

static void
_loader_write_jobs_to_disk(struct job_list* job_list)
{
	struct job* job;

	int i, disk_addr;

	storage_disk_set(0, job_list->job_count);

	disk_addr = job_list->job_count + 1;

	for (i = 0; i < job_list->job_count; i++) {
		job = job_list->jobs + i;

		storage_disk_set(i + 1, disk_addr);

		storage_disk_set(disk_addr++, job->jcc.id);
		storage_disk_set(disk_addr++, job->jcc.size);
		storage_disk_set(disk_addr++, job->jcc.priority);

		dma_write(DMA_DISK_CHANNEL, disk_addr, job->buffer,
			job->jcc.size + LOADER_INPUT_BUFF_SIZE);

		disk_addr += job->jcc.size + LOADER_INPUT_BUFF_SIZE;
	}
}

void
loader_load_jobs_to_disk(FILE* file)
{
	struct job_list job_list;
	
	_loader_job_list_init(&job_list);

	_loader_read_jobs(file, &job_list);
	_loader_write_jobs_to_disk(&job_list);

	_loader_job_list_free(&job_list);
}
