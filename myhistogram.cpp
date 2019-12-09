#include "myhistogram.h"


void myHistogram::calc_histo(const cv::Mat& image, cv::Mat& hist, int channel)
{   int     bins=256; int range_max=256;
    int		histSize[] = { bins };
    float   range[] = { 0, (float)range_max };
    int		channels[]= { 0, 1, 2 };
    const float* ranges[] = { range };

    cv::calcHist(&image, 1, &channels[channel], cv::Mat(), hist, 1, histSize, ranges);
}

void myHistogram::draw_histo(cv::Mat hist, cv::Mat &hist_img, int channels)
{
    hist_img = cv::Mat(cv::Size(256,200), CV_8UC3, cv::Scalar(255,255,255));
    float  bin = (float)hist_img.cols / hist.rows;  //=256
    normalize(hist, hist, 0, 200, cv::NORM_MINMAX);

    for (int i = 0; i<hist.rows; i++)
    {
        float  start_x = (i * bin);
        float  end_x = (i + 1) * bin;
        cv::Point2f pt1(start_x, 0);
        cv::Point2f pt2(end_x, hist.at <float>(i));

        if (pt2.y > 0)
        {   if (channels==0)
            {   rectangle(hist_img, pt1, pt2, cv::Scalar(255,0,0), -1);}
            if (channels==1)
            {   rectangle(hist_img, pt1, pt2, cv::Scalar(0,255,0), -1);}
            if (channels==2)
            {   rectangle(hist_img, pt1, pt2, cv::Scalar(0,0,255), -1);}
        }
    }
    flip(hist_img, hist_img, 0); //뒤집기
}

void myHistogram::histoview(MainWindow *mw)
{
    cv::Mat bgr[3], bgrhist[3], bgrhist_img[3];

    split(mw->frameOrigin, bgr);
    //blue
    calc_histo(bgr[0], bgrhist[0], 0);
    draw_histo(bgrhist[0], bgrhist_img[0], 0);
    //green
    calc_histo(bgr[1], bgrhist[1], 0);
    draw_histo(bgrhist[1], bgrhist_img[1], 1);
    //red
    calc_histo(bgr[2], bgrhist[2], 0);
    draw_histo(bgrhist[2], bgrhist_img[2], 2);

    if(!mw->frameOrigin.empty())
    {   //red hist
        QImage qimg2(bgrhist_img[2].data, bgrhist_img[2].cols, bgrhist_img[2].rows, bgrhist_img[2].step, QImage::Format_RGB888);
        mw->pixmap_R.setPixmap( QPixmap::fromImage(qimg2.rgbSwapped()) );
        mw->ui->graphicsView_R->fitInView(&mw->pixmap_R, Qt::KeepAspectRatio);
        //green hist
        QImage qimg3(bgrhist_img[1].data, bgrhist_img[1].cols, bgrhist_img[1].rows, bgrhist_img[1].step, QImage::Format_RGB888);

        mw->pixmap_G.setPixmap( QPixmap::fromImage(qimg3.rgbSwapped()) );
        mw->ui->graphicsView_G->fitInView(&mw->pixmap_G, Qt::KeepAspectRatio);
        //blue hist
        QImage qimg4(bgrhist_img[0].data, bgrhist_img[0].cols, bgrhist_img[0].rows, bgrhist_img[0].step, QImage::Format_RGB888);

        mw->pixmap_B.setPixmap( QPixmap::fromImage(qimg4.rgbSwapped()) );
        mw->ui->graphicsView_B->fitInView(&mw->pixmap_B, Qt::KeepAspectRatio);
    }
}

