#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    // Read the input image
    cv::Mat image = cv::imread("input.jpg");

    if (image.empty())
    {
        std::cerr << "Failed to read image." << std::endl;
        return 1;
    }

    // Convert the image to grayscale
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

    // Apply Gaussian blur to reduce noise
    cv::GaussianBlur(grayImage, grayImage, cv::Size(5, 5), 0);

    // Perform edge detection using Canny algorithm
    cv::Mat edges;
    cv::Canny(grayImage, edges, 50, 150);

    // Find contours in the edge image
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(edges, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // Find the largest contour (presumed to be the document boundary)
    double maxArea = 0;
    int maxIdx = -1;

    for (int i = 0; i < contours.size(); ++i)
    {
        double area = cv::contourArea(contours[i]);

        if (area > maxArea)
        {
            maxArea = area;
            maxIdx = i;
        }
    }

    // Approximate the contour with a polygon
    std::vector<cv::Point> polygon;
    cv::approxPolyDP(contours[maxIdx], polygon, 3, true);

    // Create a blank image for the output
    cv::Mat output(image.size(), CV_8UC3, cv::Scalar(255, 255, 255));

    // Draw the polygon on the output image
    std::vector<std::vector<cv::Point>> drawContour = { polygon };
    cv::drawContours(output, drawContour, 0, cv::Scalar(0, 0, 255), 2);

    // Display the output image
    cv::imshow("Scanned Document", output);
    cv::waitKey(0);

    return 0;
}
