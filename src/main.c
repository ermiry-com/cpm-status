#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>
#include <signal.h>

#include <cerver/version.h>
#include <cerver/cerver.h>

#include <cerver/http/http.h>
#include <cerver/http/route.h>

#include <cerver/utils/log.h>
#include <cerver/utils/utils.h>

#include "cpm.h"
#include "version.h"

#include "routes/service.h"

static Cerver *cpm_api = NULL;

void end (int dummy) {
	
	if (cpm_api) {
		cerver_stats_print (cpm_api, false, false);
		cerver_log_msg ("\nHTTP Cerver stats:\n");
		http_cerver_all_stats_print ((HttpCerver *) cpm_api->cerver_data);
		cerver_log_line_break ();
		cerver_teardown (cpm_api);
	}

	(void) cpm_end ();

	cerver_end ();

	exit (0);

}

static void cpm_set_cpm_routes (HttpCerver *http_cerver) {

	/* register top level route */
	// GET /api/status
	HttpRoute *cpm_route = http_route_create (REQUEST_METHOD_GET, "api/status", cpm_handler);
	http_cerver_route_register (http_cerver, cpm_route);

	/* register cpm children routes */
	// GET api/status/version
	HttpRoute *cpm_version_route = http_route_create (REQUEST_METHOD_GET, "version", cpm_version_handler);
	http_route_child_add (cpm_route, cpm_version_route);

}

static void start (void) {

	cpm_api = cerver_create (
		CERVER_TYPE_WEB,
		"cpm-api",
		PORT,
		PROTOCOL_TCP,
		false,
		CERVER_CONNECTION_QUEUE
	);

	if (cpm_api) {
		/*** cerver configuration ***/
		cerver_set_receive_buffer_size (cpm_api, CERVER_RECEIVE_BUFFER_SIZE);
		cerver_set_thpool_n_threads (cpm_api, CERVER_TH_THREADS);
		cerver_set_handler_type (cpm_api, CERVER_HANDLER_TYPE_THREADS);

		/*** web cerver configuration ***/
		HttpCerver *http_cerver = (HttpCerver *) cpm_api->cerver_data;

		cpm_set_cpm_routes (http_cerver);

		// add a catch all route
		http_cerver_set_catch_all_route (http_cerver, cpm_catch_all_handler);

		if (cerver_start (cpm_api)) {
			cerver_log_error (
				"Failed to start %s!",
				cpm_api->info->name->str
			);

			cerver_delete (cpm_api);
		}
	}

	else {
		cerver_log_error ("Failed to create cerver!");

		cerver_delete (cpm_api);
	}

}

int main (int argc, char const **argv) {

	srand (time (NULL));

	// register to the quit signal
	(void) signal (SIGINT, end);
	(void) signal (SIGTERM, end);

	// to prevent SIGPIPE when writting to socket
	(void) signal (SIGPIPE, SIG_IGN);

	cerver_init ();

	cerver_version_print_full ();

	cpm_version_print_full ();

	if (!cpm_init ()) {
		start ();
	}

	else {
		cerver_log_error ("Failed to init cpm!");
	}

	(void) cpm_end ();

	cerver_end ();

	return 0;

}