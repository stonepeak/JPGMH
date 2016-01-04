#include "cv.h"

#include "highgui.h"

using namespace cv;

using namespace std;

int main() { 

//string name="F:\JPGMH\JPGMH\pcc.jpg"; 

Mat src1= imread( "ppc.jpg" );
//Mat src1=imread(name,1);

Mat img; 
//˫���˲���һ�ֿ���ȥ��ߵ��˲�����֮���Կ��Դﵽ��Ч��������Ϊ�˲�������������������
//һ���������ɼ��οռ��������˲���ϵ������һ�������ز�ֵ�����˲���ϵ��

bilateralFilter(src1,img,5,700,750);//˫���˲�����3������d����˵d>5ʱ����ʵʱ�����������������sigma������һ����ͬ

bilateralFilter(img,src1,5,150,150);//<10ʱ����ûЧ��, >150ʱ����Ч��

imshow("bilateral",src1);

waitKey(0);


Mat src; cvtColor(src1,src,CV_BGR2GRAY); //������ͼ��ת�����Ҷȿռ䣬Խ��Խ�֣����ǻ��д������

/*Mat imgL; //����������ddepth��ʾĿ��ͼ�����ȣ�ddepth=-1ʱ����ԭͼ��һ�� 

Laplacian(src,imgL,-1,3,1);

imshow("Laplacian",imgL);

waitKey(0); //ϸ��*/

Mat imgC;

Canny(src,imgC,0,90);//Canny�ҵ���Ե����㷨�����룬�������ɫ���ȣ�Խ��Խ�ڣ�90ͼ���Ե���ܼ��ȣ�Խ��Խ�ܡ�

imshow("Canny",imgC);//�������ֱ�ʾ��ֵ��������ֵ����Сֵ���Ʊ�Ե���ӣ���ֵ�����Ʊ�Ե�ĳ�ʼ�ָ���

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

