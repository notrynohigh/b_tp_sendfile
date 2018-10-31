#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "uartclass.h"
#include <QFileInfo>
#include <qthread.h>
#include <qtimer.h>
#include "./protocol/proto.h"
#include "./b_tp/inc/b_tp.h"
uartClass uartModule;

extern "C" void b_tp_port_uart_send(uint8_t *pbuf, uint32_t len);
extern "C" void b_tp_callback(uint8_t *pbuf, uint32_t len);

void b_tp_callback(uint8_t *pbuf, uint32_t len);

void MainWindow::textShowString(uint8_t *pbuf, uint32_t len)
{
    ui->textEdit->append(QString::fromLocal8Bit((const char *)pbuf, len));
}

QFile file("algo.bin");
uint32_t file_size = 0;
bool read_flag = false;
bool finished = false;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->COMx->addItems(uartModule.uartComAvailable);

    if(! file.open(QIODevice::ReadOnly))
    {
        textShowString((uint8_t *)"failed to open file", 19);
    }
    else
    {
        file_size = file.size();
        quartTimer = new QTimer(this);
        quartTimer->setSingleShot(true);
        connect(quartTimer, SIGNAL(timeout()), this, SLOT(timer_timeout()));
        quartTimer->start(500);
    }

    b_tp_reg_callback(b_tp_callback);


}

uint8_t buf[4096];
uint32_t read_off = 0;
uint32_t timeout = 0;
void MainWindow::timer_timeout()
{
    int32_t len = 0;
    uint8_t tmp_buf[1024];
    uint8_t print_buf[16];
    len = uartModule.uartReadBuff(tmp_buf);
    if(len > 0)
    {
        b_tp_receive_data(tmp_buf, len);
    }

    if(read_flag)
    {
        timeout = 0;
        file.seek(read_off);
        len = file.read((char *)buf, (file_size - read_off >= 4096 ? 4096 : (file_size - read_off)));
        if(len < 0)
        {
            len = 0;
        }
        read_flag = false;
        send_file(read_off * 4096, buf, len);
        sprintf((char *)print_buf, ":%3d%", read_off * 100 / file_size);
        textShowString(print_buf, 5);
    }
    else if(read_off != 0)
    {
        timeout++;
        if(timeout > 50)
        {
            if(read_off + 4096 <= file_size)
            {
                read_flag = true;
            }
            timeout = 0;
        }
    }
    if(finished)
    {
        finished = false;
        textShowString((uint8_t *)"-----ok-----", 12);
    }
    quartTimer->start(100);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void b_tp_port_uart_send(uint8_t *pbuf, uint32_t len)
{
    uartModule.uartSendBuff(pbuf, len);
    QThread::msleep(100);
}


void b_tp_callback(uint8_t *pbuf, uint32_t len)
{
    if(pbuf[0] == CMD_SEND_FILE)
    {
        if(pbuf[1] == 0)
        {
            if(read_off + 4096 <= file_size)
            {
                read_off += 4096;
                read_flag = true;
            }
            else
            {
                finished = true;
            }
        }

    }
}


void MainWindow::on_refresh_com_clicked()
{
    ui->COMx->clear();
    uartModule.uartRefreshCOM();
    ui->COMx->addItems(uartModule.uartComAvailable);
}

void MainWindow::on_opencom_clicked()
{
    if(uartModule.uartGetOpenStatus())
    {
        uartModule.uartClosePort();
        ui->COMx->setEnabled(true);
        ui->opencom->setText("打开串口");
    }
    else
    {
        if(uartModule.uartOpenPort(ui->COMx->currentText()))
        {
            ui->COMx->setEnabled(false);
            ui->opencom->setText("关闭串口");
        }
    }
}

void MainWindow::on_Sendfile_clicked()
{
    read_off = 0;
    if(ui->opencom->text() == "关闭串口")
    {
        textShowString((uint8_t *)"-----start-----", 15);
        read_flag = true;
    }
}

void MainWindow::on_clear_clicked()
{
    ui->textEdit->clear();
}
