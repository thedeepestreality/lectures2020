#include <iostream>

double segment_length(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

struct Point
{
    double x;
    double y;
};

double segment_length(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

struct Segment
{
    Point p1;
    Point p2;
};

double segment_length(Segment seg)
{
    double x1 = seg.p1.x;
    double y1 = seg.p1.y;
    double x2 = seg.p2.x;
    double y2 = seg.p2.y;
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

#pragma pack(1)
struct Test
{
    double x;
    int y;
};
#pragma pop

int main()
{
    Segment seg;
    seg.p1.x = 0;
    seg.p1.y = 0;
    seg.p2.x = 1;
    seg.p2.y = 1;
    std::cout << segment_length(seg) << std::endl;
    double* d_ptr = (double*)&seg;
    std::cout << d_ptr[2] << std::endl;
    std::cout << "Seg size: " << sizeof(seg) << std::endl;
    std::cout << "Seg size: " << sizeof(Test) << std::endl;

    return 0;
}