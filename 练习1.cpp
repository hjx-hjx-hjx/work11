#include <opencv2/opencv.hpp>
#include<opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
float gamma = 0.5;
int main() {
	Mat srcMat = imread("D:\\pic\\11_1.jpg",0);
	Mat_<float> src;
	normalize(srcMat, src, 0, 1, CV_MINMAX);
		int height = src.rows;
		int width = src.cols;
		cout << "LutÊý×é£º" << endl;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				src.at<float>(i, j) = pow(src.at<float>(i, j), gamma);
			}
		}
		int Lut[256];
		for (int i = 0; i < 256; i++) {
			Lut[i] = 0;
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				Lut[(int)(src.at<float>(i, j) * 255)]++;
			}
		}
		for (int i = 0; i < 256; i++) {
			cout << Lut[i] << endl;;
		}
		//imshow("srcMat", srcMat);
		//imshow("src", src);
		waitKey(0);
	return 0;
}