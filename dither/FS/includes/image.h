#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>

struct Image
{
    unsigned int rows;//number of rows 
    unsigned int cols;// number of cols 
    unsigned int maxVal;// maximum greyscale value

    std::string format;//format of the file 
    std::string comment;// comment of the file 

    std::vector<short> greyvalues; //save all the greyvalues  in a vector

};

//read the image 
Image read(const std::string filename);



//as for grey values at specific position of the file 
short getVal(const Image, unsigned int row , unsigned int col);

//set greyvalues 

void setVal(const Image, unsigned int row , unsigned int col,short val);
// save the image

int write(const Image,const std::string name);