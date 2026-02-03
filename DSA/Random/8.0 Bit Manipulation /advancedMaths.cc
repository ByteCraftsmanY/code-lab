#include <bits/stdc++.h>
using namespace std;

bool isPrimeNumber(int n) {
    if (n <= 1)
        return false;
    else if (n <= 3)
        return true;

    int sq = sqrt(n);
    for (int i = 2; i <= sq; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// https://www.geeksforgeeks.org/problems/prime-factors5052/1
vector<int> getPrimeDivisors(int n) {
    vector<int> divisors;

    /*
        // O(n)
        for (int i = 2; i <= n; i++) {
            if (n % i == 0 && isPrimeNumber(i)) {
                divisors.push_back(i);
            }
        }
    */

    /*
        // O(n! * 2(n!))
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                if (isPrimeNumber(i)) {
                    divisors.push_back(i);
                }
                int div = n / i;
                if (i != div && isPrimeNumber(div)) {
                    divisors.push_back(div);
                }
            }
        }
    */

    // O(sqrt(n))
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i != 0) {
            continue;
        }
        while (n % i == 0) {
            n /= i;
        }
        divisors.push_back(i);
    }
    if (n != 1) {
        divisors.push_back(n);
    }

    return divisors;
}

vector<int> getAllDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            int div = n / i;
            if (div != i) {
                divisors.push_back(div);
            }
        }
    }
    return divisors;
}

// Sieve of Eratosthenes
// TC: O(n * log(log(n)))
// SC: O(n)
vector<int> getPrimeNumbers(int n) {
    vector<int> results;
    vector<bool> prime(n + 1, true);
    for (int i = 2; i * i <= n; i++) {
        if (!prime[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            prime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (!prime[i]) continue;
        results.push_back(i);
    }
    return results;
}

// https://www.geeksforgeeks.org/problems/prime-factorization-using-sieve/1
vector<vector<int>> primeFactors(vector<int>& queries) {
    // O(n * log(log(n)))
    int maxSize = 10e5 + 1;  //*max_element(queries.begin(), queries.end());
    vector<int> smallestPossiblePrimeFector(maxSize, 0);
    for (int i = 0; i < maxSize; i++)
        smallestPossiblePrimeFector[i] = i;

    for (int i = 2; i * i < maxSize; i++) {
        if (smallestPossiblePrimeFector[i] != i)
            continue;
        for (int j = i * i; j < maxSize; j += i) {
            if (smallestPossiblePrimeFector[j] == j)
                smallestPossiblePrimeFector[j] = i;
        }
    }

    // O(q * log(n))
    vector<vector<int>> results(queries.size(), vector<int>());
    for (int i = 0; i < queries.size(); i++) {
        int n = queries.at(i);
        while (n != 1) {
            results[i].push_back(smallestPossiblePrimeFector[n]);
            n /= smallestPossiblePrimeFector[n];
        }
    }
    return results;
}

// TC: O(log(n)) | SC: O(1)
double powerExponential(double n, long long p) {
    if (p == 0) {
        return 1;
    } else if (p < 0) {  // - power
        return 1 / powerExponential(n, p * -1);
    } else if (p & 1) {  // odd
        return n * powerExponential(n, p - 1);
    }
    return powerExponential(n * n, p / 2);
}

int main() {
    // for (int i = 0; i <= 60; i++) {
    //     cout << i << " " << (isPrimeNumber(i) ? "true" : "false") << endl;
    // }
    // int t;
    // cin >> t;
    // while (t--) {
    // int n;
    // cin >> n;
    // auto results = getPrimeDivisors(n);
    // auto results = getAllDivisors(n);
    // auto results = getPrimeNumbers(n);
    // for (auto const& x : results) {
    //     cout << x << " ";
    // }
    // cout << endl;
    // }
    // vector<int> nums = {2, 3, 4, 5, 6, 7, 12, 18};
    // auto results = primeFactors(nums);
    // for (int i = 0; i < nums.size(); i++) {
    //     cout << nums[i] << " : ";
    //     for (auto x : results[i]) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    cout << powerExponential(5, -2) << endl;
    return 0;
}
