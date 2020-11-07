#include <iostream>
#include <fstream>
#include <exception>

void char_str_to_file(  const char* filename,
                        char** lines,
                        size_t size)
{
    std::ofstream out_file;
    out_file.open(filename);
    if (!out_file.is_open())
        throw std::runtime_error("failed to open file");
    out_file << size << '\n';
    for (size_t idx = 0; idx < size; ++idx)
        out_file << lines[idx] << '\n';
    out_file.close();
}

char** char_str_from_file(const char* filename,
                            size_t& size)
{
    std::ifstream in_file(filename);
    if (!in_file.is_open())
        throw std::runtime_error("failed to open in file");
    in_file >> size;
    char** lines = new char* [size];
    for (size_t idx = 0; idx < size; ++idx)
    {
        lines[idx] = new char[32];
        in_file >> lines[idx];
    }

    in_file.close();
    return lines;
}

int main(int argc, char* argv[])
{
    //std::ofstream out_file("out.txt");
   // out_file.open("C:\\repos\\out.txt");
   // out_file.open(R"(C:\repos 1\out.txt)");
    char_str_to_file("out.txt", argv, argc);
    size_t size;
    char** lines = char_str_from_file("in.txt", size);
    char_str_to_file("out2.txt", lines, size);

    for (size_t idx = 0; idx < size; ++idx)
        delete[] lines[idx];
    delete[] lines;

    return 0;
}