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
	-cp ${EXE} ${EXEDIR}
	
clean:
	-rm -f *.o *.BAK *~ core ${EXE}

hexecho.o: hexecho.c hexecho.h 
