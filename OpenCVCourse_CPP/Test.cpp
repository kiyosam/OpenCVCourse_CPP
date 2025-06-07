#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

	string imagePath = "Resources/test.jpg"; // Replace with your image path
	Mat image = imread(imagePath);
	Mat imageSmall;
	resize(image, imageSmall, Size(image.cols / 4, image.rows / 4));

	imshow("Test Image", imageSmall);
	waitKey(0); // Wait for a key press to close the window
	return 0;
}