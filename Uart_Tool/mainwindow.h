#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class QNetworkReply;
class QNetworkAccessManager;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void textShowString(uint8_t *pbuf, uint32_t len);
    void show_img();
    void show_start_img();
    void show_start_img2();
    void post_search(QByteArray &data);
    void post_detect(QByteArray &data);
    void post_add(QString &token);
    void show_img_l(QString path);
private slots:
    void on_refresh_com_clicked();
    void timer_timeout();
    void on_opencom_clicked();

    void on_Sendfile_clicked();

    void on_clear_clicked();

    void on_pushButton_clicked();

    void on_c_path_clicked();

    void on_readtime_clicked();

    void on_settime_clicked();
    void replyFinished(QNetworkReply *);
private:
    Ui::MainWindow *ui;
    QTimer *quartTimer;
    QNetworkAccessManager *manager;
    uint8_t post_state;
};

#endif // MAINWINDOW_H
