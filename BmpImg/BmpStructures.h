#ifndef BMPSTRUCTURES_H
#define BMPSTRUCTURES_H

typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef int LONG;
typedef unsigned char BYTE;

//Следующая строчка отменяет выравнивание
//типов данных для структур
#pragma pack(push,1)
struct BITMAPFILEHEADER {
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
};

struct BITMAPINFOHEADER {
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
};

struct RGBQUAD {
  BYTE rgbBlue;
  BYTE rgbGreen;
  BYTE rgbRed;
  BYTE rgbReserved;
};

struct COMPRESSEDHEADER
{
	WORD biWidth;
	WORD biHeight;
};

struct BMRUN
{
	WORD rWidth;
	BYTE rClr;
};

struct RGB
{
	BYTE Blue;
	BYTE Green;
	BYTE Red;
};

struct RgbImg
{
	RGB** pixels;
	unsigned int width;
	unsigned int height;
};
//А эта строчка отменяет отмену выравнивания :)
#pragma pack(pop)

#endif