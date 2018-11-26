#include "newLib.h"
#include "classesLesson.h"
#include "Vector.h"
#include "FunctionPointer.h"

int globalVariable = 29;
//static int staticVariable = 20;

int main()
{
    Log("I AM BATMAN!!");
    /*
    int a = getInt("Enter first number");
    int b = getInt("Enter second number");
    Log(mul(a, b));
    
    // References
    int c = getInt("Enter another number");
    inc(c);
    PrintItAll(c);
    
    // Class Lesson
    Player p1;
    p1.x = 10;
    p1.y = 20;
    p1.speed = 2;
    p1.name = "roboGOD";
    p1.Display();
    
    p1.Move(2,-4);
    p1.Display();

    
    // Static and Extern
    Log("#########################");
    Log("Extern Variable:");
    PrintItAll(globalVariable);
    Log("Static Variable:");
    PrintItAll(staticVariable);
    
    
    // Virtual Functions
    Entity* e = new Entity();
    PrintName(e);
    PrintClass(e);
    
    Player* p = new Player("roboGOD");
    PrintName(p);
    PrintClass(p);
    */
    
    
    // Strings
    //doStringOps();
    
    
    // Vector Class
    /*
    Log("#####____ VECTORS ____#####");
    Vector v;
    std::cout << "Capacity: " <<v.capacity() << std::endl;
    for(int i=0; i<20; i++)
        v.append(i);
        
    std::cout << v << std::endl;
    std::cout << "Capacity: " << v.capacity() << std::endl;
        
    int a = v[0];
    a++;
    v[0] = 200;
    v[1] = 300;
    std::cout << v[40] << std::endl;
    std::cout << a << std::endl;
    std::cout << v << std::endl;

    v.insert(0, 500);
    v.insert(v.size(), 350);
    v.insert(10, 999);
    
    std::cout << v << std::endl;
    
    */
    
    // Standard Arrays, Function Pointers and Lambdas
    DoFuncPointer();
    
    
	Wait;
}