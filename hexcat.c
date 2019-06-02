/*
** hexcat.c
** Author: Andreas Fink (andreas@fink.org)
** Code in the public domain
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

     
unsigned char	unhex(unsigned char hex1, unsigned char hex2);
int	unnibble(unsigned char x);
int cat_fd(int ifd);
int raw = 0;

int	main(int argc, char *argv[])
{
	int	i;
	unsigned char	*s;
	int rfstdin = 1;
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
				fprintf(stderr,"hexcat -r : produces raw binary output of hex bytes 01 02 03\n");
				fprintf(stderr,"hexcat : produces human readable binary output of hex bytes like '\\x01\\x02\\x03'\n");
				exit(0);
				
			}
			if(s[1]=='v')
			{
				fprintf(stderr,"hexcat version 1.1. Copyright 2011 Andreas Fink (andreas@fink.org). Source on https://github.com/andreasfink/hexcat.git\n");
				exit(0);
				
			}
			continue;
		}else{
			rfstdin = 0;
			int fp= open(argv[i],O_RDONLY, 0);
			if (cat_fd(fp) != 0)
		        	fprintf(stderr, "failed to copy standard input\n");
			close(fp);
		}


	}
	if (rfstdin == 1){
		if (cat_fd(0) != 0)
		        fprintf(stderr, "failed to copy standard input\n");
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

int cat_fd(int ifd)
{
    unsigned char c;
    unsigned char d;
    char buffer[4096];
    ssize_t nbytes;
    while ((nbytes = read(ifd, buffer, sizeof(buffer))) > 0)
    for(int i=0; i < nbytes; i+=2){
	if(isxdigit(buffer[i]))
			{
				c = buffer[i];
				d = buffer[i+1];
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
		}
    return (nbytes < 0) ? -1 : 0;
}
