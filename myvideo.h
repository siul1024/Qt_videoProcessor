#ifndef MYVIDEO_H
#define MYVIDEO_H

#include <QImage>
#include "opencv2/opencv.hpp"

class myVideo
{

public:
    myVideo();


public:
    cv::Mat get_frame(cv::Mat frameOrigin, int r, int g, int b);


};

#endif // MYVIDEO_H

