#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
typedef long long int ll;
typedef vector<int> vc;
typedef pair<int, int> pr;
/*
    Inheritance:
        to extend the features of base class to derived class is called inhertance.

*/
class Base
{
public:
    int x = 0;
    void printx() { cout << x << " "; }
};
class Derived : public Base
{
public:
    int y = 0;
    void printall() { cout << x << " " << y << endl; }
};
//Constructer in Inheritance
class Parant
{
public:
    Parant() { cout << "Default constructer of Parant\n"; }
    Parant(int v) { cout << "Parameterized constructer of Parant " << v << endl; }
};
class Child : public Parant
{
public:
    Child() { cout << "Default constructer of Child\n"; }
    Child(int v) { cout << "Parameterized constructer of Child " << v << endl; }
    Child(int u, int v) : Parant(u)
    {
        cout << "Parameterized constructer of Child " << v << endl;
    }
};
//Types of Inhertance
//Simple / SIngle Inheritance
class Ractangle
{
};
class Cubid : public Ractangle
{
};
//Hierarchical Inheritance
class Car //act as a generalized class
{
};
class Skoda : public Car
{
};
class Tyota : public Car
{
};
class Maruti : public Car
{
};
//Multi-Level Inheritance
class Point
{
};
class Circle : public Point
{
};
class Cylender : public Circle
{
};
//Multiple Inhertance
class Camera
{
};
class Processer
{
};
class Smartphone : public Camera, public Processer
{
};
//Hybrid Inhertance
class A
{
};
class B : virtual public A
{
};
class C : virtual public A
{
};
class D : public B, public C
{
    // to remove ambiguity of class A function we make its parant class virtual
    //because this class has class A fun() that comes from from both B ans C
};

int main()
{
    freopen("#input.txt", "r++", stdin);
    freopen("#output.txt", "w++", stdout);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    // Derived d;
    // d.x = 10;
    // d.y = 20;
    // d.printx();
    // d.printall();
    // Child c;
    // Child(4);
    Child(2, 4);
    return 0;
}
