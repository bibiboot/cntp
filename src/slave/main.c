#include "globals.h"
#include "recv_ts.h"

/*
 * Create two threads
 * 1. Sniffer thread which replies back as welll as
 *    recv reply and calcukates the drtt and stores it
 *    in global variable.
 * 2. IPC thread which stores the drtt at certain
 *    memory location.
 */

int main(int argc, char *argv[])
{
    struct receiver_arg arg;

    arg.dev = SENDER_INF;
    arg.my_addr = STRATUM1;
    start_receiver((void*)&arg);

     /*
     * Deprecated
     * Shifted to raw socket
     */
    //start_receiver((void*)&arg);
    //start_sniffer((void*)&arg);
    return 0;
}
