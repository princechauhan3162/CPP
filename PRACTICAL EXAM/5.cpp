#include <iostream>
using namespace std;

class Vehicle
{
public:
    virtual void startEngine() = 0;
    virtual void drive() = 0;
};

class Car : public Vehicle
{
public:
    void startEngine()
    {
        cout << "Car Engine Started" << endl;
    }

    void drive()
    {
        cout << "Car is Running" << endl;
    }
};

class Bike : public Vehicle
{
public:
    void startEngine()
    {
        cout << "Bike Engine Started" << endl;
    }

    void drive()
    {
        cout << "Bike is Running" << endl;
    }
};

int main()
{
    Car c;
    Bike b;

    Vehicle *v[2];

    v[0] = &c;
    v[1] = &b;

    for(int i = 0; i < 2; i++)
    {
        v[i]->startEngine();
        v[i]->drive();
        cout << endl;
    }

}