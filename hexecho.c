/*
** hexecho.c
** Author: Andreas Fink (andreas@fink.org)
** Code in the public domain
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
     
unsigned char	unhex(unsigned char hex1, unsigned char hex2);
int	unnibble(unsigned char x);

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


unsigned char	unhex(unsigned char hex1, unsigned char hex2)
{
    return ( unnibble(hex1)*16+unnibble(hex2) );
}

int	unnibble(unsigned char x)
{
    if((x>='0') && (x<='9'))
    {
		return (x-'0');
    }
    else if((x>='a') && (x<='f'))
    {
		return (x-'a'+10);
    }
    else if((x>='A') && (x<='F'))
    {
		return(x-'A'+10);
	}
    return -1;
}
