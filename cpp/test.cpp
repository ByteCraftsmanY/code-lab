#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
typedef long long int ll;
typedef vector<int> vc;
typedef pair<int, int> pr;
void printArray(int **arr, int n, int m)
{
    REP(i, 0, n)
    {
        REP(j, 0, m)
        cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
int n = 20;
auto lambda = [n = n]()
{
    return 2 * n;
};
int main()
{
    freopen("#input.txt", "r++", stdin);
    freopen("#output.txt", "w++", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int **arr = new int *[n];
    REP(i, 0, n)
    arr[i] = new int[3];
    REP(i, 0, n)
    REP(j, 0, n)
    cin >> arr[i][j];
    printArray(arr, 3, 3);
    vc a;
    REP(i, 0, 4)
    {
        cin >> n;
        i % 2 ? a.emplace_back(i * i) : a.emplace_back(n);
        // a.push_back(i * i);
    }
    a.emplace(a.begin(), 9);
    vector<int>::iterator r = a.begin();
    a.erase(r + 1);
    cout << a[0] << endl;
    for (auto x : a)
        cout << x << " ";
    a.shrink_to_fit();
    cout << endl;
    cout << a.capacity() << endl;
    unordered_set<int> st(a.begin(), a.end());
    for (auto x : st)
    {
        cout << x << " ";
    }
    cout << endl;
    a.clear();
    a = {0, 1, 2, 2, 2, 3, 5};
    auto p = lower_bound(all(a), 2);
    cout << *p << endl;
    for (auto i = p; i != a.end(); i++)
        cout << *i << " ";
    cout << endl;
    st.clear();
    set<int> st1(a.begin(), a.end());
    int ax[] = {1, 2, 3};
    cout << -0 [ax] << endl;
    cout << lambda() << endl;
    double x = 9.901;
    cout << setprecision(10) << x << endl;
    {
        int m = 100;
        vector<int> arr = {10, 20, 30};
        cout << accumulate(arr.begin(), arr.end(), m, minus<int>()) << endl;
        m = 1;
        auto multi = [](int x, int y)
        { return x * y; };
        cout
            << accumulate(arr.begin(), arr.end(), m, multi) << endl;
        cout << *min_element(arr.begin(), arr.end()) << endl;
        cout << *max_element(arr.begin(), arr.end()) << endl;
    }
    {
        vector<int> arr{1, 2, 2, 3, 3, 5, 3, 2, 7};
        cout << count(arr.begin(), arr.end(), 2) << endl;
        string a = "ababaa";
        cout << count(a.begin(), a.end(), 'a') << endl;
    }
    char str1[] = "GeeksforGeeks";
    cout << sizeof(str1) << ""
                            ""
         << strlen(str1) << endl;
    return 0;
}
