#include "send_cntp_packet.h"

void 
send_cntp_packet()
{
    int s;
    void *pkt;
    struct sockaddr_ll sk;
    
    pkt = malloc(CUSTOM_HEADER_SZ + (5 * TIMESTAMP_SZ));
    memset(pkt, 0, DRTT_SZ);
    
    s = create_sending_socket(SENDER_INF, &sk);
    //set_socket_inf(s, SENDER_INF, &sk); //[AB]move "lo" to config
    
    populate_header(STRATUM1, STRATUM1, STRATUM0, CNTP_PORT, &pkt);
    create_timestamp((struct timestamp*)(pkt + CUSTOM_HEADER_SZ));
    create_timestamp((struct timestamp*)(pkt + CUSTOM_HEADER_SZ + TIMESTAMP_SZ));
    create_timestamp((struct timestamp*)(pkt + CUSTOM_HEADER_SZ + (2 * TIMESTAMP_SZ)));
    create_timestamp((struct timestamp*)(pkt + CUSTOM_HEADER_SZ + (3 * TIMESTAMP_SZ)));
    create_timestamp((struct timestamp*)(pkt + CUSTOM_HEADER_SZ + (4 * TIMESTAMP_SZ)));
    
    send_packet(s, &sk, (void *)pkt, CUSTOM_HEADER_SZ + (5 * TIMESTAMP_SZ));
   
    //print_drtt_packet(pkt);
    print_drtt_packet_net(pkt);
    print_timestamp((struct timestamp*)(pkt + CUSTOM_HEADER_SZ));

}
