#include <opencv2/opencv.hpp>
#include<opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main() {
	Mat src = imread("D:\\pic\\cppf.jpg");
	Mat dstB,dstG,dstR;
	Mat out(src.size(),src.type());
	vector<Mat> channels;
	split(src, channels);
	Mat B = channels.at(0);
	Mat G = channels.at(1);
	Mat R = channels.at(2);
	//cvtColor(B, dst1, CV_BGR2GRAY);
	equalizeHist(B, dstB);
	equalizeHist(G, dstG);
	equalizeHist(R, dstR);
	int height = src.rows;
	int width = src.cols;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			out.at<Vec3b>(i, j)[0] = dstB.at<uchar>(i, j);
			out.at<Vec3b>(i, j)[1] = dstG.at<uchar>(i, j);
			out.at<Vec3b>(i, j)[2] = dstR.at<uchar>(i, j);
		}
	}
	imshow("src", src);
	imshow("dstB", dstB);
	imshow("dstG", dstG);
	imshow("dstR", dstR);
	imshow("out", out);
	waitKey(0);
	return 0;
}