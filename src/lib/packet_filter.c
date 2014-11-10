#include "packet_filter.h"

bool
is_drtt_request(void* packet)
{
    addr_t *ptr;
    ptr = (addr_t*)packet;
    return (DRTT_REQ_PORT == *(ptr+3));
}
