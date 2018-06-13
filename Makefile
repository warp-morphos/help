CC=ppc-morphos-gcc
CFLAGS=-noixemul
CATALOGS=français.catalog
FLEXCAT=flexcat

Help: help.c help_cat.c
	$(CC) $(CFLAGS) -o Help help.c help_cat.c

Cat:
	$(FLEXCAT) help.cd français.ct CATALOG catalogs/français.catalog

clean:
	rm -f *.o Help catalogs/*
