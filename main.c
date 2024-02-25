#include "dns_reverse.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
	printf ("Please provide the ip4/ip6 address\n");
	return 1;
    }
    if(dns_reverse(argv[1]))
    {
	return 1;
    }
    return 0;
}
