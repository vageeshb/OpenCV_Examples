/*
 * Main.cpp
 *
 *  Created on: Jan 7, 2015
 *      Author: vageesh
 */


#include "Example_Headers.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

	int choice;
	cout << "Examples: " << endl;
	cout << "1. Video Capture" << endl;
	cout << "2. Trackbar" << endl;
	cout << "3. Video Capture & Trackbar" << endl;
	cout << "4. Object Detection" << endl;
	cout << "5. Object Tracking" << endl;
	cout << "6. People Detection using HOG" << endl << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	switch(choice) {
		case 1: VC_Example();
			break;
		case 2: Trackbar_Example();
			break;
		case 3: VC_Trackbar_Example();
			break;
		case 4: ObjectDetection_Example();
			break;
		case 5: ObjectTracking_Example();
			break;
		case 6: HOG_Example(true);
			break;
		default: cout << "Wrong choice entered!" << endl;
	}
	return 0;
}
