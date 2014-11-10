#include "utils.h"

void
print_header(void *packet)
{
    struct custom_packet_header* pkt;
    pkt = (struct custom_packet_header*)packet;
    printf("| %u | %u | %u | %u |",
            pkt->next_hop_addr, pkt->dst_addr,
            pkt->src_addr, pkt->dst_port);
}

void
print_ts(uint32_t *ts)
{
    printf(" %u | %u |\n",*ts, *(ts+1));
}

void
print_cntp_packet(void *packet)
{
    printf("+++++++++++++++++++++++++++++++++++++++++++++++\n");
    print_header(packet);
    print_ts(packet + CUSTOM_HEADER_LEN);
    printf("+++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void
print_header_net(void *packet)
{
    struct custom_packet_header* pkt;
    pkt = (struct custom_packet_header*)packet;
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+\t0x%04x\t+\t0x%04x\t+\t0x%04x\t+\t0x%04x\t+\n",
            htons(pkt->next_hop_addr), htons(pkt->dst_addr),
            htons(pkt->src_addr), htons(pkt->dst_port) );
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void
print_ts_net(uint32_t *ts)
{
    printf("+\t0x%08x\t+\t0x%08x\n",htonl(*ts), htonl(*(ts+1)) );
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void
print_cntp_packet_net(void *packet)
{
    print_header_net(packet);
    print_ts_net(packet + CUSTOM_HEADER_LEN);
}

void
print_timestamp(struct timestamp* ts)
{
    printf("sec:%u\tfsec:%u\n", ts->sec, ts->fsec);
}