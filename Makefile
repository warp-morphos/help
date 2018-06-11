CC=ppc-morphos-gcc
CFLAGS=-noixemul

Help: help.c help_cat.c
	$(CC) $(CFLAGS) -o Help help.c help_cat.c
