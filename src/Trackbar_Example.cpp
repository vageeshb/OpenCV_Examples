/*
 * Trackbar_Example.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: vageesh
 */

#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

Mat src;

void callbackForBrightness(int brightness_value, void* data) {
	Mat dst;
	int contrast_value = *(static_cast<int*>(data));
	//Calculating brightness and contrast value
	 int iBrightness = brightness_value - 50;
	 double dContrast = contrast_value / 50.0;

	 //adjust the brightness and contrast
	 src.convertTo(dst, -1, dContrast, iBrightness);

	 //show the brightness and contrast adjusted image
	 imshow("Win1", dst);
}

void callbackForContrast(int contrast_value, void* data) {
	Mat dst;
	int brightness_value = *(static_cast<int*>(data));
	//Calculating brightness and contrast value
	 int iBrightness = brightness_value - 50;
	 double dContrast = contrast_value / 50.0;

	 //adjust the brightness and contrast
	 src.convertTo(dst, -1, dContrast, iBrightness);

	 //show the brightness and contrast adjusted image
	 imshow("Win1", dst);
}

int Trackbar_Example() {
	// Read image
	src = imread("pic.jpg");

	if(!src.data) {
		cout << "Could not read image" << endl;
		return -1;
	}

	// Create window
	namedWindow("Win1", 1);

	int slider1_value = 50;
	int slider2_value = 50;

	createTrackbar("Brightness", "Win1", &slider1_value, 100, callbackForBrightness, &slider2_value);
	createTrackbar("Contrast", "Win1", &slider2_value, 100, callbackForContrast, &slider1_value);

	imshow("Win1", src);

	// Wait until user press some key
	waitKey(0);

	return 0;
}
