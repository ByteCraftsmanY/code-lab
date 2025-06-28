#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
typedef long long int ll;
typedef vector<int> vc;
typedef pair<int, int> pr;
class Outer
{
public:
    int a;
    static int b;
    Outer()
    {
        cout << obj.y << "is accessable\n";
    }
    class Inner //Nested Class
    {
    public:
        int x;     //= a; // Non static member are not accessable
        int y = b; //only static member can be assessable inside inner class
    };
    Inner obj;
};
int Outer::b = 0;
int main()
{
    freopen("#input.txt", "r++", stdin);
    freopen("#output.txt", "w++", stdout);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    Outer::Inner i;
    cout << i.y << endl;
    return 0;
}
