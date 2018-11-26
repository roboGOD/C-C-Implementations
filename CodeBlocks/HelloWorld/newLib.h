// You can use pragma once to apply the constraint
// So that header file is included only once
//#pragma once

#ifndef NEWLIB_H
#define NEWLIB_H

extern int globalVariable;

#include <iostream>
#define PrintItAll(x) std::cout <<x << std::endl
#define Wait std::cin.get()

// Basic Operations
int getInt(const char* message);
void Log(const char* message);
void Log(int message);
int mul(int a, int b);
void inc(int& a);


//From Strings
void PrintString(const std::string& message);
void doStringOps();


#endif
