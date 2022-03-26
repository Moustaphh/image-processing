#include<iostream>
#include<chrono>
#include<opencv2/opencv.hpp>




void fs_dither(cv::Mat &grey){

int thresh=128;// initialize threshold 

int error;

for(int i=1; i<grey.rows-1; i++){
    for(int j=1; j<grey.cols-1; j++){
		//if the value of the pixel is inferior to the threshold, then increase the connected pixels 
		//by the error(difference between the threshold and the pixel). 
		if ((int)grey.at<uchar>(i,j)<thresh){

			error =grey.at<uchar>(i,j);

			grey.at<uchar>(i,j+1)+=(5*error/16);
			grey.at<uchar>(i+1,j-1)+=(3*error/16);
			grey.at<uchar>(i+1,j)+=(7*error/16);
			grey.at<uchar>(i+1,j+1)+=(error/16);

			grey.at<uchar>(i,j)=0;

		//if the value of the pixel is superior to the threshold, then decrease the connected pixels
		//by the error(difference between the threshold and the pixel).
		}else if ((int)grey.at<uchar>(i,j)>thresh){

			error =255-grey.at<uchar>(i,j);

			grey.at<uchar>(i,j+1)-=(5*error/16);
			grey.at<uchar>(i+1,j-1)-=(3*error/16);
			grey.at<uchar>(i+1,j)-=(7*error/16);
			grey.at<uchar>(i+1,j+1)-=(error/16);

			grey.at<uchar>(i,j)=255;
	}

}
}
}

int main(){

cv::Mat grey;

cv::Mat img = cv::imread("../../ressources/lenna.png");//read the file


cv::cvtColor(img,grey,cv::COLOR_BGR2GRAY);//converting to grayscale 

//measuring the time that it took.

auto start = std::chrono::high_resolution_clock::now();

fs_dither(grey);


auto stop = std::chrono::high_resolution_clock::now();
	
auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

std::cout <<"Processing time : " <<duration.count() << "  milliseconds" <<std::endl;

//displaying the result.
cv::imshow("fs dithering ",grey);
cv::waitKey(0);

cv::destroyWindow("fs dithering ");
return 0;
}
