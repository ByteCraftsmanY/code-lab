#include <bits/stdc++.h>
using namespace std;

bool isBitSet(int n, int i) {
    return n & (1 << i);
}

bool isOdd(int n) {
    return n & 1;
}

bool isPowerOfTwo(int n) {
    return (n & (n - 1)) == 0;
}

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count++;
        n = (n & (n - 1));
    }
    return count;
}

int setRightmostUnsetBit(int n) {
    if ((n & (n + 1)) == 0) {
        return n;
    }
    return ((n + 1) & ~n) | n;
}

void swapTwoNums(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

int divide(int dividend, int divisor) {
    if (dividend == divisor) return 1;
    bool sign = ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0));  // true means +ve
    long long int divid = abs((long long int)dividend), divis = abs((long long int)divisor);
    int ans = 0, count = 0;
    while (divid >= divis) {
        count = 0;
        while (divid >= (divis << (count + 1))) {
            count++;
        }
        divid -= (divis << count);
        ans += (1 << count);
    }
    if (ans >= (1 << 31)) {
        return sign ? INT_MIN : INT_MAX;
    }
    return sign ? -ans : ans;
}

int minBitFlips(int start, int goal) {
    int count = 0, diff = start ^ goal;
    while (diff) {
        count++;
        diff &= (diff - 1);
    }
    return count;
}

int singleNumber(vector<int> &nums) {
    int res = 0;
    for (int const &num : nums) res ^= num;
    return res;
}

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    for (int i = 0; i < (1 << nums.size()); i++) {
        vector<int> result;
        for (int j = 0; j < nums.size(); j++) {
            if (i & (1 << j)) {
                result.push_back(nums[j]);
            }
        }
        ans.push_back(result);
    }
    return ans;
}

int findXORFrom1ToN(int n) {
    if (n % 4 == 0) {
        return n;
    } else if (n % 4 == 1) {
        return 1;
    } else if (n % 4 == 2) {
        return n + 1;
    } else if (n % 4 == 3) {
        return 0;
    }
    return 0;
}

int findXOR(int L, int R) {
    return findXORFrom1ToN(L - 1) ^ findXORFrom1ToN(R);
}

vector<int> twoOddNum(vector<int> arr) {
    int n = 0;
    for (int const &num : arr) n ^= num;
    int v = (n & (n - 1)) ^ n;
    int b0 = 0, b1 = 0;
    for (int const &num : arr) {
        if (v & num) {
            b1 ^= num;
        } else {
            b0 ^= num;
        }
    }
    return {b0, b1};
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> getDivisors(int n) {
    vector<int> result;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            result.push_back(i);
            if ((n / i) != i) {
                result.push_back(n / i);
            }
        }
    }
    return result;
}

vector<int> getPrimeDivisors(int n) {
    // TC: O(sqrt(n) * sqrt(n)) == O(n)
    // vector<int> divisors = getDivisors(n);
    // vector<int> res;
    // for (auto const &div : divisors) {
    //     if (isPrime(div)) res.push_back(div);
    // }
    // return res;

    vector<int> res;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            res.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
    return res;
}

int countPrimes(int n) {
    int count = 0;
    vector<int> primes(n + 1);
    for (int i = 0; i < primes.size(); i++) primes[i] = i;
    for (int i = 2; i * i <= primes.size(); i++) {
        if (primes[i] == -1) continue;
        for (int j = i * i; j <= primes.size(); j += i) {
            primes[j] = -1;
        }
    }
    for (int i = 2; i < primes.size(); i++)
        if (primes[i] != -1) count++;
    return count;
}

vector<int> findPrimeFactors(int N) {
    vector<int> primes(N + 1);
    for (int i = 0; i < primes.size(); i++) primes[i] = i;

    for (int i = 2; i * i < primes.size(); i++) {
        if (primes[i] != i) continue;
        for (int j = i * i; j < primes.size(); j += i) {
            if (primes[j] == j) {
                primes[j] = i;
            }
        }
    }

    vector<int> result;
    while (N > 1) {
        result.push_back(primes[N]);
        N /= primes[N];
    }
    return result;
}

double myPow(double x, int n) {
    if (n < 0)
        return 1 / myPow(x, -n);
    else if (n == 0)
        return 1;
    else if (n & 1)
        return x * myPow(x, n - 1);
    return myPow(x * x, n / 2);
}

int main() {
    // cout << isBitSet(5, 3) << endl;
    // cout << isOdd(2) << endl;
    // cout << isPowerOfTwo(7) << endl;
    // cout << countSetBits(2) << endl;
    // cout << setRightmostUnsetBit(7) << endl;
    // int a = 3, b = 5;
    // swapTwoNums(a, b);
    // cout << a << " " << b;
    // cout << divide(-2147483648, -1) << endl;
    // cout << minBitFlips(3, 4) << endl;
    // vector<int> nums = {0};
    // auto res = subsets(nums);
    // for (auto r : res) {
    //     for (auto e : r)
    //         cout << e << " ";
    //     cout << endl;
    // }
    // vector<int> nums = {3, 3, 1, 2}, res = twoOddNum(nums);
    // auto res = getPrimeDivisors(100);
    // for (auto r : res) cout << r << " ";

    // cout << countPrimes(10) << endl;
    vector<int> res = findPrimeFactors(12246);
    for (int const &e : res) cout << e << " ";
    cout << endl;
    return 0;
}
