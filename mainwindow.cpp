#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myrec.h"
#include "mytransform.h"
#include "myvideo.h"
#include "myhistogram.h"
#include "mydetecting.h"

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
    ui->graphicsView_trans->setScene(new QGraphicsScene(this));
    ui->graphicsView_trans->scene()->addItem(&pixmap_Trans);
    ui->graphicsView_rec->setScene(new QGraphicsScene(this));
    ui->graphicsView_rec->scene()->addItem(&pixmap);

    ui->Button_rec_stop->setEnabled(0);
    ui->Button_O->setEnabled(0);
    MYGPIO = new myGPIO();
}


////슬롯
void MainWindow::on_Button_rec_clicked()
{
    ui->Button_rec->setEnabled(0);
    ui->Button_rec_stop->setEnabled(1);
    bth = new BlinkThread(this);
    bth->start();
}
void MainWindow::on_Button_rec_stop_clicked()
{
    ui->Button_rec_stop->setEnabled(0);
    ui->Button_rec->setEnabled(1);
    bth->terminate();
    digitalWrite(1, 0);
}
void MainWindow::on_Button_capture_clicked()
{
    ui->Button_capture->setEnabled(0);
}

void MainWindow::on_Button_FACE_clicked()
{
    ui->Button_CAR->setEnabled(1);
    ui->Button_FACE->setEnabled(0);
    ui->Button_O->setEnabled(1);
}
void MainWindow::on_Button_CAR_clicked()
{
    ui->Button_CAR->setEnabled(0);
    ui->Button_FACE->setEnabled(1);
    ui->Button_O->setEnabled(1);
}
void MainWindow::on_Button_O_clicked()
{
    ui->Button_CAR->setEnabled(1);
    ui->Button_FACE->setEnabled(1);
    ui->Button_O->setEnabled(0);
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

    video.set(cv::CAP_PROP_FRAME_WIDTH, 320);
    video.set(cv::CAP_PROP_FRAME_HEIGHT, 240);

    // frameOrigin 초기화
    video >> frameOrigin;

    myVideo *MV = new myVideo(ui);
    myTransform *TF = new myTransform;
    myREC *MR = new myREC(ui, size);
    myDetecting *DT = new myDetecting;


    while(video.isOpened())
    {
        video >> frameOrigin;
        myHistogram::histoview(this);
//Video tab 출력
        if (ui->tabWidget->currentIndex() == 0)
        {
            cv::Mat resimg = MV->get_frame(frameOrigin, ui);
            QImage qimg_v(resimg.data, resimg.cols, resimg.rows, resimg.step, QImage::Format_RGB888);
            pixmap_Video.setPixmap( QPixmap::fromImage(qimg_v) );
            ui->graphicsView_Video->fitInView(&pixmap_Video, Qt::KeepAspectRatio);
        }
//Transform tab 출력
        if (ui->tabWidget->currentIndex() == 1)
        {
            cv::Mat resimg_t = TF->get_frame_trans(frameOrigin, ui);
            QImage qimg_t(resimg_t.data, resimg_t.cols, resimg_t.rows, resimg_t.step, QImage::Format_RGB888);
            pixmap_Trans.setPixmap( QPixmap::fromImage(qimg_t.rgbSwapped()) );
            ui->graphicsView_trans->fitInView(&pixmap_Trans, Qt::KeepAspectRatio);
        }
//REC tab 출력
        if (ui->tabWidget->currentIndex() == 2)
        {
            MYGPIO->read_brightness();
            ui->label_8->setNum(MYGPIO->adcValue);
            if (ui->radioButton->isChecked()==true)
            {
                frameOrigin = MR->Option_checked(frameOrigin, MYGPIO->adcValue);
            }
            if (ui->Button_rec->isEnabled() == 0)
            {
                MR->REC_clicked(frameOrigin);
            }

            if (ui->Button_capture->isEnabled() == 0)
            {
                MR->CAP_clicked(frameOrigin);
                ui->Button_capture->setEnabled(1);
            }
            QImage qimg(frameOrigin.data, frameOrigin.cols, frameOrigin.rows, frameOrigin.step, QImage::Format_RGB888);
            pixmap.setPixmap( QPixmap::fromImage(qimg.rgbSwapped()) );
            ui->graphicsView_rec->fitInView(&pixmap, Qt::KeepAspectRatio);
        }
        if (ui->tabWidget->currentIndex() == 3)
        {   cv::Mat dtimg;
            if (ui->Button_FACE->isEnabled() == 0)
            {   dtimg = DT->face_detecting(frameOrigin);    }
            else if (ui->Button_CAR->isEnabled() == 0)
            {   dtimg = DT->car_detecting(frameOrigin);     }
            else
            {   dtimg = frameOrigin;    }
            QImage qimg_d(dtimg.data, dtimg.cols, dtimg.rows, dtimg.step, QImage::Format_RGB888);
            pixmap_DETECT.setPixmap( QPixmap::fromImage(qimg_d.rgbSwapped()) );
            ui->graphicsView_detecting->fitInView(&pixmap_DETECT, Qt::KeepAspectRatio);
        }
        qApp->processEvents();
    }
    ui->Button_start->setText("Start");
    delete MV;
    delete TF;
    delete MR;
    delete DT;
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



