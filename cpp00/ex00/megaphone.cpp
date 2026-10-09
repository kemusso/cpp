#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if(argc <= 0)
        return 1;
    else if(argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for(int i = 1;i < argc;i++)
    {
        for(int j = 0;argv[i][j] != '\0';j++)
        {
            if(argv[i][j] >= 97 && argv[i][j] <= 122)
                argv[i][j] -= 32;
            std::cout << argv[i][j];
        }
    }
    std::cout << std::endl;
    return 0;
}