#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
private slots:
    void on_refresh_com_clicked();
    void timer_timeout();
    void on_opencom_clicked();

    void on_Sendfile_clicked();

    void on_clear_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *quartTimer;
};

#endif // MAINWINDOW_H
