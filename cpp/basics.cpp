#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << (#x) << " : " << x << "\n"
int main()
{
    freopen("#input.txt", "r++", stdin);
    freopen("#output.txt", "w++", stdout);
    //remove c overheads
    ios_base::sync_with_stdio(false);
    {
        int t = 0;
        // scanf("%d", &t);// not supported because of ios_base
        // while (t--)
        printf("\n %d Heelo\n", t); // supported but because of ios_base it is printing at the end of the program
    }
    //Untie cin and cout
    cin.tie(NULL);
    {
        int n;
        cin >> n;
        cout << "Value is " << n << endl;
        string s;
        cin >> s;
        cout << "Your Inter " << s << endl;
    }
    // Bi-Directinal Iteraters
    {
        vector<int> v = {1, 2, 3, 4, 5};
        //forward iterater
        vector<int>::iterator fi;
        for (fi = v.begin(); fi != v.end(); fi++)
            cout << *fi << "  ";
        cout << endl;
        //backward iterater
        vector<int>::reverse_iterator ri;
        for (ri = v.rbegin(); ri != v.rend(); ri++)
            cout << *ri << "  ";
        cout << endl;
        //Note :- Vecter , Map, Multimap, Set ,deque, List Support Backward and forward itraters
    }
    //  Forward Iteraters
    {
        forward_list<int> lst1 = {1, 2, 3, 4, 5}; // Singly Linked List
        lst1.push_front(10);
        forward_list<int> lst2 = {10, 20, 30};
        lst1.merge(lst2);
        for (auto x : lst1)
            cout << x << " ";
        cout << endl;
        // Note : unordered_map,unordered_set support forward iteraters
    }
    // Tie and MakeTouple
    {
        int a, b, c, d;
        // a, b, c, d = 10, 20, 30, 40;  //Not Working
        tie(a, b, c, d) = make_tuple(10, 20, 30, 40);
        cout << a << " " << b << " " << c << " " << d << " ";
        cout << endl;
    }
    //update using foreach loop
    {
        vector<int> v{1, 2, 3};
        for (auto x : v)
            cout << x << " ";
        cout << endl;
        for (auto &x : v)
            x = 1;
        for (auto x : v)
            cout << x << " ";
        cout << endl;
    }
    // auto keyward
    {
        auto size = 10;
        auto *x = new auto(size);
        cout << typeid(x).name();
        cout << endl;
    }
    //Size_t
    {

        size_t i = 10; //able to store >=0 int value //Mostly used to store size of the object
        cout << typeid(i).name() << endl;
    }
    //typeid
    {
        print(typeid(int).name());
        print(typeid(float).name());
        print(typeid(char).name());
        print(typeid(string).name());
        print(typeid(int *).name());
        print(typeid(double).name());
        print(typeid(char *).name());
        print(typeid(float *).name());
        print(typeid(double *).name());
        print(typeid(set<int>()).name());
        print(typeid(map<int, int>()).name());
        print(typeid(set<int>::iterator).name());
        print(typeid(vector<int>()).name());
        print(typeid(size_t).name());
        print(typeid(unsigned int).name());
        print(typeid(long long).name());
        print(typeid(int[]).name());
        print(typeid(pair<int, int>).name());
        print(typeid(tuple<int, int, float>).name());
        print(typeid(int &).name());
        print(typeid(int **).name());
        print(typeid(map<int, int>::iterator).name());
        print(typeid(unordered_map<int, int>::iterator).name());
    }
    //Lambda Functions
    {
        int pp = 10, qq = 20;
        auto findMin = [](int x, int y)
        { return x < y ? x : y; };
        auto findMax = [](int x, int y)
        { return x > y ? x : y; };
        cout << findMin(pp, qq) << "\n"
             << findMax(pp, qq) << "\n\n";
    }
    //another formula for finding ceil
    {
        int a1 = 5, b1 = 2;
        cout << ceil((double)a1 / b1) << "\n "; //If we didnt cast then it will show 2(that is wrong) becouse integer division
        cout << ((a1 + b1 - 1) / 2) << endl;    //different way
    }
    //to substract ans multipication of all array/vecter value using accumulate ()
    {
        int m = 100;
        vector<int> arr = {10, 20, 30};
        cout << accumulate(arr.begin(), arr.end(), m, minus<int>()) << endl;
        m = 1;
        auto multi = [](int x, int y)
        { return x * y; };
        cout
            << accumulate(arr.begin(), arr.end(), m, multi) << endl;
    }
    //Min / Max element from vector
    {
        vector<int> arr = {10, 20, 30};
        cout << *min_element(arr.begin(), arr.end()) << endl;
        cout << *max_element(arr.begin(), arr.end()) << endl;
    }
    //count ()
    {
        vector<int> arr{1, 2, 2, 3, 3, 5, 2, 3, 2, 7};
        cout << count(arr.begin(), arr.end(), 2) << endl;
        string a = "ababaa";
        cout << count(a.begin(), a.end(), 'a') << endl;
    }
    //MinHeap and MaxHeap with stl
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int> maxHeap;
        minHeap.push(13);
        minHeap.push(7);
        minHeap.push(56);
        while (!minHeap.empty())
        {
            int x = minHeap.top();
            cout << x << " ";
            minHeap.pop();
        }
        cout << endl;
        maxHeap.push(7);
        maxHeap.push(13);
        maxHeap.push(33);
        while (!maxHeap.empty())
        {
            int x = maxHeap.top();
            cout << x << " ";
            maxHeap.pop();
        }
        cout << endl;
    }

    return 0;
}