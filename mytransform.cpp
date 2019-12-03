#include "mytransform.h"
#include "ui_mainwindow.h"
#include <math.h>

myTransform::myTransform()
{

}


void myTransform::Print(Ui::MainWindow* ui)
{
    ui->label_7->setText("This is Transform tab");

}

int myTransform::setDial(Ui::MainWindow *ui)
{
    ui->dial_trans->setEnabled(true);
    return ui->dial_trans->value()*(-10);
}

int myTransform::setSlider(Ui::MainWindow *ui)
{
    ui->horizontalSlider_trans->setEnabled(true);
    return  ui->horizontalSlider_trans->value();
}

cv::Mat myTransform::get_frame_trans(cv::Mat frameOrigin, Ui::MainWindow *ui)
{
    cv::Mat resframe;
    cv::resize(frameOrigin, frameOrigin, cv::Size(480, 360), 0, 0, cv::INTER_LINEAR);
    resframe = mat_rotation(frameOrigin, ui);

    return mat_move_and_resize(resframe, ui);
}

cv::Mat myTransform::mat_rotation(cv::Mat frameOrigin, Ui::MainWindow *ui)
{
    cv::Mat frame;
    int s_val=abs(setSlider(ui));
    float val = s_val/10.0; if (val < 2) val = 2;
    val = 1.2/(val) + 0.2;
    ui->label_7->setText(QString::number(s_val));
    cv::Mat mat_rotate = getRotationMatrix2D(cv::Point(frameOrigin.cols/2, frameOrigin.rows/2), setDial(ui), val);
    cv::warpAffine(frameOrigin, frame, mat_rotate, cv::Size(frameOrigin.cols, frameOrigin.rows), cv::INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(255, 255, 255));
    return frame;
}

cv::Mat myTransform::mat_move_and_resize(cv::Mat frame, Ui::MainWindow *ui)
{
    cv::Matx23d M(1, 0, (setSlider(ui)), 0, 1, 0);
    cv::Mat resframe;
    cv::warpAffine(frame, resframe, M, cv::Size(frame.cols, frame.rows), cv::INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(255, 255, 255));
    return resframe;
}

//Point2f cp(src.cols / 2.f, src.rows / 2.f);
//11        Mat M = getRotationMatrix2D(cp, 20, 1);
//12
//13        Mat dst;
//14        warpAffine(src, dst, M, Size());

//if (ui->dialB->isChecked()) {
//        ui->dial->setEnabled(true);
//        displayValue(ui->dial->value()*10);
//        ui->slider->setValue(0);
//        ui->slider->setEnabled(false);




//connect(ui->dial, SIGNAL(valueChanged(int)),
//        SLOT(setValue()));
//connect(ui->slider, SIGNAL(valueChanged(int)),
//        SLOT(setValue()));
//connect(ui->sliderB, SIGNAL(toggled(bool)),
//        SLOT(setValue()));
//connect(ui->dialB, SIGNAL(toggled(bool)),
//        SLOT(setValue()));
//ui->dial->setEnabled(false);
//ui->slider->setEnabled(false);
