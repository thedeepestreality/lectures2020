#pragma once
#include "BmpStructures.h"

RgbImg readRgbImg(char const* filename);
void writeRgbImg(char const* filename, RgbImg const& img);
void writeGsImg(char const* filename, GsImg const& img);
void printImgInfo(char const* filename);