#
# File: Makefile
# Project: hexecho
# Author: Andreas Fink (andreas@fink.org)

EXEDIR=/usr/local/bin
CFLAGS=-O2
CC=gcc
EXE=hexecho
CFILES=hexecho.c 
OFILES=hexecho.o 
LIBS= 

${EXE}: ${OFILES}
	${CC} ${CFLAGS} -o ${EXE} ${OFILES} ${LIBS}

install: ${EXE}
	-mkdir -p -m 755 $(DESTDIR)/usr/local/bin
	-install -b -g bin -o root -m 755 ${EXE} $(DESTDIR)${EXEDIR}/${EXE}
	
clean:
	-rm -f *.o *.BAK *~ core ${EXE}

hexecho.o: hexecho.c hexecho.h 
