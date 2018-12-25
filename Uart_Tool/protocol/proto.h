#ifndef __PROTO_H__
#define __PROTO_H__

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DMA_BUF_SIZE       64
#define UART_HEAD          0XA5


#define UART_CMD_SET_TIME      0X55
#define UART_CMD_GET_TIME      0X56
#define UART_CMD_BATTERY       0X57
#define UART_CMD_BREAK         0X58

#pragma pack(1)


typedef struct
{
    uint8_t head;
    uint8_t len;
    uint8_t *pbuf;
    uint8_t check;
}uart_protocol_t;


typedef struct
{
    uint8_t head;
    uint8_t len;
    uint8_t buf[1];
}_uart_protocol_t;

typedef struct
{
    uint8_t cmd;
    uint8_t status;
    uint8_t *pbuf;
}uart_cmd_struct_t;


typedef struct
{
    uint8_t cmd;
    uint8_t status;
    uint8_t buf[1];
}_uart_cmd_struct_t;


typedef struct
{
    uint8_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
}uart_time_struct_t;



typedef struct
{
    uint16_t mv;
}uart_battery_mv_t;

typedef struct
{
    uint8_t flag;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
}uart_record_t;


#pragma pack()

void uart_parse_command(uint8_t *pbuf, uint32_t len);
void protocol_set_time(int year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t second);
void protocol_read_time(void);

#ifdef __cplusplus
}
#endif

#endif



