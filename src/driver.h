#include <os-simulator/driver.h>

#include <stdarg.h>

void
driver_error(const char* format, ...)
{
	va_list args;

	va_start(args);

	vfprintf(stderr, format, args);

	va_end(args);

	abort();
}
