#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int compress(vector<char>& chars) {
    int i = 0, j = 0, n = chars.size(), dist, res = 0, p = 0;
    while (i < n) {
        j = i + 1;
        while (j < n && chars[i] == chars[j]) j++;
        chars[p++] = chars[i], res += 1;
        dist = j - i;
        if (dist > 1) {  // appears more then once
            res += (int(log10(dist) + 1));
            for (auto d : to_string(dist)) {
                chars[p++] = d;
            }
        }
        i = j;
    }
    return res;
}

int main() {
    vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    chars = {'a'};
    chars = {
        'a',
        'a',
        'b',
        'b',
        'c',
        'c',
        'c',
    };
    int res = compress(chars);
    cout << res << endl;
    for (int i = 0; i < res; i++)
        cout << chars[i] << " ";
    return 0;
}