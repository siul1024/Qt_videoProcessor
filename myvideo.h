#ifndef MYVIDEO_H
#define MYVIDEO_H

#include "mainwindow.h"
#include "opencv2/opencv.hpp"

class myVideo
{

public:
    myVideo();


public:
    QImage get_frame(cv::Mat frameOrigin, int r, int g, int b);


};

#endif // MYVIDEO_H

