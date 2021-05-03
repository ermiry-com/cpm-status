#ifndef _CPM_SERVICE_H_
#define _CPM_SERVICE_H_

struct _HttpResponse;

extern struct _HttpResponse *cpm_works;
extern struct _HttpResponse *current_version;

extern struct _HttpResponse *catch_all;

extern unsigned int cpm_service_init (void);

extern void cpm_service_end (void);

#endif