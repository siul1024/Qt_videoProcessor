#ifndef MYVIDEO_H
#define MYVIDEO_H

#include "mainwindow.h"


class myVideo
{

public:
    bool checkBox_r;
    bool checkBox_g;
    bool checkBox_b;

public:
    myVideo(Ui::MainWindow *ui);

    cv::Mat get_frame(cv::Mat frameOrigin, Ui::MainWindow *ui);

private:
    void get_checkBox_state(Ui::MainWindow *ui);


};

#endif // MYVIDEO_H

