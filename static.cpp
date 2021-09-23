#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
typedef long long int ll;
typedef vector<int> vc;
typedef pair<int, int> pr;
class Swift
{
private:
    int a;

public:
    //static member share only one copy of all of its projects
    static int c; // = 0;  // Not allowed because of static it must be declear outside of class
    static int selledCar;
    static int getPrice()
    {
        // a=0; // Not allowed
        // only static members are allowed
        return c;
    }
    Swift() { selledCar++; }
};
int Swift::c = 42; //Like this
int Swift::selledCar = 0;
int main()
{
    freopen("#input.txt", "r++", stdin);
    freopen("#output.txt", "w++", stdout);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    //static member can accessed through
    //throught class name only without creating object
    cout << Swift::getPrice() << " " << Swift::c << endl;
    //Object as regular
    Swift s,s1,s2;//static member only create once and shared among all the ojects
    cout << s.getPrice() << " " << s.c << endl;
    cout << "Total Selled Car " << Swift::selledCar << endl;

    return 0;
}
