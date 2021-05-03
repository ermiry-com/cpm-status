#include <cerver/utils/log.h>

#include "version.h"

// print full cpm version information
void cpm_version_print_full (void) {

	cerver_log_msg ("\nCPM Status Version: %s\n", CPM_VERSION_NAME);
	cerver_log_msg ("Release Date & time: %s - %s\n", CPM_VERSION_DATE, CPM_VERSION_TIME);
	cerver_log_msg ("Author: %s\n", CPM_VERSION_AUTHOR);

}

// print the version id
void cpm_version_print_version_id (void) {

	cerver_log_msg ("\nCPM Status Version ID: %s\n", CPM_VERSION);

}

// print the version name
void cpm_version_print_version_name (void) {

	cerver_log_msg ("\nCPM Status Version: %s\n", CPM_VERSION_NAME);

}