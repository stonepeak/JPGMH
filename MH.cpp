#include "cv.h"

#include "highgui.h"

using namespace cv;

using namespace std;

int main() { 

string name="F:\JPGMH\JPGMH\pcc.jpg"; 

Mat src1= imread( "ppc.jpg" );
//Mat src1=imread(name,1);

Mat img; 

//双边滤波，第3个参数d可以说d>5时不能实时处理，最后两个参数是sigma参数，一般相同

//<10时基本没效果, >150时漫画效果

bilateralFilter(src1,img,5,150,150);

bilateralFilter(img,src1,5,150,150); //img.copyTo(src1);

//imshow("bilateral",src1);

waitKey(0);


Mat src; cvtColor(src1,src,CV_BGR2GRAY); //粗线，越大越粗，但是会有大量噪点

Mat imgL; //第三个参数ddepth表示目标图像的深度，ddepth=-1时，与原图像一致 

Laplacian(src,imgL,-1,3,1);

//imshow("Laplacian",imgL);

waitKey(0); //细线

Mat imgC;

Canny(src,imgC,30,90);

//imshow("Canny",imgC);

waitKey(0);

Mat imgS,imgSx,imgSy,imgS0;

Sobel(src,imgSx,-1,0,1);

Sobel(src,imgSx,-1,1,0);

imgS=imgSx+imgSy;

Sobel(src,imgS0,-1,1,1);

//imshow("Sobel0",imgS0);

//imshow("Sobel",imgS);

waitKey(0);


Mat imgTotal;

imgTotal=imgC+imgS+imgL; //imgTotal.convertTo(imgTotal,CV_32FC1); 

normalize(imgTotal,imgTotal,255,0,CV_MINMAX); 

GaussianBlur(imgTotal,imgTotal,Size(3,3),3); 

threshold(imgTotal,imgTotal,100,255,THRESH_BINARY_INV);

imshow("Total",imgTotal);

waitKey(0); 

Mat imgTotalC3; 

cvtColor(imgTotal,imgTotalC3,CV_GRAY2BGR);

bitwise_and(src1,imgTotalC3,src1); 

//imshow("Result",src1);

waitKey(0);

name.insert(11,"_edge");

imwrite(name,src1);

}

