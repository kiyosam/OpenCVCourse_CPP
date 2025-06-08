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
	Mat imageSmall, imgBlur,  imgGray, imgCanny, imgDilate, imgErode; // Create a matrix to store the grayscale image
	resize(image, imageSmall, Size(image.cols / 8, image.rows / 8));


	cvtColor(imageSmall, imgGray, COLOR_BGR2GRAY); // Convert the image to grayscale
	// Add some blur
	GaussianBlur(imageSmall, imgBlur, Size(5,5),5,0);
	//Edge detection - blur image beforehand (common pratice)
	Canny(imgBlur, imgCanny, 50, 150); // decrease will give more edges

	// lets increase the thickness of the edges. Increase the size of the kernel to increase the thickness of the edges.
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5)); // Create a kernel for dilation, in Pythie would use np.ones((3,3), np.uint8)
	dilate(imgCanny, imgDilate, kernel);
	// decrease the thickness of the edges
	erode(imgDilate, imgErode, kernel); // You can create a kernel for erosion, in Python would use np.ones((3,3), np.uint8)


	imshow("Test Image", imageSmall);
	imshow("Test Gray", imgGray);
	imshow("Test Blur", imgBlur);
	imshow("Test Canny", imgCanny);
	imshow("Test Dilate", imgDilate);
	imshow("Test Erode", imgErode);
	waitKey(0); // Wait for a key press to close the window
		
}