#include <stdint.h>
#include <cstdio>

enum ImageType {
	PNG, JPG, BMP, TGA
};

class Image {
	public:
	uint8_t* data = NULL;

	
	size_t size = 0;
	int w;
	int h;
	int channels;
	// uint8_t* grey2d=NULL;


	Image(const char* filename, int channel_force = 0);
	Image(int w, int h, int channels = 3);
	Image(const Image& img);
	~Image();

	bool read(const char* filename, int channel_force = 0);
	bool write(const char* filename);

	ImageType get_file_type(const char* filename);

	void rgb2gray(int chs);
	void gray2bw();
	uint8_t& at(int j, int i);
	void floyds();
};