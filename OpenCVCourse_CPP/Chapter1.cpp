#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream> // input /output stream

using namespace cv; // using the cv namespace to avoid typing cv:: every time
using namespace std; // using the std namespace for standard library functions

// import images
/*void main() { // void as we are not tring to output anything
	
	string imagePath = "Resources/test.jpg"; // Replace with your image path
	Mat image = imread(imagePath); // Mat is a matrix data structure used in OpenCV to store images
	Mat imageSmall;
	resize(image, imageSmall, Size(image.cols / 8, image.rows / 8));

	imshow("Test Image", imageSmall);
	waitKey(0); // Wait for a key press to close the window

}*/

// import video
// Normally we would write a new file. But for simplicity we will use the same file and just comment out the above function
//void main() {
//
//	string path = "Resources/test_video.mp4"; // Replace with your image path
//	VideoCapture cap(path);
//	Mat img;
//
//	// need to iterate through all the frames
//	while (true) {
//
//		cap.read(img);
//		imshow("Image", img);
//		waitKey(1); // in milliseconds
//	}
//}

// webcam
void main() {

	// Replace path with camera ID
	VideoCapture cap(0);
	Mat img;

	// need to iterate through all the frames
	while (true) {

		cap.read(img);
		imshow("Image", img);
		waitKey(1); // in milliseconds
	}
}
