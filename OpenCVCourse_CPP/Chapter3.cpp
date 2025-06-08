#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream> // input /output stream

using namespace cv; // using the cv namespace to avoid typing cv:: every time
using namespace std; // using the std namespace for standard library functions

/////////////// Basic Image Processing in OpenCV /////////////////

void main() {

	string imagePath = "Resources/test.jpg";
	Mat image = imread(imagePath); // Mat is a matrix data structure used in OpenCV to store images
	Mat imageSmall, imgCrop; // Create a matrix to store the grayscale image

	cout << "Image Size: " << image.size() << endl; // Print the size of the image
	resize(image, imageSmall, Size(),0.1,0.1);
	Rect roi(100, 100, 300, 300); // Define a region of interest (ROI) with x, y, width, height
	imgCrop = image(roi);

	imshow("Image small", imageSmall); // Display the original image
	imshow("Image Crop", imgCrop); // Display the cropped image
	waitKey(0); // Wait for a key press to close the window
}