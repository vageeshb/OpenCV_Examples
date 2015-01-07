/*
 * VC_Example.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: vageesh
 */

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int VC_Example()
{
	VideoCapture cap(0);
	if(!cap.isOpened()) {
		cout << "Could not open video cam" << endl;
		return -1;
	}

	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

	cout << "Frame size: " << dWidth << " x " << dHeight<< endl;

	namedWindow("Video", CV_WINDOW_AUTOSIZE);

	while(1) {
		Mat frame;

		bool b = cap.read(frame);

		if(!b) {
			cout << "Could not read frame" << endl;
			return -1;
		}

		imshow("Video", frame);

		if(waitKey(30) == 27) {
			cout << "Esc key pressed by user" << endl;
			break;
		}
	}

	return 0;
}
