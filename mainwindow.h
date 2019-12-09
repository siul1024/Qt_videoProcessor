#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPixmap>
#include <QCloseEvent>
#include <QMessageBox>
#include "opencv2/opencv.hpp"
#include "mygpio.h"
#include "mythread.h"
#include <thread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_Button_start_clicked();
    void on_Button_rec_clicked();
    void on_Button_rec_stop_clicked();
    void on_Button_capture_clicked();
    void on_Button_FACE_clicked();
    void on_Button_CAR_clicked();
    void on_Button_O_clicked();

public:
    cv::VideoCapture video;
    Ui::MainWindow *ui;
    cv::Mat frameOrigin;
    cv::Size size = cv::Size(320, 240);

    QGraphicsPixmapItem pixmap_R;
    QGraphicsPixmapItem pixmap_G;
    QGraphicsPixmapItem pixmap_B;

private:

    myGPIO *MYGPIO;
    BlinkThread *bth;
    QGraphicsPixmapItem pixmap; //REC
    QGraphicsPixmapItem pixmap_DETECT;
    QGraphicsPixmapItem pixmap_Trans;
    QGraphicsPixmapItem pixmap_Video;
};

#endif // MAINWINDOW_H
