#include "recv_ts.h"
void*
start_receiver(void *argument)
{
    struct msghdr msg;
    struct iovec entry;
    struct control control;
    char *payload;
    int payload_len = 1024; //[AB] put in config
    struct sockaddr_in from_addr;
    int ret;
    int s;
    int err_packet;
	int cpkt_pl_len;
	uint64_t offset;
    struct timeval recv_usr;

    struct custom_packet_header* hdr;
    struct timestamp recv_s1_kern;
    struct timestamp s0_ts;
    struct timestamp *from_packet_kern;
    struct receiver_arg* arg;

    arg = (struct receiver_arg*)argument;

    setup_receiver(arg, &s, &payload, payload_len, 
				   &msg, &entry, &control, &from_addr);
   	while(1)
    {
        ret = recv_rawpacket_ts(s, &msg, 0, &err_packet, &recv_s1_kern);
        if (ret < 0){
            printf("Error receiving\n");
            exit(1);
        }
       	print_drtt_packet((void*)payload); 
		gettimeofday(&recv_usr, 0);
        hdr = (struct custom_packet_header*)payload;
		
		if(err_packet){
			printf("Never anticipated an error packet. Exiting.\n");
			exit(1);
		}
		if (IS_SRC_ADDR_MATCH(hdr, arg->my_addr)){
			printf("Own packet\n");
			continue;
		} 
		if (!IS_CNTP(hdr)){
			printf("Not CNTP packet\n");
			continue;
		}
		if (!IS_DST_ADDR_MATCH(hdr, arg->my_addr)){
			//Not destined to me
			printf("Not destined to me\n");
			continue;
		}
		
		offset = cal_offset(payload, ret, recv_s1_kern);
		
   }
}

