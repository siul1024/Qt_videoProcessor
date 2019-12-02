#ifndef VIDEO_H
#define VIDEO_H

#include "mainwindow.h"


class Video
{
public:
    Video();

    void get_frame(cv::Mat *frameOrigin);
};

#endif // VIDEO_H
