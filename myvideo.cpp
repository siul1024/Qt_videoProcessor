#include "myvideo.h"
#include "ui_mainwindow.h"

myVideo::myVideo(Ui::MainWindow *ui)
{
    get_checkBox_state(ui);
}

cv::Mat myVideo::get_frame(cv::Mat frameOrigin, Ui::MainWindow *ui)
{
    get_checkBox_state(ui);
    cv::Mat bgr[3];
    std::vector<cv::Mat> imgv;
    cv::split(frameOrigin, bgr);
    if (checkBox_r==0)
    {   bgr[2] = 0; }
    if (checkBox_g==0)
    {   bgr[1] = 0; }
    if (checkBox_b==0)
    {   bgr[0] = 0;    }
    imgv.push_back(bgr[2]);
    imgv.push_back(bgr[1]);
    imgv.push_back(bgr[0]);
    cv::Mat resimg;
    cv::merge(imgv, resimg);
    return resimg;
}

void myVideo::get_checkBox_state(Ui::MainWindow *ui)
{
    checkBox_r = ui->checkBox_R->checkState();
    checkBox_g = ui->checkBox_G->checkState();
    checkBox_b = ui->checkBox_B->checkState();
}
