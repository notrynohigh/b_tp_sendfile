#include "./b_tp/inc/b_tp.h"
#include "proto.h"




extern void b_tp_port_uart_send(uint8_t *pbuf, uint32_t len);









void uart_parse_command(uint8_t *pbuf, uint32_t len)
{
    _uart_protocol_t *puart_protocol_struct = (_uart_protocol_t *)pbuf;
    uart_cmd_struct_t uart_cmd_struct;
    uint8_t sum = 0;
    if(pbuf[0] != UART_HEAD || pbuf == NULL || len < 5)
    {
        return;
    }
    if(puart_protocol_struct->len + 3 > len)
    {
        return;
    }

    sum = sum_8bit(pbuf, puart_protocol_struct->len + 2);

    if(sum != pbuf[puart_protocol_struct->len + 2])
    {
        //return;
    }
    uart_cmd_struct.cmd = puart_protocol_struct->buf[0];
    uart_cmd_struct.status = puart_protocol_struct->buf[1];
    if(puart_protocol_struct->len == 2)
    {
        uart_cmd_struct.pbuf = NULL;
    }
    else
    {
        uart_cmd_struct.pbuf = &(puart_protocol_struct->buf[2]);
    }
    uart_cmd_dispatch(uart_cmd_struct);

}




/**
 * \brief 按照格式发送数据
 * \param 指令(cmd)
 * \param 状态(status)
 * \param 参数(pbuf)
 * \param 参数长度(len)
 */
static void uart_protocol_send(uint8_t cmd, uint8_t status, uint8_t *pbuf, uint8_t len)
{
    uint8_t tmp_buf[64];
    _uart_protocol_t *p_uart_protocol = (_uart_protocol_t *)tmp_buf;
    _uart_cmd_struct_t *p_uart_cmd_struct;
    p_uart_protocol->head = UART_HEAD;
    p_uart_protocol->len = len + 2;
    p_uart_cmd_struct = (_uart_cmd_struct_t *)(p_uart_protocol->buf);
    p_uart_cmd_struct->cmd = cmd;
    p_uart_cmd_struct->status = status;
    memcpy(p_uart_cmd_struct->buf, pbuf, len);
    p_uart_cmd_struct->buf[len] = sum_8bit(tmp_buf, len + 2 + 2);
    b_tp_port_uart_send(tmp_buf, len + 2 + 3);
}




void protocol_read_time()
{
    uart_protocol_send(UART_CMD_GET_TIME, 0, NULL, 0);
}


void protocol_set_time(int year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t second)
{
    uart_time_struct_t uart_time_struct;
    uart_time_struct.year = year - 2000;
    uart_time_struct.month = month;
    uart_time_struct.day = day;
    uart_time_struct.hour = hour;
    uart_time_struct.minute = min;
    uart_time_struct.second = second;
    uart_protocol_send(UART_CMD_SET_TIME, 0, (uint8_t *)&uart_time_struct, sizeof(uart_time_struct_t));
}




