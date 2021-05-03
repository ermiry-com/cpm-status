#include <cerver/http/http.h>
#include <cerver/http/request.h>
#include <cerver/http/response.h>

#include "controllers/service.h"

// GET /api/cpm
void cpm_handler (
	const HttpReceive *http_receive,
	const HttpRequest *request
) {

	(void) http_response_send (cpm_works, http_receive);

}

// GET /api/cpm/version
void cpm_version_handler (
	const HttpReceive *http_receive,
	const HttpRequest *request
) {

	(void) http_response_send (current_version, http_receive);

}

// GET *
void cpm_catch_all_handler (
	const HttpReceive *http_receive,
	const HttpRequest *request
) {

	http_response_send (catch_all, http_receive);

}
