#include <iostream>
#include "BmpStructures.h"
#include "ImgFunctions.h"

int main()
{
	try
	{
		RgbImg img = read_rgb_img("test.bmp");
	
		for (int i = 0; i < 100; ++i)
			for (int j = 0; j < 100; ++j)
				img.pixels[i][j] = { 0, 0, 0 };
	
		write_rgb_img("out.bmp", img);
		for (int i = 0; i < img.height; ++i)
			delete[] img.pixels[i];
		delete[] img.pixels;
	}
	catch (std::exception error)
	{
		std::cout << "Error happened: " << error.what() << '\n';
		return 1;
	}
	std::cout << "Success!\n";
	return 0;
}