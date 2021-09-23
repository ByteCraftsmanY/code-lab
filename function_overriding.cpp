#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
typedef long long int ll;
typedef vector<int> vc;
typedef pair<int, int> pr;
class BasicCar
{
public:
    void display() { cout << "\nBasicCar Display"; }
    void display2() { cout << "\nBasicCar2 Display"; }
    void start() { cout << "\nBasicCar is started"; }
    virtual void run() { cout << "\nBasicCar is running"; }
};
class AdvancedCar : public BasicCar
{
public:
    //Function signature must be same with parant class
    void display() { cout << "\nAdvancedCar Display"; }
    //otherwise it will become function overloading
    void display2(int x) { cout << "\nAdvancedCar 2 Display " << x << endl; }
    void start() { cout << "\nAdvandedCar is started"; }
    void run() { cout << "\nAdvandedCar is running"; }
};
int main()
{
    freopen("#input.txt", "r++", stdin);
    freopen("#output.txt", "w++", stdout);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    AdvancedCar c;
    c.display();
    c.display2(4);
    //for calling parant class function with AdvancedCar class object
    c.BasicCar::display2();
    c.BasicCar::display();
    //Run time Polymorphism {base class pointer-> derived class object + virtual}
    {
        BasicCar *p = new AdvancedCar();
        //if we call this override function base fun will be called
        p->start();
        // but this is logically incorrect
        // becouse althrough we think that is basic car but it will run like a advance car
        // for that we will use virtual keyword
        p->run();
    }
    return 0;
}
