#include "classesLesson.h"
#include "newLib.h"


void Entity::Move(int xa, int ya)
{
    x += xa*speed;
    y += ya*speed;
}

void Player::Display()
{
    Log("########################");
    Log("Name: ");
    Log(name);
    Log("X, Y, Speed:");
    PrintItAll(x);
    PrintItAll(y);
    PrintItAll(speed);
}

void Entity::Display()
{
    Log("########################");
    Log("X, Y, Speed:");
    PrintItAll(x);
    PrintItAll(y);
    PrintItAll(speed);
}

void PrintName(Entity* e)
{
    std::cout << e->GetName() << std::endl;
}

void PrintClass(Printable* p)
{
    std::cout << p->GetClassName() << std::endl;
}
