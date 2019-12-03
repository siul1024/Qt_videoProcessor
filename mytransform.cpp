#include "mytransform.h"
#include "ui_mainwindow.h"



myTransform::myTransform(Ui::MainWindow *ui)
{
    ui->dial_trans->setRange(0, 36);
    ui->dial_trans->setWrapping(1);
    ui->horizontalSlider_trans->setRange(0, 100);

}


void myTransform::Print(Ui::MainWindow* ui)
{
    ui->label_7->setText("This is Transform tab");

}

void myTransform::readDial(Ui::MainWindow *ui)
{

}

cv::Mat myTransform::get_frame_trans(cv::Mat frameOrigin)
{
    cv::Mat frame = frameOrigin;
    return frame;

}

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
