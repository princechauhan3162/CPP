#include <iostream>
using namespace std;

class Laptop
{
private:
    string name;
    float price;
    string processor;

public:
    Laptop(string n, float p, string pro)
    {
        name = n;
        price = p;
        processor = pro;
    }
    void display()
    {
        cout << "Laptop Name : " << name << endl;
        cout << "Price       : " << price << endl;
        cout << "Processor   : " << processor << endl;
    }
};
int main()
{
    Laptop l("HP", 55000, "Intel i5");

    cout << "Laptop Details" << endl;
    l.display();
}