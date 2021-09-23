#include <bits/stdc++.h>
using namespace std;
int findMin(int x, int y)
{
    return x > y ? y : x;
}
int findMax(int x, int y)
{
    return x > y ? x : y;
}
int main()
{
    freopen("#input.txt", "r++", stdin);
    freopen("#output.txt", "w++", stdout);

    int *ptr = new int[5]; // declearation and initilization of pointer
    delete[] ptr;          // deallcating memory
    ptr = nullptr;         //pointing to null

    int arr[3] = {1, 2, 5};
    int *p = arr;
    for (int i = 0; i < 3; i++)
    {
        //different ways of printing values
        cout << i[arr] << " "; //todo
        cout << arr[i] << " ";
        cout << p[i] << " ";
        cout << i[p] << " ";
        cout << (p + i) << " ";    //address
        cout << *(p + i) << " ";   //value
        cout << (arr + i) << " ";  //address
        cout << *(arr + i) << " "; //value
        // {
        //     cout<<*p;
        //     p++;
        // }
        cout << endl;
    }
    int *q = &arr[4];
    cout << "< " << p - q << " >\n"; //tells how many values between them//if - then p is refer forward then q
    cout << arr << endl;
    cout << "\n\n";

    // reference
    int val = 10;
    int &ref = val; //ref doesnt take any memory //kind of nickname of val
    int val1 = 20;
    // &ref = val2; //not valid on2 veriable refers only once.
    cout << &val << "  " << &ref << endl; // both address are same
    ref++;
    val++;
    cout << val << "  " << ref << endl;
    cout << "\n\n";

    // Function Pointer
    int a, b;
    cin >> a >> b;
    int (*fp)(int, int);
    fp = findMax;
    cout << (*fp)(a, b) << endl;
    fp = findMin;
    /*
    Here Same function pointer refers to findMin() also this is example of polymorphism .
    Function overriding uses this function pointer method internally.
    */
    cout << (*fp)(a, b) << endl;
    return 0;
}