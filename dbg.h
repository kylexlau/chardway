#ifndef ___dbg_h__
#define ___dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

/* ##_VA_ARGS__ : means put whatever they had for extra arguments
     (...) here */

/* __FILE__ and __LINE__ : get the current file:line for the debug
   message. */

#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

/* check will make sure the condition A is true, and if not logs the
   error M (with variable arguments for log_err), then jumps to the
   function's error: for cleanup. */
#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error;}

/* sentinel : placed in any part of a function that shouldn't run, and
   if it does prints an error message then jumps to the error */
#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define check_mem(A) check((A), "Out of Memory.")

#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }

#endif
