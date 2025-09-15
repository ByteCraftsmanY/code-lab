#include <bits/stdc++.h>
using namespace std;
class MyException : public exception {
   public:
    char *what() {
        return "My Exception";
    }
};
int division(int x, int y)  // throw()
// throw() shows that this fun doesnt throw any exception
// throw(type) this show that this function will throw this type of exception
{
    if (!y)
        throw MyException();  // can throw int , char ,float , double ,class etc.
    return x / y;
}
class MyException1 {
};
class MyException2 : public MyException1 {
};
int main() {
    freopen("#input.txt", "r++", stdin);
    freopen("#output.txt", "w++", stdout);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int a, b, c;
    cin >> a >> b;
    // specially used for communication between function
    // function will tell if unable to perform
    try {
        c = division(a, b);  // get output otherwise throw exception
        // Nesting of try catch is also possible
        try {
        } catch (...) {
        }
        cout << c;
    } catch (int e) {
        cout << "Integer error" << e << endl;
    } catch (MyException e) {
        cout << "Exception thrown by function " << e.what() << endl;
    } catch (...)  // Catch all // ... elipse
    {
        cout << "Handle all type of exception";  // comman case
    }
    cout << "\nEND\n";
    try {
    } catch (MyException2)
    // derived class must be first in order of catch block
    // because if we define parant class first it can handle exception before child class so there will be no use of define child catch after  parant catch
    {
    } catch (MyException1) {
    }
    return 0;
}
