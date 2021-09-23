#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)
typedef long long int ll;
typedef vector<int> vc;
typedef pair<int, int> pr;

int main()
{
    freopen("#input.txt", "r++", stdin);
    freopen("#output.txt", "w++", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    Note:   __builtin_popcount() for finding set bit in a integer
            not a cpp standard
            provider by gcc compiler only
    */
    int a = 3;
    cout << __builtin_popcount(a) << endl; // for integer
    long int b = 11;
    cout << __builtin_popcountl(b) << endl; //for long int
    long long int c = 101;
    cout << __builtin_popcountl(c) << endl; // for long long int    
    return 0;
}
