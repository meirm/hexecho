#
# File: Makefile
# Project: hexecho
# Author: Andreas Fink (andreas@fink.org)

EXEDIR=/usr/local/bin
CFLAGS=-O2
CC=gcc
EXE1=hexecho
EXE2=hexcat
CFILES2=hexcat.c 
OFILES2=hexcat.o
CFILES1=hexecho.c
OFILES1=hexecho.o
LIBS= 

all: ${EXE1} ${EXE2}

${EXE1}: ${OFILES1}
	${CC} ${CFLAGS} -o ${EXE1} ${OFILES1} ${LIBS}

${EXE2}: ${OFILES2}
	${CC} ${CFLAGS} -o ${EXE2} ${OFILES2} ${LIBS}

install: ${EXE1} ${EXE2}
	-mkdir -p -m 755 $(DESTDIR)/usr/local/bin
	-install -b -g bin -o root -m 755 ${EXE1} $(DESTDIR)${EXEDIR}/${EXE1}
	-install -b -g bin -o root -m 755 ${EXE2} $(DESTDIR)${EXEDIR}/${EXE2}
	
clean:
	-rm -f *.o *.BAK *~ core ${EXE}

hexecho.o: hexecho.c hexecho.h 

hexcat.o: hexcat.c hexcat.h 
