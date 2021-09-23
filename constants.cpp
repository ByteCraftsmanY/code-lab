#include <iostream>
using namespace std;
class demo
{
    int x, y;

public:
    void test() const
    {
        // x++; // not allowed to modify value
        cout << x << " " << y << endl;
    }
};
int sum(const int &x, int &y)//call by reference - can modify actual value
{
    //x++; not allowed
    y++;
    return x+y;
}
int main()
{
    freopen("#input.txt", "r++", stdin);
    freopen("#output.txt", "w++", stdout);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    //type of constant on variable
    const int a = 5; //integer constant - value unmodifiable
    // int const a = 5;//constant integer - same
    // a=10; //not allowed
    int ver = 10;
    const int *ptr1 = &ver;       //integer pointer constant - address can be modified but address value unmodifiable
    int  * const ptr2 = &ver;       //constant pointer integer - address unmodifible but address value modifiable
    const int const *ptr3 = &ver; //constant pointer integer constant - address & its value both unmodifible

    int p = 1, q = 4;
    sum(p, q);
    return 0;
}
