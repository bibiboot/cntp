#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/time.h>
#include <pthread.h>

#include "config.h"
#include "color.h"
#include "cprotocol.h"
#include "uthash.h"

#define CUSTOM_HEADER_LEN sizeof(struct custom_packet_header)
#define TIMESTAMP_LEN sizeof(struct timestamp)
#define CNTP_LEN (CUSTOM_HEADER_LEN + TIMESTAMP_LEN)
#define STRATUM0 1
#define STRATUM1 2
#define DRTT_REQ_PORT 1
#define DRTT_RES_PORT 2
#define BROADCAST_ADDR 0xffff

FILE *LOGFILE;

typedef struct hashl {
    int key;
    char value[100];
    UT_hash_handle hh;
} dict_node;

struct globals {
    struct config config;
    dict_node *hashl;
};

typedef uint16_t addr_t;
typedef uint16_t port_t;

struct custom_packet_header{
    addr_t next_hop_addr;
    addr_t dst_addr;
    addr_t src_addr;
    port_t dst_port;
};

struct timestamp{
    uint32_t sec;
    uint32_t fsec;
};

extern struct globals globals;


