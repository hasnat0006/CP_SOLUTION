#include <iostream>
using namespace std;

class A
{
    int a1;

protected:
    int a2;

public:
    string a3;
    A() {}
    A(int a1, int a2, string a3) { this->a1 = a1, this->a2 = a2, this->a3 = a3; }
    virtual double fa() {}
    int getA1() { return a1; }
    virtual void display()
    {
        cout << "A1: " << a1 << endl;
        cout << "A2: " << a2 << endl;
        cout << "A3: " << a3 << endl;
    }
};
class B : virtual public A
{
    double b1;
    double fb() { return b1 + b2; }

protected:
    int b2;

public:
    B() {}
    B(int a1, int a2, string a3, int b1, int b2) : A(a1, a2, a3) { this->b1 = b1, this->b2 = b2; }
    void display()
    {
        A::display();
        cout << "B1: " << b1 << endl;
        cout << "B2: " << b2 << endl;
    }
    double fa() { return getA1() + a2 + b1 + b2; }
    double fbb() { return fb(); }
};

class F : virtual public A
{
protected:
    float f1;

public:
    F() {}
    F(int a1, int a2, string a3, float f1) : A(a1, a2, a3) { this->f1 = f1; }
    double ff() { return f1 + getA1() + a2; }
};
class G : public B, private F
{
public:
    char g;
    G() {}
    G(char g, int a1, int a2, string a3, float f1, int b1, int b2) : B(a1, a2, a3, b1, b2), F(a1, a2, a3, f1), A(a1, a2, a3)
    {
        this->g = g;
    }
    double ff() { return f1 + getA1() + a2 + (int)g; }
};
class C : virtual public B
{
public:
    int c1;
    C() {}
    C(int c1, int a1, int a2, string a3, int b1, int b2) : B(a1, a2, a3, b1, b2) { this->c1 = c1; }
};
class D : virtual public B
{
public:
    int d1;
    D() {}
    D(int d1, int a1, int a2, string a3, int b1, int b2) : B(a1, a2, a3, b1, b2) { this->d1 = d1; }
};
class E : public C, public D
{
public:
    int e1;
    E() {}
    E(int e1, int c1, int d1, int a1, int a2, string a3, int b1, int b2) : C(c1, a1, a2, a3, b1, b2), D(d1, a1, a2, a3, b1, b2), B(a1, a2, a3, b1, b2) { this->e1 = e1; }
};

int main()
{
    //!  e1, c1, d1, a1, a2, a3,     b1, b2
    E E1(10, 20, 30, 40, 50, "MIST", 60, 70);
    // create an object of class E

    // A A1(40, 50, "HASNAT");
    // create an object of class A
    //! a1,   a2,   a3,      b1,   b2
    B B1(400, 500, "TOMAL", 6000, 7000);
    // create an object of class B

    // C C1(...);
    // create an object of class C
    //!   g1,  a1 ,  a2 ,   a3     ,  f1 ,   b1,  b2
    G G1('%', 4000, 5000, "Pallob", 105.105, 600, 700);
    // create an object of class G

    cout << "FB: " << G1.fbb() << endl; // make sure this works

    cout << "FF: " << G1.ff() << endl; // or appropriate delegate function

    A *ptr;
    ptr = &B1;

    ptr->display();
    // op. overloading
}
