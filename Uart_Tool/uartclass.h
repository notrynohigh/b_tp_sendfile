#ifndef UARTCLASS_H
#define UARTCLASS_H

#include <QtSerialPort/qserialportinfo.h>
#include <QtSerialPort/qserialport.h>
#include <qtimer.h>


class uartClass
{
public:
    QStringList uartComAvailable;

    uartClass();

    void uartRefreshCOM();
    void uartB_TP_Send(uint8_t *pbuf, uint32_t len);
    bool uartOpenPort(const QString portName);
    void uartClosePort();
    void uartSendBuff(uint8_t *pbuf, uint32_t len);
    uint32_t uartReadBuff(uint8_t *pbuf);
    bool uartGetOpenStatus();
private:
    bool uartOpenStatus = false;
    QSerialPort uartPort;
    QSerialPortInfo uartPortInfo;

};

#endif // UARTCLASS_H
