#ifndef MYDETECTING_H
#define MYDETECTING_H

#include "mainwindow.h"


class myDetecting
{

public:





public:
    myDetecting();

    // 전처리
    cv::Mat preprocessing(cv::Mat frameOrigin);
    //Detecting
    cv::Mat face_detecting(cv::Mat frameOrigin);
    cv::Mat car_detecting(cv::Mat frameOrigin);
    cv::Mat line_detecting(cv::Mat frameOrigin);
};

#endif // MYDETECTING_H
