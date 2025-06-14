#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream> // input /output stream

using namespace cv; // using the cv namespace to avoid typing cv:: every time
using namespace std; // using the std namespace for standard library functions
int hmin = 16, smin = 104, vmin = 210;
int hmax = 27, smax = 184, vmax = 255;

// Detect colors
void main() { // void as we are not tring to output anything

	string imagePath = "Resources/colorPuzzle.jpg"; // Replace with your image path
	Mat image = imread(imagePath); // Mat is a matrix data structure used in OpenCV to store images
	namedWindow("Trackbars", (640, 200)); // Create a window for the trackbars	
	createTrackbar("Hue Min", "Trackbars", &hmin, 179); // Create a trackbar for hue minimum value	
	createTrackbar("Hue Max", "Trackbars", &hmax, 179); // Create a trackbar for hue maximum value
	createTrackbar("Sat Min", "Trackbars", &smin, 255); // Create a trackbar for saturation minimum value
	createTrackbar("Sat Max", "Trackbars", &smax, 255); // Create a trackbar for saturation maximum value
	createTrackbar("Val Min", "Trackbars", &vmin, 255); // Create a trackbar for value minimum value
	createTrackbar("Val Max", "Trackbars", &vmax, 255); // Create a trackbar for value maximum value
	Mat imgHSV, mask;

	while (true) {
	Scalar lower_bound(hmin, smin, vmin);
	Scalar upper_bound(hmax, smax, vmax);

	// Finding color in HSV is easier than in RGB
	cvtColor(image, imgHSV, COLOR_BGR2HSV); // Convert the image to HSV color space	

	inRange(imgHSV, lower_bound, upper_bound, mask); // we use a range because color is a range

	imshow("Test Image", imgHSV);
	imshow("Mask", mask);
	waitKey(1);
} // Wait for a key press to close the window

}
