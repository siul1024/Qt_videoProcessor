#include "myrec.h"
#include "ui_mainwindow.h"


myREC::myREC(Ui::MainWindow *ui, cv::Size size1)
{
    size = size1;
    rec_path = get_filepath(ui);
    fourcc = cv::VideoWriter::fourcc('D', 'X', '5', '0');
    fps = 29.97;
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


