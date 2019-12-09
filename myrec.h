#ifndef MYREC_H
#define MYREC_H

#include "mainwindow.h"

class myREC
{
public:
    std::string rec_path;
    cv::Size size;
    int fourcc;
    double fps;
    int delay;
    cv::VideoWriter writer;

public:
    myREC(Ui::MainWindow *ui, cv::Size size);
    ~myREC();
    void REC_clicked(cv::Mat frameOrigin);
    void CAP_clicked(cv::Mat frameOrigin);
    cv::Mat Option_checked(cv::Mat frameOrigin, int val);
private:
    std::string get_filepath(Ui::MainWindow *ui);

};

#endif // MYREC_H
