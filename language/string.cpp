#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("#input.txt", "r++", stdin);
    freopen("#output.txt", "w++", stdout);
    //npos :: End of string
    {
        string s;
        getline(cin, s);
        if (s.find("ee") != s.npos)
            cout << "found ee\n\n";
        cout << "\n\n";
    }
    //regular Expressions
    {
        string str = "Geeks Q10 in A10 out!";
        regex regularExperssion("[A-Z][0-9][0-9]");
        smatch matched;
        while (regex_search(str, matched, regularExperssion))
        {
            cout << "Match found " << matched.str() << endl;
            str = matched.suffix();
        }
        cout << "\n\n";
    }

    return 0;
}