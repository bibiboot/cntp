#include "send_cntp_packet.h"

void
send_cntp_packet()
{
    int s;
    void *pkt;
    struct sockaddr_ll sk;

    pkt = malloc(CNTP_LEN);
    memset(pkt, 0, CNTP_LEN);

    s = create_sending_socket(SENDER_INF, &sk);
    //set_socket_inf(s, SENDER_INF, &sk); //[AB]move "lo" to config

    populate_header(BROADCAST_ADDR, BROADCAST_ADDR, STRATUM0, DRTT_REQ_PORT, &pkt);
    create_timestamp((struct timestamp*)(pkt + CUSTOM_HEADER_LEN));

    //create_timestamp((struct timestamp*)(pkt + CUSTOM_HEADER_LEN + TIMESTAMP_LEN));

    send_packet(s, &sk, (void *)pkt, CNTP_LEN);

    print_cntp_packet(pkt);

    print_timestamp((struct timestamp*)(pkt + CUSTOM_HEADER_LEN));
}
