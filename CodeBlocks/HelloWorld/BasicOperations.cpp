#include <iostream>

extern int globalVariable;

void Log(const char* message)
#include "StartBrace.h"
	std::cout << message << std::endl;
}

void Log(int m)
{
    std::cout << m << std::endl;
}

int getInt(const char* message)
{
    int a;
    std::cout<<message<<": ";
    std::cin>>a;
    return a;
}

int mul(int a, int b)
{
	return a*b;
}

void inc(int& a)
{
    a += globalVariable;
}