#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
typedef long long int ll;
typedef vector<int> vc;
typedef pair<int, int> pr;
class Fatch; //to define friend must be declear first
class Test
{
private:
    int a;

protected:
    int b;

public:
    int c;
    friend void fun(); //now fun() can access Test's private and protected members through Object
    friend Fatch;      //now Fatch class can access Test's private and protected members through Object
};
void fun()
{
    Test t;
    t.a = 10;
    t.b = 20;
    t.c = 30;
}
class Fatch
{
    Test t;

public:
    void fun()
    {
        t.a = 20;
        t.b = 30;
        t.c = 40;
    }
};
int main()
{
    freopen("#input.txt", "r++", stdin);
    freopen("#output.txt", "w++", stdout);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    return 0;
}
