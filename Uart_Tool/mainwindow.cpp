#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "uartclass.h"
#include <QFileInfo>
#include <qthread.h>
#include <qtimer.h>
#include "./protocol/proto.h"
#include "./b_tp/inc/b_tp.h"
#include <QDir>
#include <QTime>
#include "qfiledialog.h"
#include "qdebug.h"
#include "qimagereader.h"
#include "qpixmap.h"


uartClass uartModule;

extern "C" void b_tp_port_uart_send(uint8_t *pbuf, uint32_t len);
extern "C" void uart_cmd_dispatch(uart_cmd_struct_t uart_cmd_struct);

uint16_t battery_mv = 0;
uart_record_t uart_record = {0, 1, 1 , 2, 3};



void b_tp_callback(uint8_t *pbuf, uint32_t len);

void MainWindow::textShowString(uint8_t *pbuf, uint32_t len)
{
    ui->textEdit->append(QString::fromLocal8Bit((const char *)pbuf, len));
}



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
QTime tim;
QStringList fl;
QString path;
QFile txt_f;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    char ptable[64];
    int plen = 0;
    ui->setupUi(this);
    ui->COMx->addItems(uartModule.uartComAvailable);

    quartTimer = new QTimer(this);
    quartTimer->setSingleShot(true);
    connect(quartTimer, SIGNAL(timeout()), this, SLOT(timer_timeout()));
    quartTimer->start(100);


    txt_f.setFileName("./path.txt");
    txt_f.open(QFile::ReadWrite);
    plen = txt_f.readLine(ptable, 64);

    if(plen <= 0)
    {
        txt_f.write("C:/JPEG\r\n");
        memcpy(ptable, "C:/JPEG\r\n", 9);
        plen = 9;
    }
    txt_f.close();

    ptable[plen - 2] = 0x0;
    ui->label_path->setText(ptable);
    path = QString::fromStdString(ptable);

    if(!dird.exists(path))
    {
       if(!dird.mkdir(path))
       {

       }
    }
    dird.setPath(path);
    fl = dird.entryList(QDir::Files);
    j_count = fl.size();
    show_img();
}

void MainWindow::show_img()
{
    char table[64];
    int len;
    QString name;
    QString path_l;
    if(j_count > 0)
    {
        len = sprintf(table, "/%03d.jpeg",j_count - 1);
        name = QString::fromStdString(table);
        path_l = path;
        path_l = path_l.append(name);
    }
    else
    {
        path_l = "./no_img.png";
    }

    QImageReader reader;
    QImage img;

    reader.setFileName(path_l);
    img = reader.read();
    ui->label_img->setPixmap(QPixmap::fromImage(img));
}



uint32_t w_index = 0xfffff;
uint32_t s_msec = 0;
char show_table[1024];
int show_len = 0;
void MainWindow::timer_timeout()
{
    int32_t len = 0;
    uint32_t i = 0;

    char stable[16];
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

                tim = QTime::currentTime();
                s_msec = tim.msecsSinceStartOfDay() - s_msec;
                ui->textEdit->append("jpeg ok");
                sprintf(stable, ":%dms\r\n", s_msec);
                ui->textEdit->append(stable);
                show_img();
            }
            if(!w_file)
            {
                tim = QTime::currentTime();
                s_msec = tim.msecsSinceStartOfDay();

                sprintf(name, "/%03d.jpeg",j_count);
                ui->textEdit->append(name);
                QString path_l;
                path_l = path;
                path_l = path_l.append(name);

                file_j.setFileName(path_l);
                file_j.open(QFile::ReadWrite);
                j_count++;
                w_file = true;
            }
        }
        if(w_file)
        {
            memcpy(buf + f_si, buf_tmp, len);
            if(w_index == 0xfffff)
                w_index = f_si;
            f_si += len;
        }
        else
        {
            uart_parse_command(buf_tmp, len);
        }
    }
    else
    {
        tt++;

        if(w_file)
        {

            if(tt > 3000)
            {
                file_j.write((const char *)buf, f_si);
                file_j.close();
                w_file = false;
                f_si = 0;
                tim = QTime::currentTime();
                s_msec = tim.msecsSinceStartOfDay() - s_msec;
                ui->textEdit->append("timeout");
                sprintf(stable, ":%dms\r\n", s_msec);
                ui->textEdit->append(stable);
                show_img();
            }
            else
            {
                for(i = 0;(i < f_si && i < 55);i++)
                {
                    if(buf[f_si - 1 - i] == 0xd9)
                    {
                        if(buf[f_si - 1 - i - 1] == 0xff)
                        {
                            f_si -= i;
                            file_j.write((const char *)buf, f_si);
                            file_j.close();
                            w_file = false;
                            f_si = 0;
                            tim = QTime::currentTime();
                            s_msec = tim.msecsSinceStartOfDay() - s_msec;
                            ui->textEdit->append("jpeg ok");
                            sprintf(stable, ":%dms\r\n", s_msec);
                            ui->textEdit->append(stable);
                            show_img();
                        }
                    }
                }

                if(w_file && tt > 50 && w_index != 0xfffff)
                {
                    f_si = w_index;
                    w_index = 0xfffff;
                }
            }
        }
        else
            tt = 0;
    }
    if(show_len > 0)
    {
        ui->textEdit->append(show_table);
        show_len = 0;
    }
    char rtable[64];
    if(battery_mv > 0)
    {
        sprintf(rtable, "电量：%4dmv",battery_mv);
        ui->battery->setText(rtable);
        battery_mv = 0;
    }

    if(uart_record.flag == 1)
    {
        sprintf(rtable, "%02d-%02d %02d:%02d拆机",uart_record.month, uart_record.day, uart_record.hour, uart_record.minute);
        ui->record->setText(rtable);
        uart_record.flag = 2;
    }
    else if(uart_record.flag == 0)
    {
        if(ui->record->text() != "无拆机记录")
        {
            ui->record->setText("无拆机记录");
        }
        uart_record.flag = 2;
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





void uart_cmd_dispatch(uart_cmd_struct_t uart_cmd_struct)
{
    uart_time_struct_t *puart_time_struct = (uart_time_struct_t *)uart_cmd_struct.pbuf;
    uart_battery_mv_t *puart_battery_mv = (uart_battery_mv_t *)uart_cmd_struct.pbuf;
    uart_record_t *puart_record = (uart_record_t *)uart_cmd_struct.pbuf;
    switch(uart_cmd_struct.cmd)
    {
        case UART_CMD_GET_TIME:
        show_len = sprintf(show_table, "%02d-%02d-%02d %02d:%02d:%02d", puart_time_struct->year, puart_time_struct->month, puart_time_struct->day, puart_time_struct->hour,
                puart_time_struct->minute, puart_time_struct->second);
            break;
        case UART_CMD_BATTERY:
            battery_mv = puart_battery_mv->mv;
            break;
        case UART_CMD_BREAK:
            memcpy(&uart_record, puart_record, sizeof(uart_record_t));
            break;
        default:
        break;
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

void MainWindow::on_c_path_clicked()
{
    QFileDialog dialog;
    QString name;
    name = dialog.getExistingDirectory(this, "jpeg dir");
    if(name != "" && name != path)
    {
        ui->label_path->setText(name);
        path = name;
        name.append("\r\n");
        txt_f.open(QFile::ReadWrite);
        txt_f.seek(0);
        txt_f.write(name.toLocal8Bit());
        txt_f.close();
        dird.setPath(path);
        fl = dird.entryList(QDir::Files);
        j_count = fl.size();
        show_img();
    }
}

void MainWindow::on_readtime_clicked()
{
    protocol_read_time();
}

void MainWindow::on_settime_clicked()
{
    QTime tim_c;
    QDate date_c;
    date_c = QDate::currentDate();
    tim_c = QTime::currentTime();
    protocol_set_time(date_c.year(), date_c.month(), date_c.day()
                      ,tim_c.hour(), tim_c.minute(), tim_c.second());
}
