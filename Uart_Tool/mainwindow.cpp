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

#include "QtNetwork"
#include "QMessageBox"

#include "QXmlStreamReader"
#include "QXmlStreamWriter"

#include "qcolordialog.h"

uartClass uartModule;

extern "C" void b_tp_port_uart_send(uint8_t *pbuf, uint32_t len);
extern "C" void uart_cmd_dispatch(uart_cmd_struct_t uart_cmd_struct);

uint16_t battery_mv = 0;
uart_record_t uart_record = {0, 1, 1 , 2, 3};


QMap<QString, QString> m_map;


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
QByteArray face_pp_data;
uint32_t token_count = 0;

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
    show_start_img();
    show_start_img2();
    //ui->label_img->setScaledContents(true);
    manager = new QNetworkAccessManager(this);
    connect(manager,QNetworkAccessManager::finished, this, replyFinished);

    QXmlStreamReader xmlread;
    QFile xml_f;
    QString i_token,i_name;

    xml_f.setFileName("./img/img.xml");
    if(xml_f.open(QFile::ReadOnly))
    {
        xmlread.setDevice(&xml_f);
        while(!xmlread.atEnd())
        {
            QXmlStreamReader::TokenType type = xmlread.readNext();
            if(type == QXmlStreamReader::StartElement)
            {
                if(xmlread.attributes().hasAttribute("token"))
                {
                    i_token = xmlread.attributes().value("token").toString();
                }
            }
            else if(type == QXmlStreamReader::Characters && !xmlread.isWhitespace())
            {
                i_name = xmlread.text().toString();
                m_map.insert(i_token, i_name);
                token_count++;
            }
        }
        xml_f.close();
    }

    xml_f.setFileName("./color.xml");
    if(xml_f.open(QFile::ReadOnly))
    {
        xmlread.setDevice(&xml_f);
        while(!xmlread.atEnd())
        {
            QXmlStreamReader::TokenType type = xmlread.readNext();
            if(type == QXmlStreamReader::Characters && !xmlread.isWhitespace())
            {
                QString color_str = xmlread.text().toString();
                this->setStyleSheet(color_str);
            }
        }
        xml_f.close();
    }


}


void MainWindow::post_search(QByteArray &data)
{
    QUrl url;
    url.setUrl("https://api-cn.faceplusplus.com/facepp/v3/search");
    QNetworkRequest request;
    request.setUrl(url);

    QHttpMultiPart *multpart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    /**KEY*/
    QHttpPart part;
    part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"api_key\""));
    part.setBody("deWn4DAEuE-y9EbZ4Q73FZMioyiQC46g");
    multpart->append(part);

    /**secret*/
    part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"api_secret\""));
    part.setBody("38drPhQ0OjpOgybOVE-81kJn-DeizdFZ");
    multpart->append(part);

    QHttpPart img_part;
    /**image_url1*/
    img_part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"image_file\";filename=\"1\""));
    img_part.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/octet-stream"));
    img_part.setBody(data);
    multpart->append(img_part);

    /**token*/
    part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"faceset_token\""));
    part.setBody("698a44cfe95d476acdf1f3f89c1e8ce7");
    multpart->append(part);

    post_state = 0x01;
    manager->post(request, multpart);
}

void MainWindow::post_detect(QByteArray &data)
{
    QUrl url;
    url.setUrl("https://api-cn.faceplusplus.com/facepp/v3/detect");
    QNetworkRequest request;
    request.setUrl(url);

    QHttpMultiPart *multpart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    /**KEY*/
    QHttpPart part;
    part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"api_key\""));
    part.setBody("deWn4DAEuE-y9EbZ4Q73FZMioyiQC46g");
    multpart->append(part);

    /**secret*/
    part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"api_secret\""));
    part.setBody("38drPhQ0OjpOgybOVE-81kJn-DeizdFZ");
    multpart->append(part);

    QHttpPart img_part;
    /**image_url1*/
    img_part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"image_file\";filename=\"1\""));
    img_part.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/octet-stream"));
    img_part.setBody(data);
    multpart->append(img_part);

    post_state = 0x02;
    manager->post(request, multpart);
}


void MainWindow::post_add(QString &token)
{
    QUrl url;
    url.setUrl("https://api-cn.faceplusplus.com/facepp/v3/faceset/addface");
    QNetworkRequest request;
    request.setUrl(url);

    QHttpMultiPart *multpart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    /**KEY*/
    QHttpPart part;
    part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"api_key\""));
    part.setBody("deWn4DAEuE-y9EbZ4Q73FZMioyiQC46g");
    multpart->append(part);

    /**secret*/
    part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"api_secret\""));
    part.setBody("38drPhQ0OjpOgybOVE-81kJn-DeizdFZ");
    multpart->append(part);

    /**faceset_token*/
    part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"faceset_token\""));
    part.setBody("698a44cfe95d476acdf1f3f89c1e8ce7");
    multpart->append(part);

    /**token*/
    part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"face_tokens\""));
    part.setBody(token.toLatin1());
    multpart->append(part);

    post_state = 0x03;
    manager->post(request, multpart);
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
    QString all = reply->readAll();
    int index = 0;
    QString res;
    char name[64];
    int opt;
    reply->deleteLater();
    if(post_state == 0x1)
    {
        post_state = 0x0;
        index = all.lastIndexOf("face_token");
        if(index >= 0)
        {
            res = all.mid(index + strlen("face_token") + 4, 32);
            if(m_map.contains(res))
            {
                ui->search_result->setText("匹配成功 o(∩_∩)o 哈哈");
                show_img_l(m_map.value(res));
                return;
            }
        }

        ui->search_result->setText("未匹配成功~~~~(>_<)~~~~");
        show_start_img2();
        opt = QMessageBox::information(this, "Hi", "未匹配成功，是否将此图上传至图片库？",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

        if(opt == QMessageBox::Yes)
        {
            post_detect(face_pp_data);
        }
    }
    else if(post_state == 0x2)
    {
        post_state = 0x0;
        index = all.lastIndexOf("face_token");
        if(index >= 0)
        {
            res = all.mid(index + strlen("face_token") + 4, 32);
            token_count++;
            sprintf(name, "sub_%d.jpg", token_count);
            QString new_f = "./img/";
            new_f.append(name);
            QFile add_f;
            add_f.setFileName(new_f);
            add_f.open(QFile::ReadWrite);
            add_f.write(face_pp_data);
            add_f.close();

            QXmlStreamWriter xml_w;
            QMap<QString, QString>::const_iterator i;
            add_f.setFileName("./img/img.xml");
            if(add_f.open(QFile::ReadWrite))
            {
                xml_w.setDevice(&add_f);
                xml_w.setAutoFormatting(true);
                xml_w.writeStartDocument();
                xml_w.writeStartElement("root");

                for(i = m_map.constBegin();i != m_map.constEnd();i++)
                {
                    xml_w.writeStartElement("img");
                    xml_w.writeAttribute("token",i.key());
                    xml_w.writeTextElement("name", i.value());
                    xml_w.writeEndElement();
                }

                xml_w.writeStartElement("img");
                xml_w.writeAttribute("token",res);
                xml_w.writeTextElement("name", name);
                xml_w.writeEndElement();

                xml_w.writeEndElement();
                add_f.close();
            }
            m_map.insert(res, name);
            post_add(res);
        }
    }
    else if(post_state == 0x3)
    {
        post_state = 0x0;
        index = all.lastIndexOf("face_added");
        if(index >= 0)
        {
            res = all.mid(index + strlen("face_added") + 3, 1);
            if(res == '1')
            {
                QMessageBox::information(this, "Hi", "添加成功！", QMessageBox::Ok, QMessageBox::Ok);
            }
        }
    }

}


void MainWindow::show_img_l(QString path)
{
    QString path_l;
    path_l = "./img/";
    path_l.append(path);
    QImageReader reader;
    QImage img;
    reader.setFileName(path_l);
    img = reader.read();
    ui->label_img_2->setPixmap(QPixmap::fromImage(img));
}



void MainWindow::show_start_img()
{
    QString path_l;
    path_l = "./no_img.png";

    QImageReader reader;
    QImage img;
    reader.setFileName(path_l);
    img = reader.read();
    ui->label_img->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::show_start_img2()
{
    QString path_l;
    path_l = "./no_img.png";

    QImageReader reader;
    QImage img;
    reader.setFileName(path_l);
    img = reader.read();
    ui->label_img_2->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::show_img()
{
    char table[64];
    int len;
    QString name;
    QString path_l;
    QFile file_r;
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

    file_r.setFileName(path_l);
    if(file_r.open(QFile::ReadWrite))
    {
        face_pp_data = file_r.readAll();
        file_r.close();
        post_search(face_pp_data);
    }

}




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
        if(w_file)
        {
            memcpy(buf + f_si, buf_tmp, len);
            f_si += len;

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

        }
        else
        {
            if(buf_tmp[0] == 0xff && buf_tmp[1] == 0xd8 && buf_tmp[2] == 0xff && buf_tmp[3] == 0xe0 && buf_tmp[4] == 0x00
                    && buf_tmp[5] == 0x10 && buf_tmp[6] == 0x4a && buf_tmp[7] == 0x46)
            {
                tim = QTime::currentTime();
                s_msec = tim.msecsSinceStartOfDay();
                char timtable[64];
                sprintf(timtable, "%d:%d:%d %d", tim.hour(),tim.minute(),tim.second(),tim.msec());
                ui->textEdit->append(timtable);
                sprintf(name, "/%03d.jpeg",j_count);
                ui->textEdit->append(name);
                QString path_l;
                path_l = path;
                path_l = path_l.append(name);

                file_j.setFileName(path_l);
                file_j.open(QFile::ReadWrite);
                j_count++;
                w_file = true;
                f_si = 0;

                memcpy(buf + f_si, buf_tmp, len);
                f_si += len;

            }
            else
                uart_parse_command(buf_tmp, len);
        }


    }
    else
    {
        tt++;
        if(tt > 50 && w_file)
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
        }
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
    quartTimer->start(10);
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
           //show_len = sprintf(show_table, "%02d-%02d %02d:%02d拆机",uart_record.month, uart_record.day, uart_record.hour, uart_record.minute);
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

void MainWindow::on_color_sel_clicked()
{
    QColorDialog dialog;
    QColor sel_color;
    char color_table[64];
    QXmlStreamWriter xml_write;
    QFile xml_f;
    QString str = "background-color:";
    sel_color = dialog.getColor(Qt::white,this, "color", QColorDialog::ShowAlphaChannel);
    if(sel_color.isValid())
    {
        sprintf(color_table, "rgb(%d,%d,%d);",sel_color.red(), sel_color.green(), sel_color.blue());
        str.append(color_table);
        this->setStyleSheet(str);

        xml_f.setFileName("./color.xml");
        if(xml_f.open(QFile::ReadWrite))
        {
            xml_write.setDevice(&xml_f);

            xml_write.writeStartDocument();
            xml_write.writeStartElement("color");
            xml_write.writeTextElement("color_string", str);
            xml_write.writeEndElement();
            xml_write.writeEndDocument();
            xml_f.close();
        }



    }
}
