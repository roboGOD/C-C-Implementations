#include <iostream>

class Printable
{
public:
    virtual std::string GetClassName() = 0;
};

class Entity : public Printable
{
public:
    int x, y;
    int speed;
    
    void Move(int xa, int ya);
    
    void Display();
    
    virtual std::string GetName() {return "Entity Object";}
    
    std::string GetClassName() override {return "Entity";}
};

class Player : public Entity
{
private:
    std::string m_name;
public:
    const char * name;
public:
    Player(const std::string& name)
        : m_name(name) {}
    
    std::string GetName() override {return m_name;}
    
    void Display();
    
    std::string GetClassName() override {return "Player";}
};

void PrintName(Entity* e);
void PrintClass(Printable* p);