#ifndef MYTRANSFORM_H
#define MYTRANSFORM_H

#include "mainwindow.h"

class myTransform
{

public:
    myTransform(Ui::MainWindow *ui);


    cv::Mat get_frame_trans(cv::Mat frameOrigin);

    void Print(Ui::MainWindow *ui);
    void readDial(Ui::MainWindow *ui);

};

#endif // MYTRANSFORM_H



