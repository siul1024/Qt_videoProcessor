#ifndef MYTRANSFORM_H
#define MYTRANSFORM_H

#include "mainwindow.h"

class myTransform
{

public:
    myTransform();
    cv::Mat get_frame_trans(cv::Mat frameOrigin, Ui::MainWindow *ui);
    void Print(Ui::MainWindow *ui);


private:
    cv::Mat mat_rotation(cv::Mat frameOrigin, Ui::MainWindow *ui);
    cv::Mat mat_move_and_resize(cv::Mat frameOrigin, Ui::MainWindow *ui);
    int setSlider(Ui::MainWindow *ui);
    int setDial(Ui::MainWindow *ui);
};

#endif // MYTRANSFORM_H



