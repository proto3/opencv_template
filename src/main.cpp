#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <fstream>
#include <sys/mman.h>
#include <unistd.h>

using namespace std;

//----------------------------------------------------------------------------//
int main(int argc, char **argv)
{
    size_t length = 512 * 512;
    void* addr = mmap(NULL, sizeof(uint8_t)*length, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if(addr == MAP_FAILED)
    {
        cout << "fail" << endl;
        exit(-1);
    }
    uint8_t* data = (uint8_t*)addr;


    //TODO FIND A WAY TO COPY image file to a buffer while checking its type and size 
    // cv::Mat img(512, 512, CV_8UC1, data);
    // img = imread("../lena.jpg", cv::IMREAD_GRAYSCALE);
    // img = cv::Mat(512, 512, CV_8UC1, data);
    std::ifstream file("../lena.jpg", std::ios::binary | std::ios::ate);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<char> buffer(size);
    if (file.read(buffer.data(), size))
    {
        /* worked! */
    }

    cv::imdecode(buffer, IMREAD_GRAYSCALE, data);


    int counter = 0;
    pid_t pid = fork();

    if(pid == 0)
    {
        // usleep(100000);
        // int ret = munmap(addr, length);
        cout << "child" << endl;
        for(int i = 0; i < 10000 ; i++)
            data[i] = i / 50;
        cv::imshow("display", img);
        cv::waitKey(0);
        return 0;
    }
    else if(pid > 0)
    {
        usleep(100000);
        data[5000] = 0;
        cv::imshow("display", img);
        cv::waitKey(0);
        return 0;
    }
    else
    {
        cout << "fork failed" << endl;
        return -1;
    }

    return 0;
}
//----------------------------------------------------------------------------//
