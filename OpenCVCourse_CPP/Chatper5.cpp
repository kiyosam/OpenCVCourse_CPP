#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream> // input /output stream

using namespace cv; // using the cv namespace to avoid typing cv:: every time
using namespace std; // using the std namespace for standard library functions

float w = 250, h = 350; // Width and height of the image to be warped
Mat matrix, imgWarp;
// Warping images
void main() { // void as we are not tring to output anything

	string imagePath = "Resources/cards.jpg"; // Replace with your image path
	Mat img = imread(imagePath); // Mat is a matrix data structure used in OpenCV to store images

	Point2f src[4] = {{1,511},{137,402},{287,669},{418,526}}; // Source points for the perspective transformation
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} }; 
	matrix = getPerspectiveTransform(src, dst); // Get the perspective transformation matrix
	warpPerspective(img, imgWarp, matrix, Point(w, h)); // Apply the perspective transformation to the image

	// create circles on the source points
	for (int i = 0; i < 4; i++) {
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED); // Draw circles on the source points 
	}

	imshow("Test Image", img);
	imshow("Warped Image", imgWarp); // Display the original and warped images
	waitKey(0); // Wait for a key press to close the window
}