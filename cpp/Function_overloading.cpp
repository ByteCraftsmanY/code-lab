#include <bits/stdc++.h>
using namespace std;

//Function Overloading
int sum(int x, int y)
{
    return x + y;
}
float sum(float x, float y)
{
    return x + y;
}
int sum(int x, int y, int z)
{
    return x + y + z;
}
/*
    argument list must be different 
    argument type must be different
*/
//float sum(int x,int y);//Not Allowed when only return type change


//Function template
template <typename T>
// template <class T>
T findMax(T x, T y)
{
    return x > y ? x : y;
}
int main()
{
    freopen("#input.txt", "r++", stdin);
    freopen("#output.txt", "w++", stdout);
    //Function Overriding
    {
        int a, b, c, d;
        float x, y, z;
        a = 10, b = 20, c = 30;
        x = 4.5f, y = 3.4f;
        cout << sum(a, b) << " " << sum(x, y) << " " << sum(a, b, c) << endl;
    }
    // function template for using same code for different data types
    {
        cout << findMax('a', 'z') << " " << findMax(34, 4) << endl;
    }

    return 0;
}
