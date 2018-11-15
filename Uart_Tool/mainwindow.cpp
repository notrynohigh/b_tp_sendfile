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

QFile file_img("img.bin");
QFile file_algo("algo.bin");

uint32_t file_size = 0;

#define STANDBY           0
#define READ_IMG_DATA     1
#define READ_ALGO_DATA    2
#define WAIT_IMG_ACK      3
#define WAIT_ALGO_ACK     4
#define WAIT_STANDBY      5


uint8_t status = STANDBY;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->COMx->addItems(uartModule.uartComAvailable);

    quartTimer = new QTimer(this);
    quartTimer->setSingleShot(true);
    connect(quartTimer, SIGNAL(timeout()), this, SLOT(timer_timeout()));
    quartTimer->start(500);

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

    if(status == READ_IMG_DATA)
    {
        timeout = 0;
        file_img.seek(read_off);
        len = file_img.read((char *)buf, (file_size - read_off >= 4096 ? 4096 : (file_size - read_off)));
        if(len < 0)
        {
            len = 0;
        }
        status = WAIT_IMG_ACK;
        send_img_file(read_off, buf, len);
        sprintf((char *)print_buf, ":%3d\%", read_off * 100 / file_size);
        textShowString(print_buf, 5);
    }
    if(status == READ_ALGO_DATA)
    {
        timeout = 0;
        file_algo.seek(read_off);
        len = file_algo.read((char *)buf, (file_size - read_off >= 4096 ? 4096 : (file_size - read_off)));
        if(len < 0)
        {
            len = 0;
        }
        status = WAIT_ALGO_ACK;
        send_algo_file(read_off, buf, len);
        sprintf((char *)print_buf, ":%3d\%", read_off * 100 / file_size);
        textShowString(print_buf, 5);
    }

    if(status == WAIT_IMG_ACK || status == WAIT_ALGO_ACK)
    {
        timeout++;
        if(timeout > 50)
        {
            status = (status == WAIT_IMG_ACK) ? READ_IMG_DATA : READ_ALGO_DATA;
            timeout = 0;
        }
    }
    if(status == WAIT_STANDBY)
    {
        textShowString((uint8_t *)"-----ok-----", 12);
        status = STANDBY;
        ui->pushButton->setEnabled(true);
        ui->Sendfile->setEnabled(true);
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
        if(pbuf[1] == 0 && status == WAIT_IMG_ACK)
        {
            if(read_off + 4096 <= file_size)
            {
                read_off += 4096;
                status = READ_IMG_DATA;
            }
            else
            {
                file_img.close();
                status = WAIT_STANDBY;
            }
        }
    }
    else if(pbuf[0] == CMD_SEND_ALGO_P)
    {
        if(pbuf[1] == 0 && status == WAIT_ALGO_ACK)
        {
            if(read_off + 4096 <= file_size)
            {
                read_off += 4096;
                status = READ_ALGO_DATA;
            }
            else
            {
                file_algo.close();
                status = WAIT_STANDBY;
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
        ui->Sendfile->setEnabled(true);
        ui->pushButton->setEnabled(true);
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
    if(ui->opencom->text() == "关闭串口")
    {
        ui->Sendfile->setEnabled(false);
        ui->pushButton->setEnabled(false);
        if(!file_img.open(QIODevice::ReadOnly))
        {
            ui->Sendfile->setEnabled(true);
            ui->pushButton->setEnabled(true);
            textShowString((uint8_t *)"failed to open file", 19);
            return;
        }
        file_size = file_img.size();
        textShowString((uint8_t *)"-----start-----", 15);
        read_off = 0;
        status = READ_IMG_DATA;
    }
}

void MainWindow::on_clear_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->opencom->text() == "关闭串口")
    {
        ui->Sendfile->setEnabled(false);
        ui->pushButton->setEnabled(false);
        if(!file_algo.open(QIODevice::ReadOnly))
        {
            ui->Sendfile->setEnabled(true);
            ui->pushButton->setEnabled(true);
            textShowString((uint8_t *)"failed to open file", 19);
            return;
        }
        file_size = file_algo.size();
        textShowString((uint8_t *)"-----start-----", 15);
        read_off = 0;
        status = READ_ALGO_DATA;
    }
}
