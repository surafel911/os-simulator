#include <os-simulator/driver.h>

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void
driver_error(const char* format, ...)
{
	va_list args;

	va_start(args, format);

	fprintf(stderr, "ERROR: ");
	vfprintf(stderr, format, args);
	fprintf(stderr, "\n\n");

	va_end(args);

	abort();
}
