#include <iostream>

class Shape
{
public:
    Shape() { std::cout << "Shape is created\n"; }
    virtual void show() const = 0;
    virtual void hide() const = 0;
    virtual ~Shape() { std::cout << "Shape is deleted\n"; }
};

class Point : public Shape
{
protected:
    int _x, _y;
public:
    Point(int const kX = 0, int const kY = 0) : _x(kX), _y(kY)
    {
        std::cout << "Point is created\n";
    }
    void show() const override { std::cout << "Point is shown\n"; }
    void hide() const override { std::cout << "Point is hidden\n"; }
    ~Point() { std::cout << "Point is deleted\n"; }
};

class Circle : public Point
{
protected:
    int _rad;
public:
    Circle( int const kX = 0, 
            int const kY = 0, 
            int const kRad = 1) : Point(kX, kY), _rad(kRad)
    {
        std::cout << "Circle is created\n";
    }
    void show() const override { std::cout << "Circle is shown\n"; }
    void hide() const override { std::cout << "Circle is hidden\n"; }
    ~Circle() { std::cout << "Circle is deleted\n"; }
};

class Rectangle : public Point
{
protected:
    int _width, _height;
public:
    Rectangle(  const int kX = 0,
                const int kY = 0,
                const int kWidth = 1,
                const int kHeight = 1) : Point(kX, kY), _width(kWidth), _height(kHeight)
    {
        std::cout << "Rectangle is created\n";
    }
    void show() const override { std::cout << "Rectangle is shown\n"; }
    void hide() const override { std::cout << "Rectangle is hidden\n"; }
    ~Rectangle() { std::cout << "Rectangle is deleted\n"; }
};

class Square: public Rectangle
{
public:
    Square( const int kX = 0,
            const int kY = 0,
            const int kSide = 1) : Rectangle(kX, kY, kSide, kSide)
    {
        std::cout << "Square is created\n";
    }
    void show() const override { std::cout << "Square is shown\n"; }
    void hide() const override { std::cout << "Square is hidden\n"; }
    ~Square() { std::cout << "Square is deleted\n"; }
};

void render(Shape* shapes[], size_t const kSize)
{
    for (size_t idx = 0; idx < kSize; ++idx)
        shapes[idx]->show();
}

int main()
{
    size_t const kSize = 3;
    Shape* shapes[kSize] = { new Circle(1,1,5), new Square(0,0,3), new Point(-3,2) };
    render(shapes, kSize);
    return 0;
}