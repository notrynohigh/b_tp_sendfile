#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "uartclass.h"
#include <QFileInfo>
#include <qthread.h>
#include <qtimer.h>
#include "./protocol/proto.h"
#include "./b_tp/inc/b_tp.h"
#include <QDir>
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

uint8_t buf[1024 * 10];
uint32_t f_si = 0;
uint8_t buf_tmp[1024 * 10];
uint32_t j_count = 0;
char name[64];
bool w_file = false;
QFile file_j;
FILE *pf;
uint32_t tt = 0;
QDir dird;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->COMx->addItems(uartModule.uartComAvailable);

    quartTimer = new QTimer(this);
    quartTimer->setSingleShot(true);
    connect(quartTimer, SIGNAL(timeout()), this, SLOT(timer_timeout()));
    quartTimer->start(100);
    std::string pach("C:\\JPEG\\");
    QString path = QString::fromStdString(pach);

    if(!dird.exists(path))
    {
       if(!dird.mkdir(path))
       {

       }
    }

}


void MainWindow::timer_timeout()
{
    int32_t len = 0;
    len = uartModule.uartReadBuff(buf_tmp);
    if(len > 0)
    {
        tt = 0;
        if(buf_tmp[0] == 0xff && buf_tmp[1] == 0xd8 && buf_tmp[2] == 0xff && buf_tmp[3] == 0xe0 && buf_tmp[4] == 0x00
                && buf_tmp[5] == 0x10 && buf_tmp[6] == 0x4a && buf_tmp[7] == 0x46)
        {
            if(w_file)
            {
                file_j.write((const char *)buf, f_si);
                file_j.close();
                w_file = false;
                f_si = 0;
                ui->textEdit->append("jpeg ok");
            }
            if(!w_file)
            {
                sprintf(name, "C:\\JPEG\\%03d.jpeg", j_count);
                ui->textEdit->append(name);
                pf = fopen(name, "wb");
                j_count++;
                w_file = true;
                file_j.open(pf, QFile::ReadWrite);

            }
        }
        memcpy(buf + f_si, buf_tmp, len);
        f_si += len;
    }
    else
    {
        tt++;
        if((w_file && tt > 3000) || (w_file && buf[f_si - 1] == 0xd9 && buf[f_si - 2] == 0xff))
        {
            file_j.write((const char *)buf, f_si);
            file_j.close();
            w_file = false;
            f_si = 0;
            ui->textEdit->append("jpeg ...");
        }
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

}

void MainWindow::on_clear_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_pushButton_clicked()
{
    if(w_file)
    {
        file_j.write((const char *)buf, f_si);
        file_j.close();
        w_file = false;
        f_si = 0;
        ui->textEdit->append("jpeg ..");
    }
}
