#include "globals.h"

int main(int argc, char *argv[])
{
    globals.src_node  = atoi(argv[1]);
    globals.dest_node = atoi(argv[2]);

    globals.sender_inf = argv[3];

    send_cntp_packet();
    return 0;
}
