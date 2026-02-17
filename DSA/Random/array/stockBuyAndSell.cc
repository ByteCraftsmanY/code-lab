// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPurchasedPrice = INT_MAX, maxProfit = 0;
    for (auto x : prices) {
        minPurchasedPrice = min(x, minPurchasedPrice);
        maxProfit = max(maxProfit, x - minPurchasedPrice);
    }
    return maxProfit;
}
int main() {
    return 0;
}