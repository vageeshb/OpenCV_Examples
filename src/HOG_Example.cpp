/*
 * HOG.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: vageesh
 */

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int HOG_Example (bool filtered) {
	// Initialize VC
    VideoCapture cap(0);

    //cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
    //cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);

    if (!cap.isOpened()) {
    	cout << "Could not initialize VC" << endl;
        return -1;
    }

    // Variables
    Mat frame;
    HOGDescriptor hog;
    int win_stride_slider = 8, padding_slider = 0;
    vector<Rect> found, found_filtered;
	size_t i, j;
	Rect r;

	// Set default people detector
    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

    // Create a window for controls and output
    namedWindow("Controls", CV_WINDOW_AUTOSIZE);
    namedWindow("HOG", CV_WINDOW_AUTOSIZE);

    // Add trackbars to manipulate window_stride and padding values
    createTrackbar("Win_Stride", "Controls", &win_stride_slider, 16);
    createTrackbar("Padding", "Controls", &padding_slider, 32);

    while (true) {

    	// Read frame from VC into Image
        cap.read(frame);
        if (!frame.data)
            continue;

        found.clear();
        found_filtered.clear();

        // Detect features
        hog.detectMultiScale(frame, found, 0,
        		Size(win_stride_slider, win_stride_slider),
				Size(padding_slider, padding_slider),
				1.05, 2);

        if(filtered) {
        	// Filter the found features
        	for (i=0; i<found.size(); i++) {
				r = found[i];
				for (j=0; j<found.size(); j++)
					if (j!=i && (r & found[j])==r)
						break;
				if (j==found.size())
					found_filtered.push_back(r);
			}
        }
        else {
        	found_filtered = found;
        }

        // Mark the found features with a rectangle
        for (i=0; i<found_filtered.size(); i++) {
        	r = found_filtered[i];
            r.x += cvRound(r.width*0.1);
			r.width = cvRound(r.width*0.8);
			r.y += cvRound(r.height*0.06);
			r.height = cvRound(r.height*0.9);
			rectangle(frame, r.tl(), r.br(), cv::Scalar(0,255,0), 2);
        }

        imshow("HOG", frame);

        if (waitKey(20) >= 0)
            break;
    }
    return 0;
}
