#include <bits/stdc++.h>
using namespace std;

string convertToBinary(int n) {
    string binary;
    while (n > 0) {
        char c = n % 2 == 0 ? '0' : '1';
        n /= 2;
        binary = c + binary;
    }
    return binary;
}

// https://www.naukri.com/code360/problems/check-whether-k-th-bit-is-set-or-not_5026446
bool isKthBitSet(int n, int k) {
    int val = 1 << (k - 1);
    cout << convertToBinary(n) << " " << convertToBinary(val) << endl;
    return n & val;
}

bool isOdd(int n) {
    return n & 1;
}

// https://leetcode.com/problems/number-of-1-bits/description/
int numberOfSetBits(int n) {
    /*
        int counter = 0, val = 1;
        for (int i = 0; i < 30; i++) {
            if (n & val) {
                counter++;
            }
            val = val << 1;
        }
        return counter;
    */

    /*
        int count = 0;
        while (n) {
            count += (n & 1);
            n = n >> 1;
        }
        return count;
    */

    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

// https://www.naukri.com/code360/problems/set-the-rightmost-unset-bit_8160456
int setBits(int N) {
    // int val = 1;
    // for (int i = 0; i < 31; i++) {
    //     if (val > N) {
    //         break;
    //     }
    //     if ((N & val) == 0) {
    //         return N | val;
    //     }
    //     val = val << 1;
    // }
    // return N;

    if ((N & (N + 1)) == 0) {
        return N;
    }
    return ((N + 1) & ~N) | N;
}

void swapTwoNumbers(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;  // (a ^ b) ^ b
    a = a ^ b;  // (a ^ b) ^ b // b == a from above
}

int setKthBit(int n, int k) {
    return n | (1 << k);
}

int clearKthBit(int n, int k) {
    return n & (~(1 << k));
}

int flipKthBit(int n, int k) {
    return n ^ ((1 << k));
}

int removeRightmostSetBit(int n) {
    return (n & (n - 1));
}

bool isPowerOf2(int n) {
    return n & (n - 1);
}

int divide(int dividend, int divisor) {
    if (dividend == divisor) return 1;
    bool sign = true;
    if ((dividend <= 0 && divisor > 0) || (dividend >= 0 && divisor < 0)) {
        sign = false;
    }
    long long int n = abs((long long int)dividend), d = abs((long long int)divisor), result = 0;

    while (n >= d) {
        long long int c = 0;
        while (n >= (d << (c + 1))) {
            c++;
        }
        n -= (d << c);
        result += (1 << c);
    }
    // special case when we convert INT_MIN (....8) to INT_MAX (...7) which is 1 larger
    if (result == (1 << 31))
        return sign ? INT_MAX : INT_MIN;
    return sign ? result : (-1 * result);
}

int main() {
    cout << divide(22, 3) << endl;
    return 0;
    int t;
    cin >> t;
    while (t--) {
        // int n, k;
        // cin >> n >> k;
        // cout << isKthBitSet(n, k) << endl;
        /*
            3
            3 2
            128 7
            200 4
        */
        // int n;
        // cin >> n;
        // cout << isOdd(n) << endl;
        // cout << isPowerOf2(n) << endl;
        // cout << setBits(n) << endl;

        // int a, b;
        // cin >> a >> b;
        // swapTwoNumbers(a, b);
        // cout << a << " " << b << endl;

        // int n, k, res;
        // cin >> n >> k;
        // res = setKthBit(n, k);
        // cout << convertToBinary(n) << " " << convertToBinary(res) << endl;
        // res = clearKthBit(n, k);
        // cout << convertToBinary(n) << " " << convertToBinary(res) << endl;
        // res = flipKthBit(n, k);
        // cout << convertToBinary(n) << " " << convertToBinary(res) << endl;

        // int n;
        // cin >> n;
        // cout << removeRightmostSetBit(n) << endl;

        // int n;
        // cin >> n;
        // cout << numberOfSetBits(n) << endl;
        cout << divide(22, 3) << endl;
    }
    return 0;
}
