#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView_R->setScene(new QGraphicsScene(this));
    ui->graphicsView_R->scene()->addItem(&pixmap_R);
    ui->graphicsView_G->setScene(new QGraphicsScene(this));
    ui->graphicsView_G->scene()->addItem(&pixmap_G);
    ui->graphicsView_B->setScene(new QGraphicsScene(this));
    ui->graphicsView_B->scene()->addItem(&pixmap_B);
    ui->graphicsView_detecting->setScene(new QGraphicsScene(this));
    ui->graphicsView_detecting->scene()->addItem(&pixmap_DETECT);
    ui->graphicsView_Video->setScene(new QGraphicsScene(this));
    ui->graphicsView_Video->scene()->addItem(&pixmap_Video);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Button_start_clicked()
{
    using namespace cv;

    if(video.isOpened())
    {
        ui->Button_start->setText("START");
        video.release();
        return;
    }

    bool isCamera;
    int cameraIndex = ui->videoEdit->text().toInt(&isCamera);
    if(isCamera)
    {
        if(!video.open(cameraIndex))
        {
            QMessageBox::critical(this,
                                  "Camera Error",
                                  "Make sure you entered a correct camera index,"
                                  "<br>or that the camera is not being accessed by another program!");
            return;
        }
    }
    else
    {
        if(!video.open(ui->videoEdit->text().trimmed().toStdString()))
        {
            QMessageBox::critical(this,
                                  "Video Error",
                                  "Make sure you entered a correct and supported video file path,"
                                  "<br>or a correct RTSP feed URL!");
            return;
        }
    }

    ui->Button_start->setText("Stop");

    while(video.isOpened())
    {
        video >> frameOrigin;
// 히스토그램 출력
        histoview(frameOrigin);

        qApp->processEvents();
    }
    ui->Button_start->setText("Start");
}


void MainWindow::calc_histo(const cv::Mat& image, cv::Mat& hist, int channel)
{   int bins=256; int range_max=256;
    int		histSize[] = { bins };
    float   range[] = { 0, (float)range_max };
    int		channels[]= { 0, 1, 2 };
    const float* ranges[] = { range };

    cv::calcHist(&image, 1, &channels[channel], cv::Mat(), hist, 1, histSize, ranges);
}

void MainWindow::draw_histo(Mat hist, Mat &hist_img, int channels)
{
    hist_img = Mat(Size(256,200), CV_8UC3, Scalar(255,255,255));
    float  bin = (float)hist_img.cols / hist.rows;  //=256
    normalize(hist, hist, 0, 200, NORM_MINMAX);

    for (int i = 0; i<hist.rows; i++)
    {
        float  start_x = (i * bin);
        float  end_x = (i + 1) * bin;
        Point2f pt1(start_x, 0);
        Point2f pt2(end_x, hist.at <float>(i));

        if (pt2.y > 0)
            if (channels==0)
                rectangle(hist_img, pt1, pt2, Scalar(255,0,0), -1);
            if (channels==1)
                rectangle(hist_img, pt1, pt2, Scalar(0,255,0), -1);
            if (channels==2)
                rectangle(hist_img, pt1, pt2, Scalar(0,0,255), -1);

    }
    flip(hist_img, hist_img, 0); //뒤집기
}

void MainWindow::histoview(Mat frameOrigin)
{
    Mat bgr[3], bgrhist[3], bgrhist_img[3];

    split(frameOrigin, bgr);
    //blue
    calc_histo(bgr[0], bgrhist[0], 0);
    draw_histo(bgrhist[0], bgrhist_img[0], 0);
    //green
    calc_histo(bgr[1], bgrhist[1], 0);
    draw_histo(bgrhist[1], bgrhist_img[1], 1);
    //red
    calc_histo(bgr[2], bgrhist[2], 0);
    draw_histo(bgrhist[2], bgrhist_img[2], 2);

    if(!frameOrigin.empty())
    {   //red hist
        QImage qimg2(bgrhist_img[2].data, bgrhist_img[2].cols, bgrhist_img[2].rows, bgrhist_img[2].step, QImage::Format_RGB888);

        pixmap_R.setPixmap( QPixmap::fromImage(qimg2.rgbSwapped()) );
        ui->graphicsView_R->fitInView(&pixmap_R, Qt::KeepAspectRatio);
        //green hist
        QImage qimg3(bgrhist_img[1].data, bgrhist_img[1].cols, bgrhist_img[1].rows, bgrhist_img[1].step, QImage::Format_RGB888);

        pixmap_G.setPixmap( QPixmap::fromImage(qimg3.rgbSwapped()) );
        ui->graphicsView_G->fitInView(&pixmap_G, Qt::KeepAspectRatio);
        //blue hist
        QImage qimg4(bgrhist_img[0].data, bgrhist_img[0].cols, bgrhist_img[0].rows, bgrhist_img[0].step, QImage::Format_RGB888);

        pixmap_B.setPixmap( QPixmap::fromImage(qimg4.rgbSwapped()) );
        ui->graphicsView_B->fitInView(&pixmap_B, Qt::KeepAspectRatio);
    }
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    if(video.isOpened())
    {
        QMessageBox::warning(this,
                             "Warning",
                             "Stop the video before closing the application!");
        event->ignore();
    }
    else
    {
        event->accept();
    }
}


