#include "myrec.h"
#include "ui_mainwindow.h"


myREC::myREC(Ui::MainWindow *ui, cv::Size size1)
{
    size = size1;
    rec_path = get_filepath(ui);
    fourcc = cv::VideoWriter::fourcc('D', 'X', '5', '0');
    fps = 10.0;
    delay = cvRound(1000.0 / fps);
    writer.open(rec_path, fourcc, fps, size);
}

std::string myREC::get_filepath(Ui::MainWindow *ui)
{
    return ui->lineEdit_path->text().toStdString();
}

void myREC::REC_clicked(cv::Mat frameOrigin)
{
    writer << frameOrigin;
    cv::waitKey(delay);
}
void myREC::CAP_clicked(cv::Mat frameOrigin)
{
    cv::imwrite("./writetest.jpg", frameOrigin);
}

cv::Mat myREC::Option_checked(cv::Mat frameOrigin, int val)
{
    if (val > 300 & val < 400)
    {
        frameOrigin *= 1.1;
    }
    else if (val >= 400 & val < 500)
    {
        frameOrigin *= 1.2;
    }
    else if (val >= 500 & val < 600)
    {
        frameOrigin *= 1.3;
    }
    else if (val >= 600)
    {
        frameOrigin *= 1.4;
    }
    return frameOrigin;
}


myREC::~myREC()
{

}
