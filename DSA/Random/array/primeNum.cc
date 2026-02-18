#include <bits/stdc++.h>

#include "utils.h"
using namespace std;

vector<int> printPrime(int n) {
    vector<int> arr(n + 1, 0);
    for (int i = 2; i <= sqrt(n); i++) {
        if (arr[i] == -1) continue;
        int j = i * 2;
        while (j <= n) {
            arr[j] = -1;
            j += i;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (arr[i] != -1) {
            cout << i << " ";
        }
    }
    return {};
}

int main() {
    printPrime(50);
    return 0;
}