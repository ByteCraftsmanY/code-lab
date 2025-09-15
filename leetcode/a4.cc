#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    for (int i = 0; i < flowerbed.size(); i++) {
        if (n <= 0)
            break;
        bool isPreviousEmpty = i == 0 || flowerbed[i - 1] == 0;
        bool isNextEmpty = i == flowerbed.size() - 1 || flowerbed[i + 1] == 0;
        if (isPreviousEmpty && isNextEmpty && !flowerbed[i])
            flowerbed[i] = 1, n--;
    }
    return n <= 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> flowerbed(n, false);
    for (int& x : flowerbed) {
        cin >> x;
    }
    cout << canPlaceFlowers(flowerbed, m);
    return 0;
}