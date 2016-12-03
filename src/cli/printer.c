#include <stdio.h>

#include "printer.h"

static const char *messages[] = {
	[0] = NULL,
	[PROCTAL_ERROR_OUT_OF_MEMORY] = "Ran out of memory.",
	[PROCTAL_ERROR_PERMISSION_DENIED] = "Permission denied.",
	[PROCTAL_ERROR_WRITE_FAILURE] = "Failed to write everything out.",
	[PROCTAL_ERROR_READ_FAILURE] = "Failed to read everything in.",
	[PROCTAL_ERROR_UNKNOWN] = "An unknown failure occurred.",
	[PROCTAL_ERROR_UNIMPLEMENTED] = "Feature not implemented.",
	[PROCTAL_ERROR_UNSUPPORTED] = "Feature not supported.",
	[PROCTAL_ERROR_UNSUPPORTED_WATCH_READ] =
		"Watching only for reads is not supported yet."
		" You can watch for both reads and writes, though.",
	[PROCTAL_ERROR_UNSUPPORTED_WATCH_READ_EXECUTE] =
		"Watching for reads and instruction executions at once is not supported.",
	[PROCTAL_ERROR_UNSUPPORTED_WATCH_WRITE_EXECUTE] =
		"Watching for writes and instruction executions at once is not supported.",
	[PROCTAL_ERROR_UNSUPPORTED_WATCH_READ_WRITE_EXECUTE] =
		"Watching for reads, writes and instruction executions at once is not supported.",
	[PROCTAL_ERROR_PROCESS_NOT_FOUND] = "Process not found.",
	[PROCTAL_ERROR_PROCESS_NOT_SET] = "Process was not set.",
	[PROCTAL_ERROR_INJECT_ADDR_NOT_FOUND] = "Could not find a suitable address in memory to inject code in.",
	[PROCTAL_ERROR_PROCESS_SEGFAULT] = "Process hit segmentation fault.",
	[PROCTAL_ERROR_PROCESS_EXITED] = "Process has exited.",
	[PROCTAL_ERROR_PROCESS_STOPPED] = "Process has stopped.",
	[PROCTAL_ERROR_PROCESS_UNTAMEABLE] = "Process is in a state that cannot be dealt with.",
};

void cli_print_proctal_error(proctal p)
{
	int error = proctal_error(p);

	if (error == 0) {
		return;
	}

	if (!((unsigned) error < (sizeof messages / sizeof messages[0]))) {
		error = PROCTAL_ERROR_UNKNOWN;
	}

	fprintf(stderr, "%s\n", messages[error]);
}