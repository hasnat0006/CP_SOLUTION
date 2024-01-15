#include <bits/stdc++.h>
using namespace std;
class Shape
{
public:
    virtual int getArea() = 0;
};
class triangle : public Shape
{
public:
    int height, width;
    int getArea() { return 0.5 * height * width; }
};
class circle : public Shape
{
public:
    int r;
    int getArea() { return 3.1416 * r * r; }
};
void print(Shape *obj)
{
    cout << obj->getArea() << endl;
}
int main()
{
    triangle t;
    t.height = 10;
    t.width = 20;
    print(&t);
    circle c;
    c.r = 5;
    print(&c);
}