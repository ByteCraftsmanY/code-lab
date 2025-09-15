#include <bits/stdc++.h>
using namespace std;
string decodeString(string s) {
    stack<char> st;
    int i = 0, count = 0, idx = 0;
    string result = "", subStr = "", decodedSubStr;
    while (i < s.size()) {
        if (s[i] == ']') {
            // extract string
            subStr = "";
            while (!st.empty() && st.top() != '[') {
                subStr = st.top() + subStr;
                st.pop();
            }
            st.pop();

            // extract nums
            idx = 0, count = 0;
            while (!st.empty() && isdigit(st.top())) {
                int ele = (st.top() - '0') * pow(10, idx++);
                count += ele;
                st.pop();
            }

            // build string
            decodedSubStr = "";
            for (int i = 0; i < count; i++) decodedSubStr += subStr;
            for (auto c : decodedSubStr) st.push(c);
        } else {
            st.push(s[i]);
        }
        i++;
    }
    i = st.size() - 1;
    result.resize(st.size());
    while (!st.empty()) {
        result[i--] = st.top();
        st.pop();
    }
    return result;
}
int main() {
    string s;
    getline(cin, s);
    cout << decodeString(s) << endl;
    return 0;
}