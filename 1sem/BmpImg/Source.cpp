#include <iostream>
#include "BmpStructures.h"
#include "ImgFunctions.h"

void generate_gs_img()
{
	GsImg gray;
	gray.height = 51;
	gray.width = 6 * gray.height;
	gray.pixels = new BYTE * [gray.height];
	for (size_t r = 0; r < gray.height; ++r)
	{
		gray.pixels[r] = new BYTE[gray.width];
		for (size_t c = 0; c < gray.width; ++c)
			gray.pixels[r][c] = 255;
	}

	for (size_t bright = 0; bright < 6; ++bright)
		for (size_t r = 0; r < gray.height; ++r)
			for (size_t c = bright * gray.height; c < (bright + 1) * gray.height; ++c)
				gray.pixels[r][c] = bright*51;

	writeGsImg("own_gray.bmp", gray);

	for (size_t r = 0; r < gray.height; ++r)
	{
		delete[] gray.pixels[r];
	}
	delete[] gray.pixels;
}

void generate_gs_gradient()
{
	GsImg gray;
	gray.height = 50;
	gray.width = 256;
	gray.pixels = new BYTE * [gray.height];
	for (size_t r = 0; r < gray.height; ++r)
	{
		gray.pixels[r] = new BYTE[gray.width];
		for (size_t c = 0; c < gray.width; ++c)
			gray.pixels[r][c] = c;
	}

	writeGsImg("gray_gradient.bmp", gray);

	for (size_t r = 0; r < gray.height; ++r)
	{
		delete[] gray.pixels[r];
	}
	delete[] gray.pixels;
}

int main()
{
	/*try
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
	}*/

	generate_gs_img();
	generate_gs_gradient();
	
	std::cout << "Success!\n";
	return 0;
}