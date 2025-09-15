#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<int> countBits(int n) {
    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int count = 0, temp = i;
        while (temp > 0) {
            count++;
            temp &= (temp - 1);
        }
        arr[i] = count;
    }
    return arr;
}

int main(){
}