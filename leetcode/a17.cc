#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0, maxAltitude = 0;
        for (int al : gain) {
            sum += al;
            maxAltitude = max(sum, maxAltitude);
        }
        return maxAltitude;
    }
};

int main() {
    return 0;
}