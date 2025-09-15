#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    vector<int> result;
    int i = 0;
    while (i < asteroids.size()) {
        bool hasExistance = true;
        while (!st.empty() && st.top() > 0 && asteroids.at(i) < 0) {
            if (st.top() > abs(asteroids.at(i))) {
                hasExistance = false;
                break;
            } else if (st.top() < abs(asteroids.at(i))) {
                st.pop();
            } else {
                st.pop();
                hasExistance = false;
                break;
            }
        }
        if (hasExistance) st.push(asteroids.at(i));
        i++;
    }
    result.resize(st.size());
    i = result.size() - 1;
    while (!st.empty()) {
        result[i--] = st.top();
        st.pop();
    }
    return result;
}

int main() {
    vector<int> arr = {5, 10, -5};
    arr = {8, -8};
    arr = {10, 2, -5};
    vector<int> res = asteroidCollision(arr);
    for (auto x : res) cout << x << " ";
    return 0;
}