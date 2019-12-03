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


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    void draw_histo(cv::Mat hist, cv::Mat &hist_img, int channels);
    void calc_histo(const cv::Mat& image, cv::Mat& hist, int channel);
    void histoview(cv::Mat frameOrigin);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_Button_start_clicked();


public:
    cv::VideoCapture video;
    Ui::MainWindow *ui;
    cv::Mat frameOrigin;



private:
    QGraphicsPixmapItem pixmap_R;
    QGraphicsPixmapItem pixmap_G;
    QGraphicsPixmapItem pixmap_B;
    QGraphicsPixmapItem pixmap_DETECT;
    QGraphicsPixmapItem pixmap_Trans;
    QGraphicsPixmapItem pixmap_Video;

};

#endif // MAINWINDOW_H
