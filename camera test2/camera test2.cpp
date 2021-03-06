// camera test2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp> 
#include<iostream>

using namespace std;
using namespace cv;

int main() {
	//1：远离数据线 2：靠近数据线
	VideoCapture cap;
	VideoCapture cap1;
	cap.open(2); //打开视频,以上两句等价于VideoCapture cap("E://2.avi");

	cap1.open(1);					   //cap.open("http://www.laganiere.name/bike.avi");//也可以直接从网页中获取图片，前提是网页有视频，以及网速够快
	if (!cap.isOpened())//如果视频不能正常打开则返回
		return -1;
	Mat frame;
	Mat frame1;
	while (1)
	{
		cap >> frame;//等价于cap.read(frame);
		cap1 >> frame1;
		if (frame.empty())//如果某帧为空则退出循环
			break;
		if (frame1.empty())//如果某帧为空则退出循环
			break;
		imshow("video", frame);
		imshow("video", frame1);
		waitKey(20);//每帧延时20毫秒
		imwrite("cap2_right.jpg", frame);
		imwrite("cap1_right.jpg", frame1);
		break;
	}
	cap.release();//释放资源
	cap1.release();
	return 0;
}

