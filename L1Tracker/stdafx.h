// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

//#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
using namespace cv;


// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
#ifdef _DEBUG
//Debug Mode

#pragma comment(lib,"C:\\OpenCV\\build\\x86\\vc10\\lib\\opencv_core243d.lib")
#pragma comment(lib,"C:\\OpenCV\\build\\x86\\vc10\\lib\\opencv_imgproc243d.lib")
#pragma comment(lib,"C:\\OpenCV\\build\\x86\\vc10\\lib\\opencv_highgui243d.lib")
#pragma comment(lib,"C:\\OpenCV\\build\\x86\\vc10\\lib\\opencv_imgproc243d.lib")
#pragma comment(lib,"C:\\OpenCV\\build\\x86\\vc10\\lib\\opencv_objdetect243d.lib")
#else
//Release Mode

#pragma comment(lib,"C:\\OpenCV\\build\\x86\\vc10\\lib\\opencv_core243.lib")
#pragma comment(lib,"C:\\OpenCV\\build\\x86\\vc10\\lib\\opencv_imgproc243.lib")
#pragma comment(lib,"C:\\OpenCV\\build\\x86\\vc10\\lib\\opencv_highgui243.lib")
#pragma comment(lib,"C:\\OpenCV\\build\\x86\\vc10\\lib\\opencv_imgproc243.lib")
#pragma comment(lib,"C:\\OpenCV\\build\\x86\\vc10\\lib\\opencv_objdetect243.lib")
#endif