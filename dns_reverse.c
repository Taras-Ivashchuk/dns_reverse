#include "dns_reverse.h"
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>

int dns_reverse(char* ip)
{
    char hbuf[NI_MAXHOST];
    struct sockaddr_storage addr_st;

    struct sockaddr_in* s_addr = (struct sockaddr_in*)&addr_st;
    s_addr->sin_family = AF_INET;

    if (inet_pton(AF_INET, ip, &(s_addr->sin_addr.s_addr)) < 1)
    {
        struct sockaddr_in6* s_addr6 = (struct sockaddr_in6*)&addr_st;
        s_addr6->sin6_family = AF_INET6;
        if (inet_pton(AF_INET6, ip, &(s_addr6->sin6_addr.s6_addr)) < 1)
        {

            perror("ipv6: inet_ntop\n");
            return 1;
        }
    }

    if (getnameinfo((struct sockaddr*)&addr_st, sizeof(addr_st), hbuf,
                    sizeof(hbuf), NULL, 0, NI_NAMEREQD | NI_NOFQDN))
    {
        perror("getnameinfo: could not resolve hostname\n");
        return 1;
    }

    printf("host=%s\n", hbuf);

    return 0;
}
