#include "./b_tp/inc/b_tp.h"
#include "proto.h"


void tc_send(uint8_t cmd, uint8_t status, uint8_t *pbuf, uint32_t len)
{
    uint8_t tmp_buf[4096 + (32)];
    tcmd_struct_t *pstruct = (tcmd_struct_t *)tmp_buf;
    if(pbuf == NULL && len > 0)
    {
        return;
    }
    pstruct->cmd = cmd;
    pstruct->status = status;
    memcpy(pstruct->buf, pbuf, len);
    b_tp_send_data(tmp_buf, len + 2);
}


void send_img_file(uint32_t address, uint8_t table[], uint32_t len)
{
    send_file_t send_file_s;
    send_file_s.address = address;
    send_file_s.len = len;
    memcpy(send_file_s.buf, table, len);
    if(len < 4096)
        tc_send(CMD_SEND_FILE, 4, &send_file_s, sizeof(send_file_t));
    tc_send(CMD_SEND_FILE, 0, &send_file_s, sizeof(send_file_t));
}

void send_algo_file(uint32_t address, uint8_t table[], uint32_t len)
{
    send_file_t send_file_s;
    send_file_s.address = address;
    send_file_s.len = len;
    memcpy(send_file_s.buf, table, len);
    if(len < 4096)
        tc_send(CMD_SEND_ALGO_P, 4, &send_file_s, sizeof(send_file_t));
    tc_send(CMD_SEND_ALGO_P, 0, &send_file_s, sizeof(send_file_t));
}



