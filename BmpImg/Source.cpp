#include <iostream>
#include "BmpStructures.h"
#include "ImgFunctions.h"

int main()
{
	RgbImg img = read_rgb_img("test.bmp");
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			img.pixels[i][j] = { 0,0,0 };
	//(R+G+B)/3
	write_rgb_img("out.bmp", img);
	system("pause");
	return 0;
}