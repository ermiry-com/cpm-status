#ifndef _CPM_H_
#define _CPM_H_

#include "runtime.h"

#define DEFAULT_PORT					"5000"

struct _HttpResponse;

extern RuntimeType RUNTIME;

extern unsigned int PORT;

extern unsigned int CERVER_RECEIVE_BUFFER_SIZE;
extern unsigned int CERVER_TH_THREADS;
extern unsigned int CERVER_CONNECTION_QUEUE;

// inits cpm main values
extern unsigned int cpm_init (void);

// ends cpm main values
extern unsigned int cpm_end (void);

#endif