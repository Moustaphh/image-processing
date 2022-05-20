#include"Image.h"

    
void Image::floyds(){
		int thresh=128;// initialize threshold 

		int error;

		for(int i=1; i<h-1; i++){
			for(int j=1; j<w-1; j++){
				//if the value of the pixel is inferior to the threshold, then increase the connected pixels 
				//by the error(difference between the threshold and the pixel). 

				if (at(i,j)<thresh){

					error =at(i,j);

					at(i,j+1)+=(5*error/16);
					at(i+1,j-1)+=(3*error/16);
					at(i+1,j)+=(7*error/16);
					at(i+1,j+1)+=(error/16);

					at(i,j)=0;

				//if the value of the pixel is superior to the threshold, then decrease the connected pixels
				//by the error(difference between the threshold and the pixel).
				}else if (at(i,j)>thresh){

					error =255-at(i,j);

					at(i,j+1)-=(5*error/16);
					at(i+1,j-1)-=(3*error/16);
					at(i+1,j)-=(7*error/16);
					at(i+1,j+1)-=(error/16);
					at(i,j)=255;	
		}
	}
	}
	}