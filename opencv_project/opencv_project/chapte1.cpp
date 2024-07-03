//#include <opencv2/imgcodecs.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/imgproc.hpp>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//
///////////////////  Images  //////////////////////
//
///*void main() {
//
//	string path = "Resources/test.png";
//	Mat img = imread(path);
//	imshow("Image", img);
//	waitKey(10000);
//
//}*/
//
//
/////////////////  Video  //////////////////////
//
//void main() {
//
//	string path = "Resources/test_video.mp4";
//	VideoCapture cap(path);
//	Mat img;
//
//	//while (true) {
//
//		cap.read(img);
//		imshow("Image", img);
//		waitKey(20);
//	//}
//}
//
//
///////////////////  Webcam  //////////////////////
//
////void main() {
////
////	VideoCapture cap(0);
////	Mat img;
////
////	while (true) {
////
////		cap.read(img);
////		imshow("Image", img);
////		waitKey(1);
////	}
////}
#include<iostream>
#include <opencv2/opencv.hpp>

int main()
{
    // Open the video file
    std::string videoPath = "Resources/test_video.mp4";
    cv::VideoCapture caap(videoPath);

    // Check if the video file was opened successfully
    if (!caap.isOpened()) {
        std::cout << "Error opening video file" << std::endl;
        return -1;
    }

    // Create a window to display the video
    cv::namedWindow("Video", cv::WINDOW_NORMAL);

    // Read and display each frame of the video
    while (true) {
        // Read a frame from the video
        cv::Mat frame;
        bool success = caap.read(frame);

        // Check if the frame was read successfully
        if (!success)
            break;

        // Display the frame in the window
        cv::imshow("Video", frame);

        // Exit the loop if 'q' is pressed
        if (cv::waitKey(20) == 'q')
            break;
    }

    // Release the video file and close the window
    caap.release();
    cv::destroyAllWindows();

    return 0;
}
