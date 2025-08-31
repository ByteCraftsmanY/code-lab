#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
typedef long long int ll;
typedef vector<int> vc;
typedef pair<int, int> pr;

/*

For operator overloading you have to just use operater+
signature instead of function name here 
compare add() to operater+()

we can overlaod operator using 
    member function
        or
    friend function
*/
class ComplexNumber
{
private:
    int real;
    int img;

public:
    ComplexNumber(int real = 0, int img = 0) { this->real = real, this->img = img; }
    ComplexNumber add(ComplexNumber x)
    {
        ComplexNumber temp;
        temp.real = real + x.real;
        temp.img = img + x.img;
        return temp;
    }
    //instead of using add() for sum we use operater overloading for easier understanding
    ComplexNumber operator+(ComplexNumber x)
    {
        return ComplexNumber(real + x.real, img + x.img);
    }
    ComplexNumber operator-(ComplexNumber x) { return ComplexNumber(real - x.real, img - x.img); }
    //Same signature but take two Args instead of one and friend before signature
    //Global access wheather friend is private,or protected or public
    // Used for uperater overloading
    //it is like global fun() but can access all private member of that class in which it is define as a friend
    friend ComplexNumber operator*(ComplexNumber, ComplexNumber);
    void out() { cout << real << " + i" << img << endl; }
    //Overload insertion (<<) and extraction(>>) operator
    //or
    //Overload Input output stream
    // can only be defined with friend only
    //return type must be ostream refereance and Args of Ostream must be referenced
    friend ostream &operator<<(ostream &o, ComplexNumber &c);
};
//friend function must be define outside the class without scope resolution
ComplexNumber operator*(ComplexNumber a, ComplexNumber b) { return ComplexNumber(a.real * b.real, a.img * b.img); }
ostream &operator<<(ostream &out, ComplexNumber &c)
{
    out << c.real << "+i" << c.img << endl;
    return out;
}
//Excersize
class RationalNumber
{
private:
    int p, q;

public:
    RationalNumber(int p = 0, int q = 0) { this->p = p, this->q = q; }
    friend RationalNumber operator+(RationalNumber, RationalNumber);
    friend ostream &operator<<(ostream &, RationalNumber);
};
RationalNumber operator+(RationalNumber a, RationalNumber b)
{
    RationalNumber c;
    c.q = a.q * b.q;
    c.p = (a.p * b.q) + (a.q * b.p);
    return c;
}
ostream &operator<<(ostream &out, RationalNumber b)
{
    out << b.p << "/" << b.q << endl;
    return out;
}
int main()
{
    freopen("#input.txt", "r++", stdin);
    freopen("#output.txt", "w++", stdout);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    ComplexNumber a(3, 6);
    ComplexNumber b(7, 4);
    ComplexNumber c = a.add(b);
    c.out();
    ComplexNumber d = a + b; //d = a.operator+(b);
    c.out();
    ComplexNumber e = a - b;
    e.out();
    ComplexNumber f = operator*(a, b); // a * b;
    f.out();
    //inserton(<<) operator takes two argument thats why we take two Args on overloaded()
    cout << f;
    operator<<(cout, f);
    RationalNumber p(3, 4), q(2, 5), r;
    cout << p;
    cout << q;
    r = p + q;
    cout << r;
    return 0;
}
