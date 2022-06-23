#include"Image.h"




void Image::gray2bw(){
    
    int min_val=255; 
    int max_val=0; 
    int thresh; 

    //this loop finds the max and min.

    for(int i=0;i<size;i++){
        if(data[i]<min_val){
            min_val=data[i];
        }
        if( data[i]>max_val){
            max_val=data[i];
        }
    }
    thresh= min_val+((max_val-min_val)/2);//the average value will be the threshold

    //this loop does the thresold, it sets tha values that are bigger than the thresh to 255 and the others to 0.
    for( int j=0 ; j<size; j++){
        if(data[j]>thresh){
            data[j]=255;
        }else{
            data[j]=0;
        }
    }
}