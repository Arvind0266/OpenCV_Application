#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    // Create a VideoCapture object to access the webcam
    cv::VideoCapture cap(0);

    if (!cap.isOpened())
    {
        std::cerr << "Failed to open webcam." << std::endl;
        return 1;
    }

    // Load the face cascade classifier
    cv::CascadeClassifier faceCascade;
    if (!faceCascade.load("Resources/haarcascade_frontalface_default.xml"))
    {
        std::cerr << "Failed to load face cascade classifier." << std::endl;
        return 1;
    }

    // Create a window for displaying the output
    cv::namedWindow("Face Detection", cv::WINDOW_NORMAL);

    while (true)
    {
        // Read a frame from the webcam
        cv::Mat frame;
        cap >> frame;

        // Convert the frame to grayscale
        cv::Mat grayFrame;
        cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);

        // Equalize the histogram to improve contrast
        cv::equalizeHist(grayFrame, grayFrame);

        // Detect faces in the frame
        std::vector<cv::Rect> faces;
        faceCascade.detectMultiScale(grayFrame, faces, 1.3, 5);
        for (const auto& face : faces)
        {
            // Crop the face region from the frame
            cv::Mat faceROI = frame(face);

            // Display the cropped face region
            cv::imshow("Cropped Face", faceROI);

            // Save the cropped face region as an image
            std::string filename = "output_" + std::to_string(std::time(0)) + ".jpg";
            cv::imwrite(filename, faceROI);
        }
        // Process each detected face
        for (const auto& face : faces)
        {
            // Crop the face region from the frame
            cv::Mat faceROI = frame(face);

            // Save the cropped face region as an image
            std::string filename = "output_" + std::to_string(std::time(0)) + ".jpg";
            cv::imwrite(filename, faceROI);

            // Draw rectangles around the detected faces on the original frame
            cv::rectangle(frame, face, cv::Scalar(0, 255, 0), 2);
        }

        // Display the frame with face detection results
        cv::imshow("Face Detection", frame);
        // Display the frame with face detection results
        //cv::imshow("Face Detection", frame);

        // Break the loop if the 'q' key is pressed
        if (cv::waitKey(1) == 'q')
            break;
    }

    // Release the VideoCapture and destroy the windows
    cap.release();
    cv::destroyAllWindows();

    return 0;
}
