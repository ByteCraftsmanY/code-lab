#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int guess(int num);

class Solution {
   public:
    int guessNumber(int n) {
        int l = 1, h = n, mid;
        while (l <= h) {
            mid = (l + (h - l) / 2);
            int result = guess(mid);
            switch (result) {
                case 1:
                    l = mid + 1;
                    break;
                case -1:
                    h = mid - 1;
                    break;
                default:
                    return mid;
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}