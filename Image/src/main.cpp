#include<iostream>
#include "Image.h"


int main(int argc, char** argv) {
	Image im("../../dither/ressources/lenna.png");

	im.rgb2gray(1);
	im.floyds();
	im.write("fs.jpg");

	return 0;
}




