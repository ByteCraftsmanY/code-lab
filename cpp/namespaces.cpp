#include <iostream>
namespace first
{
    int a = 10;
    class Test
    {
    public:
        Test() { std::cout << "First space class\n"; }
    };
    void fun() { std::cout << "First space fun\n"; }
}
namespace second
{
    int a = 20;
    class Test
    {
    public:
        Test() { std::cout << "Second space class\n"; }
    };
    void fun() { std::cout << "second space fun\n"; }
}
using namespace first;
int main()
{
    fun();
    second::fun();
}