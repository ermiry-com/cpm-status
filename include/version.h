#ifndef _CPM_VERSION_H_
#define _CPM_VERSION_H_

#define CPM_VERSION					"0.1"
#define CPM_VERSION_NAME			"Version 0.1"
#define CPM_VERSION_DATE			"02/05/2021"
#define CPM_VERSION_TIME			"23:58 CST"
#define CPM_VERSION_AUTHOR			"Erick Salas"

// print full cpm version information
extern void cpm_version_print_full (void);

// print the version id
extern void cpm_version_print_version_id (void);

// print the version name
extern void cpm_version_print_version_name (void);

#endif