#ifndef COMPAT_H_
#define COMPAT_H_

#define __dead __attribute__((noreturn))
#define pledge(pr, pa) (0)
#define getdtablecount() (0)
//#define setproctitle(p, t) (0)

#define DEF_WEAK(x)

int crypt_checkpass(const char *, const char *);


#include <stddef.h>
#include <stdlib.h>
#include <string.h>
static inline void freezero(void *ptr, size_t size)
{
  if (ptr != NULL) {
    memset(ptr, 0, size);
  }
  free(ptr);
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
static inline socklen_t ss_len(struct sockaddr_storage *ss)
{
  switch (ss->ss_family) {
    case AF_INET:
      return sizeof(struct sockaddr_in);
    case AF_INET6:
      return sizeof(struct sockaddr_in6);
    default:
      fprintf(stderr, "ss_len: unsupported address family (%x)\n",
          ss->ss_family);
      abort();
  }
}

#endif
