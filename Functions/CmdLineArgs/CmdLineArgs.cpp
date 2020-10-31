#include <iostream>

int main(int argc, char* argv[], char* env[])
{
    std::cout << "Argc = " << argc << '\n';
    for (int i = 0; i < argc; ++i)
    {
        std::cout << argv[i] << ' ';
        if (i > 0)
        {
            int val = atoi(argv[i]);
            //double val = atof(argv[i]);
            std::cout << val * val;
        }
        std::cout << '\n';
    }

    std::cout << "Env vars: \n";
    int idx = 0;
    while (env[idx])
        std::cout << env[idx++] << '\n';

    return 0;
}