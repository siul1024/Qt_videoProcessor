#ifndef MYVIDEO_H
#define MYVIDEO_H

#include "mainwindow.h"


class myVideo
{

public:
    myVideo();

    cv::Mat get_frame(cv::Mat frameOrigin, int r, int g, int b);


};

#endif // MYVIDEO_H

