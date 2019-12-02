#ifndef VIDEO_H
#define VIDEO_H

#include "mainwindow.h"
#include "opencv2/opencv.hpp"

class myVideo
{

public:
    myVideo();

public:
    cv::Mat get_frame(cv::Mat frameOrigin, int r, int g, int b);


};

#endif // VIDEO_H

