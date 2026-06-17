#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void displayDetails()
    {
        cout << "Shape" << endl;
    }
};

class Circle : public Shape
{
public:
    float radius;

    Circle()
    {
        cout << "Enter Radius: ";
        cin >> radius;
    }

    void displayDetails()
    {
        cout << "\nCircle" << endl;
        cout << "Radius = " << radius << endl;
        cout << "Area = " << 3.14 * radius * radius << endl;
    }
};

class Rectangle : public Shape
{
public:
    float length, width;

    Rectangle()
    {
        cout << "Enter Length: ";
        cin >> length;

        cout << "Enter Width: ";
        cin >> width;
    }

    void displayDetails()
    {
        cout << "\nRectangle" << endl;
        cout << "Length = " << length << endl;
        cout << "Width = " << width << endl;
        cout << "Area = " << length * width << endl;
    }
};

int main()
{
    Circle c;
    Rectangle r;

    Shape *s[2];

    s[0] = &c;
    s[1] = &r;

    cout << "\nDetails of Shapes\n";

    for(int i = 0; i < 2; i++)
    {
        s[i]->displayDetails();
    }

}