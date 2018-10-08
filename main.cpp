/*
 * main.cpp
 *
 *  Created on: Oct 7, 2018
 *      Author: mmlab
 */

#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/cvaux.h>
#include <highgui.h>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

int main(){
	Mat frame;
	Mat fgMaskMog;
	Mat bg;

	int nFrames = 1000;
	double learning_rate = 0.1;

	int history = 300;
	int nmixtures = 20;

	double backgroundRatio = 0.001;
	double noiseSigma = 10;

	Ptr< BackgroundSubtractor> pMOG;
	pMOG = new BackgroundSubtractorMOG(history,nmixtures,backgroundRatio,noiseSigma);

	VideoCapture cap(0);

	if(!cap.isOpened())
		return 0;

	for (int i = 0; i<nFrames; i++){
		cap >> frame;

		pMOG->operator()(frame,fgMaskMog,learning_rate);

		imshow("video",frame);
		imshow("MOG",fgMaskMog);

		waitKey(1);

	}

}


