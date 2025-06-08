#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream> // input /output stream

using namespace cv; // using the cv namespace to avoid typing cv:: every time
using namespace std; // using the std namespace for standard library functions

/////////////// Draw shapes and text /////////////////

void main() {

	// Creat a blank image. Color is defined as a scalar
	Mat img(512, 512, CV_8UC3, Scalar(255, 0, 0));    // 8 bit means 0 -255. 2^8 is 256 values. Unisgned 0-255, signed -128 to 127
	
	circle(img, Point(256, 256), 100, Scalar(0, 255, 0), FILLED); // Draw a filled green circle at the center of the image
	rectangle(img, Point(100, 100), Point(400, 400), Scalar(0, 0, 255), 5); // Draw a red rectangle with thickness of 5 pixels
	line(img, Point(0, 0), Point(512, 512), Scalar(255, 255, 0), 2); // Draw a blue line from top left to bottom right

	putText(img, "OpenCV", Point(200, 450), FONT_HERSHEY_DUPLEX, 2, Scalar(255, 255, 255), 2); // Draw white text "OpenCV" at the bottom of the image
	imshow("Image",img);
	waitKey(0); // Wait for a key press to close the window
}