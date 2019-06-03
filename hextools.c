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

unsigned char unhex(unsigned char hex1, unsigned char hex2)
{
    return ( unnibble(hex1)*16+unnibble(hex2) );
}

