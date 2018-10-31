#ifndef __PROTO_H__
#define __PROTO_H__

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CMD_SEND_FILE    0X1

#pragma pack(1)


typedef struct
{
    uint8_t cmd;
    uint8_t status;
    uint8_t buf[1];
}tcmd_struct_t;

typedef struct
{
    uint8_t cmd;
    uint8_t status;
    uint8_t *pbuf;
}tcmd_pstruct_t;


typedef struct
{
    uint32_t address;
    uint32_t len;
    uint8_t buf[4096];
}send_file_t;






#pragma pack()



void send_file(uint32_t address, uint8_t table[], uint32_t);

#ifdef __cplusplus
}
#endif

#endif



