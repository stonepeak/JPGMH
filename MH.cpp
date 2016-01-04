#include "cv.h"

#include "highgui.h"

using namespace cv;

using namespace std;

int main() { 

//string name="F:\JPGMH\JPGMH\pcc.jpg"; 

Mat src1= imread( "ppc.jpg" );
//Mat src1=imread(name,1);

Mat img; 
//双边滤波是一种可以去噪边的滤波器。之所以可以达到此效果，是因为滤波器是由俩个函数构成
//一个函数是由几何空间距离决定滤波器系数，另一个由像素差值决定滤波器系数

bilateralFilter(src1,img,5,700,750);//双边滤波，第3个参数d可以说d>5时不能实时处理，最后两个参数是sigma参数，一般相同

bilateralFilter(img,src1,5,150,150);//<10时基本没效果, >150时漫画效果

imshow("bilateral",src1);

waitKey(0);


Mat src; cvtColor(src1,src,CV_BGR2GRAY); //将输入图像转换到灰度空间，越大越粗，但是会有大量噪点

/*Mat imgL; //第三个参数ddepth表示目标图像的深度，ddepth=-1时，与原图像一致 

Laplacian(src,imgL,-1,3,1);

imshow("Laplacian",imgL);

waitKey(0); //细线*/

Mat imgC;

Canny(src,imgC,0,90);//Canny找到边缘检测算法。输入，输出，黑色填充度，越大越黑，90图像边缘的密集度，越大越密。

imshow("Canny",imgC);//俩个数字表示阀值，俩个阀值当中小值控制边缘连接，大值来控制边缘的初始分割线

waitKey(0);

/*Mat imgS,imgSx,imgSy,imgS0;

Sobel(src,imgSx,-1,0,1);

Sobel(src,imgSx,-1,1,0);

imgS=imgSx+imgSy;

Sobel(src,imgS0,-1,1,1);

//imshow("Sobel0",imgS0);

//imshow("Sobel",imgS);

waitKey(0);


Mat imgTotal;

imgTotal=imgC//+imgS+imgL; //imgTotal.convertTo(imgTotal,CV_32FC1); 

normalize(imgTotal,imgTotal,255,0,CV_MINMAX); 

GaussianBlur(imgTotal,imgTotal,Size(3,3),3); 

threshold(imgTotal,imgTotal,100,255,THRESH_BINARY_INV);

imshow("Total",imgTotal);

waitKey(0); 
*/
}

