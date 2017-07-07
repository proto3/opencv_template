#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <MyProject/MyClass.h>
#include <iostream>

//----------------------------------------------------------------------------//
int main(int argc, char **argv)
{
    //IMAGE INPUT------------------------//
    cv::Mat img = cv::imread("../lena.jpg", cv::IMREAD_ANYDEPTH);
    if(img.data == NULL)
    {
        std::cerr << "Cannot read image." << std::endl;
        return -1;
    }
    //process image here
    cv::imshow("display", img);
    cv::waitKey(0);

    //VIDEO INPUT------------------------//
    cv::Mat frame;
    cv::VideoCapture video(0);
    // cv::VideoCapture video("../video.mp4");
    if(!video.isOpened())
    {
        std::cerr << "Cannot open video source." << std::endl;
        return -1;
    }
    while(video.read(frame))
    {
        //process frame here
        cv::imshow("display", frame);
        if((char)cv::waitKey(30) != -1)
        {
            break;
        }
    }

    //CLASS TEMPLATE---------------------//
    MyClass m;
    m.foo();

    return 0;
}
//----------------------------------------------------------------------------//
