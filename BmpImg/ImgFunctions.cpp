#include "ImgFunctions.h"
#include <fstream>
#include <exception>
#include <iostream>

RgbImg read_rgb_img(const char filename[])
{
    std::ifstream bmp_in(filename, std::ios::binary);
    if (!bmp_in.is_open())
        throw std::runtime_error("Failed to open input file");

    BITMAPFILEHEADER bmfh;
    BITMAPINFOHEADER bmih;

    bmp_in.read((char*)&bmfh, sizeof(BITMAPFILEHEADER));
    bmp_in.read((char*)&bmih, sizeof(BITMAPINFOHEADER));

    RgbImg img;
    img.height = bmih.biHeight;
    img.width = bmih.biWidth;
    img.pixels = new RGB * [img.height];

    for (size_t row = 0; row < img.height; ++row)
    {
        img.pixels[row] = new RGB[img.width];
        for (size_t col = 0; col < img.width; ++col)
            bmp_in.read((char*)&img.pixels[row][col], 3);
    }

    bmp_in.close();
    return img;
}

void write_rgb_img(char const filename[], RgbImg const& img)
{
    std::ofstream bmp_out(filename, std::ios::binary);
    if (!bmp_out.is_open())
        throw std::runtime_error("Failed to open output file");

    BITMAPFILEHEADER bmfh;
    char bfType[] = { 'B', 'M' };
    bmfh.bfType = *((WORD*)bfType); // ('M' << 8) | 'B';
    bmfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    bmfh.bfSize = bmfh.bfOffBits + img.height * img.width * 3;
    bmfh.bfReserved1 = bmfh.bfReserved2 = 0;

    BITMAPINFOHEADER bmih;
    bmih.biClrImportant = bmih.biClrUsed = bmih.biCompression = 0;
    bmih.biPlanes = bmih.biXPelsPerMeter = bmih.biYPelsPerMeter = 1;
    bmih.biSize = sizeof(BITMAPINFOHEADER);
    bmih.biSizeImage = bmfh.bfSize - bmfh.bfOffBits;
    bmih.biHeight = img.height;
    bmih.biWidth = img.width;
    bmih.biBitCount = 24;

    bmp_out.write((char*)&bmfh, sizeof(BITMAPFILEHEADER));
    bmp_out.write((char*)&bmih, sizeof(BITMAPINFOHEADER));

    for (size_t row = 0; row < img.height; ++row)
    {
        for (size_t col = 0; col < img.width; ++col)
            bmp_out.write((char*)&img.pixels[row][col], 3);
    }

    bmp_out.close();
}

void print_rgb_img_info(const char filename[])
{
    std::ifstream bmp_in(filename, std::ios::binary);
    if (!bmp_in.is_open())
        throw std::runtime_error("Failed to open input file");

    BITMAPFILEHEADER bmfh;
    BITMAPINFOHEADER bmih;

    bmp_in.read((char*)&bmfh, sizeof(BITMAPFILEHEADER));
    bmp_in.read((char*)&bmih, sizeof(BITMAPINFOHEADER));

    std::cout << bmfh.bfSize << std::endl;
    std::cout << bmfh.bfOffBits << std::endl;

    std::cout << bmih.biSize << std::endl;
    std::cout << bmih.biHeight << std::endl;
    std::cout << bmih.biWidth << std::endl;
    std::cout << bmih.biSizeImage << std::endl;

    bmp_in.close();
}
