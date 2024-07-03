#include<iostream>
#include <opencv2/opencv.hpp>

int main()
{
    // Open the video file
   // std::string videoPath = "Resources/test_video.mp4";
    cv::VideoCapture caap("Resources/test_video.mp4");

    ////// Check if the video file was opened successfully
    //if (!caap.isOpened()) {
    //    std::cout << "Error opening video file" << std::endl;
    //    return -1;
    //}

    //// Create a window to display the video
    //cv::namedWindow("Video", cv::WINDOW_NORMAL);
  //  cv::namedWindow("video", cv::WINDOW_NORMAL);

    //// Read and display each frame of the video
    while (true) {
        // Read a frame from the video
        cv::Mat frame;
         caap.read(frame);

        // Check if the frame was read successfully
      //  if (!success)
        //    break;

        // Display the frame in the window
        cv::imshow("Videoplay", frame);
        cv::waitKey(01);
    

        // Exit the loop if 'q' is pressed
       // if (cv::waitKey(20) == 'q')
         //   break;
    }

    //// Release the video file and close the window
    caap.release();
    cv::destroyAllWindows();

    return 0;
}