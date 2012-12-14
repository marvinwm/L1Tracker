#pragma once
#include "stdafx.h"

#define MAX_TEMPLATE 10


class L1Tracker
{
public:
	L1Tracker(Mat &srcImg,Rect &ROI);
	~L1Tracker(void);
private:
	void initTargetTemplate(Mat &srcImg,Rect &ROI);
	void initTrivialTemplate();
	void CreateMatrix();
	Mat getROI(Mat &srcImg,RotatedRect &ROI);
	vector<Mat*> targetTemplate;
	vector<SparseMat*> trivialTemplate;
	SparseMat B;	//B=[Target Trivial -Trivial]
	Size templateSize;
	int templateType;
};

