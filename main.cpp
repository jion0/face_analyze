#include<iostream>
#include "opencv2/opencv.hpp"
#include "face.h"

using namespace cv;
using namespace std;
using namespace aip;

int main()
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
     {
     cout<<"fail"<<endl;
     return -1;
     }
     cout<<"succeeded"<<endl;
     
     Mat img;
     Mat gray;
     Mat equ;
     
     CascadeClassifier classf("/usr/share/opencv/haarcascades/haarcascade_frontalface_alt2.xml");  //加入opencv已经训练好的人脸模型
     
     vector<Rect> allFace;
     Mat faceImg;
     vector<uchar> jpgBuf;
     
         // 设置APPID/AK/SK
    std::string app_id = "";
    std::string api_key = "";  //请自己添加
    std::string secret_key = "";

    aip::Face client(app_id, api_key, secret_key);
    
    std::string base64Img;
    
    Json::Value result;
    
    time_t sec;
     
     for(;;)
     {
     	cap>>img;
     	cvtColor(img, gray, CV_BGR2GRAY );
     	equalizeHist(gray, equ);
     	classf.detectMultiScale(equ, allFace);
     	if(allFace.size())
     	{
	     	rectangle(equ,allFace[0], Scalar(255,255,0));
	     	faceImg = equ(allFace[0]);
	     	imencode(".jpg", faceImg, jpgBuf);
	     	
	     	base64Img=base64_encode((char *)jpgBuf.data(), jpgBuf.size());
	     	
            result=client.search(base64Img, "BASE64", "", aip::null);   //第三个参数是百度智能云创建人脸库里的组名
	     	
	     	if(!result["result"].isNull()&&result["result"]["user_list"][0]["score"]>80)
	     	{ 
	     		cout<<result["result"]["user_list"][0]["user_id"]<<endl;
	     		sec = time(NULL);
	     		cout<<ctime(&sec)<<endl;
	     		putText(equ,result["result"]["user_list"][0]["user_id"].asString(),
	     		Point(0,50),FONT_HERSHEY_SIMPLEX,1.0,Scalar(255,255,0));
	     		putText(equ,ctime(&sec),
	     		Point(0,100),FONT_HERSHEY_SIMPLEX,1.0,Scalar(255,255,0));
	     		
	     	}
     	}
     	else
     	{
            cout<<"no face"<<endl;        //未检测到人脸
     	}
     	imshow("video",equ);
     	waitKey(40);
     }

    return 0;
}
