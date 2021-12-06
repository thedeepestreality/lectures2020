#include "ImgFunctions.h"
#include <fstream>
#include <exception>
#include <iostream>

int getOffset(int width)
{
    int offset = 0;
    if (width % 4)
        offset = 4 - (3 * width) % 4;
    return offset;
}

RgbImg readRgbImg(const char* filename)
{
    std::ifstream bmp_in(filename, std::ios::binary);
    if (!bmp_in.is_open())
        throw std::runtime_error("Failed to open input file");

    BITMAPFILEHEADER bmfh;
    BITMAPINFOHEADER bmih;

    bmp_in.read((char*)&bmfh, sizeof(BITMAPFILEHEADER));
    bmp_in.read((char*)&bmih, sizeof(BITMAPINFOHEADER));

    const int offset = getOffset(bmih.biWidth);

    RgbImg img;
    img.height = bmih.biHeight;
    img.width = bmih.biWidth;
    img.pixels = new RGB * [img.height];

    for (size_t row = 0; row < img.height; ++row)
    {
        img.pixels[row] = new RGB[img.width];
        for (size_t col = 0; col < img.width; ++col)
            bmp_in.read((char*)&img.pixels[row][col], 3);
        bmp_in.seekg(offset, std::ios::cur);
    }

    bmp_in.close();
    return img;
}

void writeRgbImg(char const* filename, RgbImg const& img)
{
    std::ofstream bmp_out(filename, std::ios::binary);
    if (!bmp_out.is_open())
        throw std::runtime_error("Failed to open output file");

    const int offset = getOffset(img.width);

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

    BYTE* offset_array = new BYTE[offset];
    for (int i = 0; i < offset; ++i)
        offset_array[i] = 0;

    for (size_t row = 0; row < img.height; ++row)
    {
        for (size_t col = 0; col < img.width; ++col)
            bmp_out.write((char*)&img.pixels[row][col], 3);
        bmp_out.write((char*)offset_array, offset);
    }

    delete[] offset_array;
    bmp_out.close();
}

void writeGsImg(char const* filename, GsImg const& img)
{
    std::ofstream bmp_out(filename, std::ios::binary);
    if (!bmp_out.is_open())
        throw std::runtime_error("Failed to open output file");

    const int offset = getOffset(img.width);

    BITMAPFILEHEADER bmfh;
    char bfType[] = { 'B', 'M' };
    bmfh.bfType = *((WORD*)bfType); // ('M' << 8) | 'B';
    bmfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    bmfh.bfSize = bmfh.bfOffBits + img.height * img.width + 256*4;
    bmfh.bfReserved1 = bmfh.bfReserved2 = 0;

    BITMAPINFOHEADER bmih;
    bmih.biClrImportant = bmih.biClrUsed = 256;
    bmih.biCompression = 0;
    bmih.biPlanes = bmih.biXPelsPerMeter = bmih.biYPelsPerMeter = 1;
    bmih.biSize = sizeof(BITMAPINFOHEADER);
    bmih.biSizeImage = bmfh.bfSize - bmfh.bfOffBits;
    bmih.biHeight = img.height;
    bmih.biWidth = img.width;
    bmih.biBitCount = 8;

    RGBQUAD grayscale[256];
    BYTE idx = 0;
    do {
        grayscale[idx] = { idx, idx, idx, 0 };
    } while (++idx != 0);

    bmp_out.write((char*)&bmfh, sizeof(BITMAPFILEHEADER));
    bmp_out.write((char*)&bmih, sizeof(BITMAPINFOHEADER));
    bmp_out.write((char*)grayscale, 256 * 4);

    BYTE* offset_array = new BYTE[offset];
    for (int i = 0; i < offset; ++i)
        offset_array[i] = 0;

    for (size_t row = 0; row < img.height; ++row)
    {
        for (size_t col = 0; col < img.width; ++col)
            bmp_out.write((char*)&img.pixels[row][col], 1);
        bmp_out.write((char*)offset_array, offset);
    }

    delete[] offset_array;
    bmp_out.close();
}

void printImgInfo(const char* filename)
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
