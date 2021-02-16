#include <iostream>
#include <array>
#include <tuple>
#include <variant>
#include <exception>

std::pair<int, int> arr_arg(std::array<int,3> const& arr)
{
    return std::make_pair(arr[0], arr[2]);
}

std::tuple<int, int, int> arr_to_tuple(std::array<int, 3> const& arr)
{
    return std::make_tuple(arr[0], arr[1], arr[2]);
}

int main()
{
    int arr[3] = { 1,2,3 };

    std::array<int, 3> arr_t = { 1,2,3 };
    std::cout << arr_t.size() << '\n';

    std::array<int, 3> arr_t2 = { 4,5,6 };
    arr_t = arr_t2;
    
    for (size_t idx = 0; idx < arr_t.size(); ++idx)
        std::cout << arr_t[idx] << '\n';

    auto p = arr_arg(arr_t);
    std::cout << p.first << ' ' << p.second << '\n';
    std::cout << std::get<0>(p) << ' ' << std::get<1>(p) << '\n';

    auto t = arr_to_tuple(arr_t2);
    std::cout << std::get<0>(t) << ' ' << std::get<1>(t) << ' ' << std::get<2>(t) << '\n';

    std::variant<int, double, std::array<double,8>> v;
    v = 0.5;
    v = 12;
    
    try
    {
        //std::cout << std::get<1>(v) << '\n';
        std::cout << std::get<int>(v) << '\n';
    }
    catch (std::bad_variant_access const& e)
    {
        std::cout << "error: " << e.what() << '\n';
    }

    return 0;
}