#include <iostream>
using namespace std;

class Shape
{
private:
    string color;
    float area;

public:
    void setColor(string c)
    {
        color = c;
    }

    string getColor()
    {
        return color;
    }

    void setArea(float a)
    {
        area = a;
    }

    float getArea()
    {
        return area;
    }
};

class Circle : public Shape
{
private:
    float radius;

public:
    void input()
    {
        cout << "Enter Circle Color: ";
        cin >> ws;
        getline(cin, color);

        setColor(color);

        cout << "Enter Radius: ";
        cin >> radius;
    }

    void calculateArea()
    {
        float area = 3.14 * radius * radius;
        setArea(area);
    }

private:
    string color;
};

class Rectangle : public Shape
{
private:
    float length, width;

public:
    void input()
    {
        cout << "\nEnter Rectangle Color: ";
        cin >> ws;
        getline(cin, color);

        setColor(color);

        cout << "Enter Length: ";
        cin >> length;

        cout << "Enter Width: ";
        cin >> width;
    }

    void calculateArea()
    {
        float area = length * width;
        setArea(area);
    }

    void display()
    {
        cout << "\nRectangle Color : " << getColor() << endl;
        cout << "Rectangle Area  : " << getArea() << endl;
    }

private:
    string color;
};

int main()
{
    Circle c;
    Rectangle r;

    c.input();
    c.calculateArea();

    cout << "\nCircle Color : " << c.getColor() << endl;
    cout << "Circle Area  : " << c.getArea() << endl;

    r.input();
    r.calculateArea();
    r.display();

}