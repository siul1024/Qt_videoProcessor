#include "mydetecting.h"

myDetecting::myDetecting()
{


}


cv::Mat myDetecting::preprocessing(cv::Mat frameOrigin)
{
    cv::Mat gray;
    cv::cvtColor(frameOrigin, gray, cv::COLOR_BGR2GRAY);
    cv::equalizeHist(gray, gray);
    return gray;
}


cv::Mat myDetecting::face_detecting(cv::Mat frameOrigin)
{

    cv::CascadeClassifier face_cascade("./xml/haarcascade_frontalface_alt2.xml");
    cv::Mat frame;
    cv::Mat gray = preprocessing(frameOrigin);
    frame = frameOrigin;
    std::vector<cv::Rect> faces;
    face_cascade.detectMultiScale(gray, faces);
    if (faces.size() > 0)
    {
        cv::rectangle(frame, faces[0], cv::Scalar(255, 0, 0), 2);
    }
    return frame;
}

cv::Mat myDetecting::car_detecting(cv::Mat frameOrigin)
{

    cv::CascadeClassifier face_cascade("./xml/cascade2.xml");
    cv::Mat frame;
    cv::Mat gray = preprocessing(frameOrigin);
    frame = frameOrigin;
    std::vector<cv::Rect> cars;
    face_cascade.detectMultiScale(gray, cars);
    if (cars.size() > 0)
    {
        cv::rectangle(frame, cars[0], cv::Scalar(255, 0, 0), 2);
    }
    return frame;
}


