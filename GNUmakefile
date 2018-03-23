PROG= httpd
SRCS= parse.y
SRCS+= config.c control.c httpd.c log.c logger.c proc.c
SRCS+= server.c server_http.c server_file.c server_fcgi.c
MAN= httpd.8 httpd.conf.5

SRCS+= patterns.c
MAN+= patterns.7

SRCS+= openbsd-compat/vis.c openbsd-compat/imsg.c openbsd-compat/imsg-buffer.c openbsd-compat/crypt_checkpass.c openbsd-compat/openbsd_compat.c

CFLAGS+= -D_GNU_SOURCE -DLIBBSD_OVERLAY
CFLAGS+= -Iopenbsd-compat -I/usr/include/bsd
CFLAGS+= $(EXTRA_CFLAGS)

LDLIBS= -levent -ltls -lssl -lcrypto -lutil -lresolv -lbsd -lcrypt

OBJS= $(addsuffix .o,$(basename $(SRCS)))

httpd: $(OBJS)

clean:
	rm -f *.o openbsd-compat/*.o
