#ifndef MYHISTOGRAM_H
#define MYHISTOGRAM_H

#include "ui_mainwindow.h"
#include "mainwindow.h"

class myHistogram
{

public:

    static void draw_histo(cv::Mat hist, cv::Mat &hist_img, int channels);
    static void calc_histo(const cv::Mat& image, cv::Mat& hist, int channel);
    static void histoview(MainWindow *mw);

};

#endif // MYHISTOGRAM_H
