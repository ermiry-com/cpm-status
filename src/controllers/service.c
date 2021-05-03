#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <cerver/http/response.h>

#include <cerver/utils/utils.h>

#include "version.h"

HttpResponse *cpm_works = NULL;
HttpResponse *current_version = NULL;

HttpResponse *catch_all = NULL;

unsigned int cpm_service_init (void) {

	unsigned int retval = 1;

	cpm_works = http_response_json_key_value (
		(http_status) 200, "msg", "CPM status works!"
	);

	char *status = c_string_create (
		"%s - %s",
		CPM_VERSION_NAME, CPM_VERSION_DATE
	);

	if (status) {
		current_version = http_response_json_key_value (
			(http_status) 200, "version", status
		);

		free (status);
	}

	catch_all = http_response_json_key_value (
		(http_status) 200, "msg", "CPM status service!"
	);

	if (
		catch_all
		&& cpm_works && current_version
	) retval = 0;

	return retval;

}

void cpm_service_end (void) {

	http_response_delete (cpm_works);
	http_response_delete (current_version);

	http_response_delete (catch_all);

}
