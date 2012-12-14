#include "stdafx.h"
#include "L1Tracker.h"



L1Tracker::L1Tracker(Mat &srcImg,Rect &ROI)
{
	templateType=srcImg.type();
	templateSize=ROI.size();
	initTargetTemplate(srcImg,ROI);
	initTrivialTemplate();
}


L1Tracker::~L1Tracker(void)
{
}

Mat L1Tracker::getROI(Mat &srcImg,RotatedRect &ROI)
{
	// matrices we'll use
	Mat M, rotated, cropped;
	// get angle and size from the bounding box
	float angle = ROI.angle;
	Size rect_size = ROI.size;
	// thanks to http://felix.abecassis.me/2011/10/opencv-rotation-deskewing/
	if (ROI.angle < -45.) {
		angle += 90.0;
		swap(rect_size.width, rect_size.height);
	}
	// get the rotation matrix
	M = getRotationMatrix2D(ROI.center, angle, 1.0);
	// perform the affine transformation
	warpAffine(srcImg, rotated, M, srcImg.size(), INTER_CUBIC);
	// crop the resulting image
	getRectSubPix(rotated, rect_size, ROI.center, cropped);
	return cropped;
}

//根据用户输入初始化目标模板，分别为原位置，以及8个方向的随机位移构成
void L1Tracker::initTargetTemplate(Mat &srcImg,Rect &ROI)
{
	Rect rect=ROI;
	targetTemplate.push_back(new Mat(srcImg,rect)); //(0,0)
	rect.x+=1;	//(1,0)
	targetTemplate.push_back(new Mat(srcImg,rect));
	rect.y+=1;	//(1,1)
	targetTemplate.push_back(new Mat(srcImg,rect));
	rect.x-=1;	//(0,1)
	targetTemplate.push_back(new Mat(srcImg,rect));
	rect.x-=1;	//(-1,1)
	targetTemplate.push_back(new Mat(srcImg,rect));
	rect.y-=1;	//(-1,0)
	targetTemplate.push_back(new Mat(srcImg,rect));
	rect.y-=1;	//(-1,-1)
	targetTemplate.push_back(new Mat(srcImg,rect));
	rect.x+=1;	//(0,-1)
	targetTemplate.push_back(new Mat(srcImg,rect));
}

void L1Tracker::initTrivialTemplate()
{
	int size[]={templateSize.height,templateSize.width},idx[2];
	for (int i=0;i<templateSize.height;++i)
	{
		idx[0]=i;
		for (int j=0;j<templateSize.width;++j)
		{
			idx[1]=j;
			SparseMat *tmp=new SparseMat(2,size,CV_8UC1);
			tmp->ref<uchar>(idx)=255;
			trivialTemplate.push_back(tmp);
		}
	}

}

void L1Tracker::CreateMatrix()
{

}