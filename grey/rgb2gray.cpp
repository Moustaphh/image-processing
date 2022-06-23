#include"Image.h"
#include<algorithm>

#include<string.h>

void Image::rgb2gray(int chs){
		uint8_t *grey2d=new uint8_t[w*h];

	if (channels<2){ printf("the image is already grey \n" );
	}else{
		int count=0;
	for( int i=0;i<size;i+=channels){
		count++;

		int grey= 0.2426*data[i]+0.7152*data[i+1]+0.0722*data[i+2];

		if(chs==3){

		memset(data+i,grey,3);
		}else{
		memset(grey2d+count,grey,1);}

	}
	if(chs==1){
	
			std::swap(data,grey2d);
			size=w*h;
			channels=1;
            delete[] grey2d;
            
		}

}
	}