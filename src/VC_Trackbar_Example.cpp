/*
 * VC_Trackbar_Example.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: vageesh
 */

#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int VC_Trackbar_Example() {

	// Variables
	Mat frame, modified_frame;
	int iBrightness, iSlider_brightness, iSlider_contrast;
	double dContrast;

	VideoCapture cap(0);

	if(!cap.isOpened()) {
		cout << "Could not initialize video camera" << endl;
		return -1;
	}

	namedWindow("Video", CV_WINDOW_AUTOSIZE);

	// Initialize trackbars sliders
	iSlider_brightness = 50;
	iSlider_contrast = 50;

	// Create Trackbars
	createTrackbar("Brightness", "Video", &iSlider_brightness, 100);
	createTrackbar("Contrast", "Video", &iSlider_contrast, 100);

	while(1) {

		bool status = cap.read(frame);

		if(!status) {
			cout << "Could not fetch frame" << endl;
			return -1;
		}

		iBrightness = iSlider_brightness - 50;
		dContrast = iSlider_contrast / 50.0;

		//adjust the brightness and contrast
		frame.convertTo(modified_frame, -1, dContrast, iBrightness);

		imshow("Video", modified_frame);

		if(waitKey(30) == 27) {
			cout << "Esc key pressed by user" << endl;
			break;
		}
	}

	return 0;
}
