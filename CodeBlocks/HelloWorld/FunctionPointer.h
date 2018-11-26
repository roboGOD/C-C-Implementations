#include <iostream>
#include <array>
typedef void(*FP)(int);

void ForEach(std::array<int, 5> arr, FP func)
{
    std::cout << "Printing List" << std::endl;
    for(int value: arr)
        func(value);
}

void DoFuncPointer()
{
    std::array<int, 5> arr = {2,4,6,8,10};
    auto lambda = [](int val){std::cout<<"Value : " << val << std::endl;};
    ForEach(arr, lambda);
}





