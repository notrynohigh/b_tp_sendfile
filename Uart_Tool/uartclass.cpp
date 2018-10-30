#include "uartclass.h"
#include "b_tp/inc/b_tp.h"
#include <qthread.h>

uartClass::uartClass()
{
    uartOpenStatus = false;

    foreach (const QSerialPortInfo &info , QSerialPortInfo::availablePorts()) {
        QSerialPort SerialPort;
        SerialPort.setPort(info);
        if(SerialPort.open(QIODevice::ReadWrite))
        {
            uartComAvailable.append(SerialPort.portName());
            SerialPort.close();
        }
    }
}


void uartClass::uartRefreshCOM()
{
    uartComAvailable.clear();
    foreach (const QSerialPortInfo &info , QSerialPortInfo::availablePorts()) {
        QSerialPort SerialPort;
        SerialPort.setPort(info);
        if(SerialPort.open(QIODevice::ReadWrite))
        {
            uartComAvailable.append(SerialPort.portName());
            SerialPort.close();
        }
    }
}


bool uartClass::uartOpenPort(const QString portName)
{
    if(uartOpenStatus)
    {
        return false;
    }
    uartPort.setPortName(portName);
    if(uartPort.open(QSerialPort::ReadWrite))
    {
        uartPort.setBaudRate(115200);
        uartOpenStatus = true;
    }
    return uartOpenStatus;
}



void uartClass::uartClosePort()
{
    if(uartOpenStatus)
    {
        uartOpenStatus = false;
        uartPort.close();
    }
}


void uartClass::uartSendBuff(uint8_t *pbuf, uint32_t len)
{
    if(uartOpenStatus)
    {
        uartPort.write((const char *)pbuf, len);
    }
}

void uartClass::uartB_TP_Send(uint8_t *pbuf, uint32_t len)
{
    b_tp_send_data(pbuf, len);
}


uint32_t uartClass::uartReadBuff(uint8_t *pbuf)
{
    QByteArray readbuf;
    if(uartOpenStatus)
    {
        if(pbuf == NULL)
        {
            return 0;
        }
        readbuf = uartPort.readAll();
        if(readbuf.length() > 0)
        {
            memcpy(pbuf, readbuf, readbuf.length());
        }
        return readbuf.length();
    }
}

bool uartClass::uartGetOpenStatus()
{
    return uartOpenStatus;
}
