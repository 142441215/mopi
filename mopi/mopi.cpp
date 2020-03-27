#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main() {
	VideoCapture cap(0);
	double scale = 0.5;
	double i_minH = 0;
	double i_maxH = 20;
	double i_minS = 50;
	double i_maxS = 255;
	double i_minV = 50;
	double i_maxV = 255;
		Mat frame;
		Mat hsvMat;
		Mat detectMat;
		Mat medMat;
		Mat dipMat;
	while (1)
	{
		cap >> frame;
		Size ResImgsiz = Size(frame.cols*scale, frame.rows*scale);
		Mat rFrame = Mat(ResImgsiz, frame.type());
		resize(frame, rFrame, ResImgsiz, INTER_LINEAR);
		cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);
		rFrame.copyTo(detectMat);
		cv::inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), detectMat);
		GaussianBlur(rFrame, medMat, Size(3, 3), 3, 3);
		rFrame.copyTo(dipMat);
		medMat.copyTo(dipMat, detectMat);
		imshow("whie: in the range", detectMat);
		imshow("dipMat", dipMat);
		imshow("frame", rFrame);
		waitKey(30);

	}
}