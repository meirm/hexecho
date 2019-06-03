/*
** hexecho.c
** Author: Andreas Fink (andreas@fink.org)
** Code in the public domain
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "hextools.h"     

int	main(int argc, char *argv[])
{
	int	i;
	unsigned char	*s;
	unsigned char c;
	unsigned char d;
	int raw = 0;
	
	for(i=1;i<argc;i++)
	{
		s = (unsigned char *)argv[i];
		if(s[0]=='-')
		{
			if(s[1]=='r')
            {
				raw=1;
            }
			if((s[1]=='h') || (s[1]=='?'))
			{
				fprintf(stderr,"hexecho -r 01 02 03: produces raw binary output of hex bytes 01 02 03\n");
				fprintf(stderr,"hexecho 01 02 03: produces human readable binary output of hex bytes like '\\x01\\x02\\x03'\n");
				exit(0);
				
			}
			if(s[1]=='v')
			{
				fprintf(stderr,"hexecho version 1.1. Copyright 2011 Andreas Fink (andreas@fink.org). Source on https://github.com/andreasfink/hexecho.git\n");
				exit(0);
				
			}
			continue;
		}

		while(*s)
		{
			if(isxdigit(*s))
			{
				c = *s++;
				d =  *s++;
				if (d == '\0') {
					fprintf(stderr, "expected a hex pair but only got a single hex number\n");
					abort();
				}
				c = unhex(c,d);
				if(raw)
				{
					putchar(c);
				}
				else
				{
					if(isprint(c))
					{
						putchar(c);
					}
					else
					{
						printf("\\x%02X",c);
					}
				}
			}
			else
				s++;
		}
	}
    if(raw==0)
    {
        printf("\n");
    }
	fflush(stdout);
}

