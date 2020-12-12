#include <iostream>

enum class DayOfWeek { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

const char* day_names[] = {
    "Monday",
    "Tuesday", 
    "Wednesday", 
    "Thursday", 
    "Friday", 
    "Saturday", 
    "Sunday"
};

void print_day_of_week(DayOfWeek day)
{
    //switch (day)
    //{
    //    case DayOfWeek::Monday:
    //        std::cout << "Monday\n";
    //        break;
    //    case DayOfWeek::Tuesday:
    //        std::cout << "Tuesday\n";
    //        break;
    //    //...
    //}
    std::cout << day_names[(size_t)day] << '\n';
}

struct Test
{
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char bit4 : 1;
    unsigned char bit5 : 1;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
    unsigned char bit8 : 1;
};

enum class ParameterType {Double = 1, Int, Char};

union ParameterValue
{
    double x;
    int y;
    char z;
};

struct Parameter
{
    ParameterType type;
    ParameterValue value;
};

int main()
{
    DayOfWeek day = DayOfWeek::Friday;
    print_day_of_week(day);
    print_day_of_week((DayOfWeek)0);

  /*  Test t = { 1,2 };
    Test* ptr = &t;
    (*ptr).val1 = 50;
    ptr->val1 = 6;*/
    unsigned char x = 0b00001001;
    Test* ptr = (Test*)&x;
    std::cout << (int)ptr->bit1 << ' ' << (int)ptr->bit2 << ' ' << (int)ptr->bit3 << ' ' << (int)ptr->bit4 << '\n';
    //std::cout << sizeof(Test) << '\n';

    Parameter p;
    p.type = ParameterType::Int;
    p.value.y = 2;

    union {
        int val1;
        double val2;
    };

    val1 = 2;
    val2 = 0.5;
    val1 = 3;

    return 0;
}