#include <iostream>


namespace first
{
    int value =1;
}

namespace second
{
    int value =2;
}

int main()
{
    std::cout<<first::value;
    std::cout<<second::value;
}