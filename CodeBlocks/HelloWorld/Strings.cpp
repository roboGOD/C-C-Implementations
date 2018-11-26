#include <iostream>
#include <string>

void PrintString(const std::string& message)
{
    std::cout << message << std::endl; 
}


void doStringOps()
{
    const char name[6] = {'J', 'o', 'k', 'e', 'R', '\0'};
    const char* name2 = "roboGOD";
    std::string name3 = "H.B";
    PrintString(name);
    PrintString(name2);
    PrintString(name3);
    
    name3.append("hullar");
    PrintString(name3);
    
    std::cout << "Size: " << name3.size() << std::endl;
    std::cout << "Capacity: " << name3.capacity() << std::endl;
    
    std::cout << std::endl;
    
    name3.assign("> Harnoor Bhullar <");
    PrintString(name3);
    std::cout << "Size: " << name3.size() << std::endl;
    std::cout << "Capacity: " << name3.capacity() << std::endl;
}





