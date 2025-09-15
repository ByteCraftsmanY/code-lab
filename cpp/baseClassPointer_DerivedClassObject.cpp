// • Base class pointer can point on derived class object
// • But only those functions which are in base class, can be called
// • If derived class is having overrides functions they will not be called unless base class functions are declared as virtual
// • Derived class pointer cannot point on base class object

#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
typedef long long int ll;
typedef vector<int> vc;
typedef pair<int, int> pr;

class BasicCar {
   public:
    void drive() {
        cout << "you can drive\n";
    }
};

class AdvancedCar : public BasicCar {
   public:
    void music() {
        cout << "Play Music\n";
    }
};

int main() {
    freopen("#input.txt", "r++", stdin);
    freopen("#output.txt", "w++", stdout);

    ios_base::sync_with_stdio(false);
    
    cout.tie(NULL);
    cin.tie(NULL);
    
    bool prnt = false;
    
    // Basic car have its own featrues
    if (prnt) {
        BasicCar car;
        car.drive();
    }

    // Base class object can have its parant features  also
    if (prnt) {
        AdvancedCar car;
        car.drive();
        car.music();
    }

    // child car pointer can only inilized with its own object
    //  ability to access its parant class fun() also
    if (prnt) {
        AdvancedCar *car = new AdvancedCar();
        car->drive();
        car->music();
    }
    
    //  base class pointer can only have its own features
    // it can be initilized with its own object as well as its child class object
    // example : advance car can be a basic car
    if (prnt) {
        // AdvancedCar _advancedCar;
        // BasicCar *car = &_advancedCar;
        //              or
        BasicCar *car = new AdvancedCar();
        car->drive();
        // car->music();//Not allowed
    }
    // but basic car can not be a advanced car
    if (prnt) {
        // Not allowed
        //  AdvancedCar *car = new BasicCar();
    }

    return 0;
}
