#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
typedef long long int ll;
typedef vector<int> vc;
typedef pair<int, int> pr;
//Generalization
class Car // Generalized class || Abstracted class{if contains pure virtual fun}
{
    //if it contains all pure virtual fun then it will become Interface
public:

    virtual void start() = 0; // {} //if () = 0 then Pure Virtual Fun
    virtual void stop() = 0;  // {}  //if () = 0 then Pure Virtual Fun
    virtual void run() = 0;   // { cout << "\nCar is running"; };
    //because of pure virtual fun it become abstracted class
    //pure virtual fun is used for archibing generalization and polymorphism
};
class Inova : public Car
{
public:
    void start() { cout << "\nInova started"; }
    void stop() { cout << "\nInova stoped"; }
    void run() { cout << "\nInova running"; }
};
class Swift : public Car
{
public:
    void start() { cout << "\nSwift started"; }
    void stop() { cout << "\nSwift stoped"; }
    void run() { cout << "\nSwift running"; }
};

class latestCar : public Car
// we didnt override pure virtual fun
//so it is also a abstracted class
{
public:
    virtual void maxSpeed() = 0;
};
class Bugati : public latestCar
{
public:
    void start() { cout << "\nBugati started"; }
    void run() { cout << "\nBugati running"; }
    void stop() { cout << "\nBugati stopped"; }
    void maxSpeed() { cout << "\nBugati maxRun = 500kmph"; }
    void name() { cout << "\nBugati"; }
};
int main()
{
    freopen("#input.txt", "r++", stdin);
    freopen("#output.txt", "w++", stdout);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    //Car c; //not allowed because of abstracted class
    Car *c = new Inova();//can hae a pointer to achive polymorphism
    c->start();
    c->run();
    c->stop();
    c = new Swift();
    c->start();
    c->run();
    c->stop();
    latestCar *lc = new Bugati();
    lc->maxSpeed();
    return 0;
}
