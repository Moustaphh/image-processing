#include<iostream>
#include "Image.h"


int main(int argc, char** argv) {
	Image im("../../dither/ressources/lenna.png");

	im.rgb2gray(1);
	
	// im.gray2bw();
	// im.floyds()
	im.write("grey.jpg");

	return 0;
}




