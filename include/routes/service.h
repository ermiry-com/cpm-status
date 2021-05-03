#ifndef _CPM_ROUTES_SERVICE_H_
#define _CPM_ROUTES_SERVICE_H_

struct _HttpReceive;
struct _HttpRequest;

// GET /api/cpm
extern void cpm_handler (
	const struct _HttpReceive *http_receive,
	const struct _HttpRequest *request
);

// GET /api/cpm/version
extern void cpm_version_handler (
	const struct _HttpReceive *http_receive,
	const struct _HttpRequest *request
);

// GET *
extern void cpm_catch_all_handler (
	const struct _HttpReceive *http_receive,
	const struct _HttpRequest *request
);

#endif