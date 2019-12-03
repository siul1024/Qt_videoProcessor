#include "myvideo.h"
#include "ui_mainwindow.h"

myVideo::myVideo()
{

}

cv::Mat myVideo::get_frame(cv::Mat frameOrigin, int r, int g, int b)
{   cv::Mat bgr[3];
    std::vector<cv::Mat> imgv;
    cv::split(frameOrigin, bgr);
    if (r==0)
    {
        bgr[2] = 0;
    }
    if (g==0)
    {
        bgr[1] = 0;
    }
    if (b==0)
    {
        bgr[0] = 0;
    }
    imgv.push_back(bgr[2]);
    imgv.push_back(bgr[1]);
    imgv.push_back(bgr[0]);
    cv::Mat resimg;
    cv::merge(imgv, resimg);
    return resimg;

}
