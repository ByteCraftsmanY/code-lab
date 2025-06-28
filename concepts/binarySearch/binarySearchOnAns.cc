#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int ll;

/*
    Note: Binary Search On Answers
        when find some minimum or maximum in some range
        where some side values are valid and another are not
        either from left or right

*/

int findSquareRoot(int n) {
https:  // www.naukri.com/code360/problems/square-root-integral_893351?leftPanelTabValue=PROBLEM
    int ans = 1;
    // brute force - O(n)
    // for (int i = 1; i <= n; i++) {
    //     if (i * i <= n)
    //         ans = i;
    //     else
    //         break;
    // }

    // optimal - O(logn)
    int low = 1, high = n, mid = 0;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (mid * mid <= n) {
            ans = mid, low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int powerExponential(int n, int m) {
    int ans = 1;
    while (m > 0) {
        if (m % 2 == 0) {  // even
            n *= n;
            m /= 2;
        } else {  // odd
            ans *= n;
            m--;
        }
    }
    return ans;
}

int findNthRoot(int n, int m) {
    // https://www.naukri.com/code360/problems/nth-root-of-m_1062679?leftPanelTabValue=PROBLEM
    // for (int i = 1; i <= m; i++) {
    //     long long int ans = 1;
    //     for (int j = 1; j <= n; j++) {
    //         ans *= i;
    //     }
    //     if ((int)ans == m) {
    //         return i;
    //     } else if ((int)ans > m) {
    //         break;
    //     }
    // }

    // optimal - O(nLogm)
    int low = 1, high = m, mid = 0;
    while (low <= high) {
        double temp = m;
        mid = low + (high - low) / 2;
        for (int j = 1; j <= n; j++) {
            temp /= mid;
        }
        // cout << format("mid is {} | ans is {}\n", mid, temp);
        if (temp == 1) {
            return mid;
        } else if (temp > 1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int kokoEatingBananas(const vi &arr, int h) {
    ll ans = INT_MAX;
    ll maxEle = *max_element(arr.begin(), arr.end());
    auto getTotalHourByN = [arr](ll n) -> ll {
        ll hour = 0;
        for (int pile : arr) {
            ll val = ceil((double)pile / n);
            // cout << format("pile: {}, i: {}, h: {}\n", pile, i, div);
            hour += val;
        }
        return hour;
    };
    // brute force - O(Max(arr) * N)
    // for (int i = 1; i <= maxEle; i++) {
    //     int hour = getTotalHourByN(i);
    //     if (hour > h) {
    //         continue;
    //     } else {
    //         return i;
    //     }
    // }

    // optimal
    ll low = 1, high = maxEle;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll hour = getTotalHourByN(mid);
        if (hour <= h) {
            ans = min(mid, ans);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int minimumDaysToMakeNBouquets(const vi &arr, int m, int k) {
    int n = arr.size();
    if (n < m * k) {
        return -1;
    }

    int minEle = *min_element(arr.begin(), arr.end()),
        maxEle = *max_element(arr.begin(), arr.end());

    // for (const int &ele : tempArr) {
    //     int counter = 0;
    //     int incr = 0;
    //     for (int i = 0; i < arr.size(); i++) {
    //         if (arr[i] <= ele) {
    //             incr++;
    //         }
    //         if (incr == k) {
    //             counter++;
    //         }

    //         if (arr[i] > ele || incr >= k) {
    //             incr = 0;
    //         }
    //     }
    //     if (counter >= m) {
    //         return ele;
    //     }
    // }

    int minDays = INT_MAX;
    int low = minEle, high = maxEle;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int counter = 0;
        int incr = 0;
        int ele = mid;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= ele) {
                incr++;
            }
            if (incr == k) {
                counter++;
            }

            if (arr[i] > ele || incr >= k) {
                incr = 0;
            }
        }
        if (counter >= m) {
            minDays = min(minDays, ele);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return minDays == INT_MAX ? -1 : minDays;

    /*
        7, 7, 7, 7, 13, 11, 12, 7
        0  1  2  3
        7 11 12 13

    */
}

int findSmallestIntegerDiviser(const vi &arr, int limit) {
    auto getDiviserResult = [arr](int i) -> int {
        int ans = 0;
        for (const int &ele : arr) {
            ans += ceil((double)ele / (double)i);
        }
        return ans;
    };
    int maxEle = *max_element(arr.begin(), arr.end());

    // for (int i = 1; i <= maxEle; i++) {
    //     int divRes = getDiviserResult(i);
    //     if (divRes <= limit) {
    //         return i;
    //     }
    // }

    int low = 1, high = maxEle, mid = 0, divRes = 0;
    while (low <= high) {
        mid = low + (high - low) / 2;
        divRes = getDiviserResult(mid);
        if (divRes > limit) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
    /*
        2
        5 8
        1 2 3 4 5
        4 10
        8 4 2 3
    */
}

int shipWithinDays(const vector<int> &weights, int days) {
    int minCapacity = INT_MIN;
    int maxCapacity = 0;
    for (const int &weight : weights) {
        minCapacity = max(minCapacity, weight);
        maxCapacity += weight;
    }
    auto countDaysByCapacity = [weights](int capacity) -> int {
        int days = 0, remCap = capacity;
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] <= remCap) {
                remCap -= weights[i];
            } else {
                days++;
                remCap = capacity - weights[i];
            }
        }
        days++;
        return days;
    };

    // for (int i = minCapacity; i <= maxCapacity; i++) {
    //     int dayToComplete = countDaysByCapacity(i);
    //     if (dayToComplete <= days) {
    //         return i;
    //     }
    // }

    int low = minCapacity, high = maxCapacity, mid = 0;
    while (low <= high) {
        mid = low + (high - low) / 2;
        int daysToComplete = countDaysByCapacity(mid);
        if (daysToComplete <= days) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;

    /*
        2
        8 5
        5 4 5 2 3 4 5 6
        10 5
        1 2 3 4 5 6 7 8 9 10
    */
}

int findKthPositive(const vector<int> &arr, int k) {
    // unordered_set<int> st(arr.begin(), arr.end());
    // int i = 1;
    // while (k > 0) {
    //     if (!st.contains(i)) k--;
    //     i++;
    // }
    // return i - 1;

    // int i = 1, p = 0, n = arr.size();
    // while (k > 0 && p < n) {
    //     if (arr[p] == i) {
    //         p++;
    //     } else {
    //         k--;
    //     }
    //     i++;
    // }
    // while (k > 0) i++, k--;
    // return i - 1;

    // for (int i = 0; i < arr.size(); i++) {
    //     if (arr[i] <= k) {
    //         k += (k - arr[i] + 1);
    //     } else {
    //         break;
    //     }
    // }
    // return k;

    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing >= k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low + k;

    /*
        2
        4 1
        4 7 9 10
        4 4
        4 7 9 10
    */
}

int aggrasiveCows(vi &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    auto getMaxCowThatCanBeArrangedWithGivenDist = [stalls](int dist) -> int {
        int ans = 1;
        int prev = stalls[0];
        for (int i = 1; i < stalls.size(); i++) {
            if (prev + dist <= stalls[i]) {
                prev = stalls[i];
                ans++;
            }
        }
        return ans;
    };
    int maxDist = stalls.back() - stalls.front();

    // for (int i = maxDist; i >= 2; i--) {
    //     int cowCount = getMaxCowThatCanBeArrangedWithGivenDist(i);
    //     if (cowCount >= k) {
    //         return i;
    //     }
    // }

    int low = 2, high = maxDist;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cowCount = getMaxCowThatCanBeArrangedWithGivenDist(mid);
        if (cowCount >= k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high;
    /*
        2
        6 4
        0 3 4 7 10 9
        5 2
        4 2 1 3 6
    */
}

int findPages(vector<int> &arr, int n, int m) {
    if (n < m) {
        return -1;
    }
    auto calculateStudents = [arr, n](int pages) -> int {
        int student = 1, pageCount = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] + pageCount <= pages) {
                pageCount += arr[i];
            } else {
                student++;
                pageCount = arr[i];
            }
        }
        return student;
    };
    int minRange = INT_MIN, maxRange = 0;
    for (const int &ele : arr) {
        minRange = max(minRange, ele), maxRange += ele;
    }

    // for (int page = minRange; page <= maxRange; page++) {
    //     int students = calculateStudents(page);
    //     if (students == m) {
    //         return page;
    //     }
    // }
    // return minRange;

    int low = minRange, high = maxRange;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int students = calculateStudents(mid);
        if (students <= m) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
    /*
        3
        4 2
        12 34 67 90
        5 4
        25 46 28 49 24
        835 591
        3 7 9 9 9 10 3 2 2 8 6 5 9 8 3 7 9 1 4 8 10 5 10 8 2 1 10 4 10 2 4 7 10
       2 2 9 9 5 2 3 1 7 10 3 9 8 10 2 7 5 10 3 9 8 4 5 7 5 5 6 2 7 5 5 1 4 1 1
       7 6 6 8 2 2 1 1 2 8 10 8 3 10 9 6 7 8 3 3 1 6 2 6 7 10 2 6 6 2 2 3 7 6 8
       3 10 1 6 3 4 5 4 4 2 6 2 1 9 4 1 9 1 7 4 9 6 3 8 1 7 6 5 9 1 7 5 10 2 1 6
       8 2 10 9 10 1 8 6 4 8 2 1 6 6 5 7 3 8 3 8 3 5 2 5 9 7 6 7 6 4 6 7 8 8 9 8
       7 2 9 2 6 4 1 4 2 1 9 1 4 9 9 3 10 4 8 2 5 10 5 10 2 1 2 5 1 8 3 5 10 2 1
       1 3 1 5 4 9 1 5 6 4 6 6 8 1 5 6 7 6 2 9 8 6 6 9 7 3 4 6 8 2 4 4 1 4 6 1 3
       5 10 5 3 2 1 1 7 8 1 3 5 10 9 10 6 3 2 4 7 9 8 3 8 1 9 10 10 7 1 8 6 4 5
       5 7 2 2 10 9 10 2 4 9 10 2 2 2 3 8 6 10 8 4 1 4 9 6 9 6 1 3 5 7 3 5 9 8 9
       3 3 5 8 5 10 8 3 7 9 5 2 8 5 10 10 1 10 1 2 4 7 3 6 10 5 9 8 7 3 8 4 6 9
       7 8 4 1 4 6 5 9 6 5 3 7 5 1 10 9 4 9 8 6 4 6 7 3 5 7 2 1 7 8 7 10 10 9 7
       3 9 8 9 1 10 2 4 10 8 7 4 5 3 3 5 10 2 4 4 8 9 2 6 10 3 7 10 9 3 5 1 5 10
       10 10 10 3 2 8 9 8 10 1 9 9 9 5 7 6 5 2 7 10 10 4 6 6 2 7 9 2 4 2 4 6 10
       10 7 4 1 3 3 1 3 3 3 4 3 1 1 4 7 8 7 2 10 4 4 4 4 2 3 8 10 7 7 4 7 7 9 2
       1 5 9 9 7 9 10 10 7 1 8 7 3 3 4 2 3 4 7 10 2 7 9 3 3 4 10 5 9 9 2 7 6 8 5
       9 6 1 7 1 10 7 2 1 3 7 7 8 2 8 9 7 2 8 1 4 3 9 10 7 6 1 2 3 8 6 6 3 10 2
       1 10 10 2 10 3 9 7 3 9 7 10 7 5 1 10 10 2 8 3 9 6 8 1 4 7 1 4 2 3 9 8 10
       9 10 4 9 1 4 8 10 4 8 4 4 10 2 5 2 8 1 1 8 6 3 2 7 2 8 5 10 9 7 6 3 7 6
       10 1 1 7 6 4 1 3 6 3 5 6 10 6 1 6 2 7 7 8 10 5 8 3 9 6 8 7 6 6 3 3 1 6 8
       9 8 2 7 3 2 3 3 6 5 9 4 8 2 10 4 8 1 8 7 5 4 10 1 3 1 7 7 9 5 9 5 9 7 3 2
       2 5 7 6 7 6 6 5 3 5 6 9 3 10 8 2 4 1 2 1 8 2 2 2 4 4 5 5 2 2 8 8 3 10 10
       1 10 4 2 5 3 9 10 4 2 3 9 4 9 9 6 1 7 10 7 7 10 2 9 3 3 9 6 8 6 3 7 7 7 1
       5 2 5 3 9 8 1 8 2 6 8 7 6 1 1 4 3 8 6 2 1 5 10 8 10 7 2 7 2 9 9 3 10 3 5
       7 1 6 9 10 10 10 9 5 9 3 10 9 6 7 6 4 2 6 2 9 2 8 4 6 10 6 9 3 7 8 3 3 3
       7
    */
}

int splitArray(vector<int> &nums, int k) {
    int n = nums.size();
    if (n < k) {
        return -1;
    }
    auto calculateSubarrays = [nums, n](int limit) -> int {
        int subArrayCount = 1, sum = 0;
        for (int i = 0; i < n; i++) {
            if ((sum + nums[i]) <= limit) {
                sum += nums[i];
            } else {
                subArrayCount++;
                sum = nums[i];
            }
        }
        return subArrayCount;
    };
    int minRange = INT_MIN, maxRange = 0;
    for (auto num : nums) {
        minRange = max(num, minRange), maxRange += num;
    }
    // for (int i = minRange; i <= maxRange; i++) {
    //     int count = calculateSubarrays(i);
    //     if (count == k) {
    //         return i;
    //     }
    // }
    // return minRange;

    int low = minRange, high = maxRange, mid = 0;
    while (low <= high) {
        mid = low + (high - low) / 2;
        int count = calculateSubarrays(mid);
        if (count <= k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;

    /*
        2
        5 2
        7 2 5 10 8
        5 2
        1 2 3 4 5
    */
}

int findLargestMinDistance(const vector<int> &boards, int k) {
    auto calculatePaintersByTime = [boards](int time) -> int {
        int painter = 1, boardLen = 0;
        for (auto const board : boards) {
            if ((boardLen + board) <= time) {
                boardLen += board;
            } else {
                painter++, boardLen = board;
            }
        }
        return painter;
    };
    int minRange = INT_MIN, maxRange = 0;
    for (auto const board : boards) {
        minRange = max(board, minRange);
        maxRange += board;
    }

    // for (int i = minRange; i <= maxRange; i++) {
    //     int painters = calculatePaintersByTime(i);
    //     if (painters == k) {
    //         return i;
    //     }
    // }
    // return minRange;

    int low = minRange, high = maxRange, mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        int painters = calculatePaintersByTime(mid);
        if (painters <= k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;

    /*
        3
        4 2
        5 5 5 5
        4 2
        10 20 30 40
        2 2
        48 90
    */
}

double minimiseMaxDistance(vector<int> &arr, int k) {
    // bruteForce
    // timeComplexity: O(n*k) + O(n-1)
    // spaceComplexity: O(n-1)
    // int n = arr.size();
    // vector<int> howManyStations = vector<int>(n - 1, 0);
    // for (int i = 0; i < k; i++) {
    //     long double maxDist = INT_MIN;
    //     int index = -1;
    //     for (int j = 0; j < n - 1; j++) {
    //         long double diff = (long double)(arr[j + 1] - arr[j]) /
    //                            (long double)(howManyStations[j] + 1);
    //         if (diff > maxDist) {
    //             maxDist = diff, index = j;
    //         }
    //     }
    //     howManyStations[index]++;
    // }
    // long double maxDis = INT_MIN;
    // for (int i = 0; i < n - 1; i++) {
    //     long double dist = (long double)(arr[i + 1] - arr[i]) /
    //                        (long double)(howManyStations[i] + 1);
    //     maxDis = max(maxDis, dist);
    // }
    // return maxDis;

    // better
    // timeComplexity: O(klog(n) + nlogn) + O(n-1) + O(n-1)
    // spaceComplexity: O(n-1)
    // int n = arr.size();
    // vector<int> howManyStations = vector<int>(n - 1, 0);
    // priority_queue<pair<long double, int>> pq;
    // for (int i = 0; i < n - 1; i++) {
    //     pq.push({arr[i + 1] - arr[i], i});
    // }
    // for (int i = 0; i < k; i++) {
    //     auto [maxDist, index] = pq.top();
    //     pq.pop();
    //     howManyStations[index]++;
    //     long double dist = (long double)(arr[index + 1] - arr[index]) /
    //                        (long double)(howManyStations[index] + 1);
    //     pq.push({dist, index});
    // }
    // return pq.top().first;

    // timeComplexity: O(log(maxdist))
    // spaceComplexity: O(1)
    int n = arr.size();
    auto countGasStations = [arr, n](long double dist) -> int {
        int counter = 0;
        for (int i = 0; i < n - 1; i++) {
            int dif = (arr[i + 1] - arr[i]);
            int count = dif / dist;
            if (count * dist == dif) {
                /*
                    2-1 = 1/0.5 should be 1 as we can only keep 1 station
                    but division will give 2 so we decrease value by 1
                 */
                count--;
            }
            counter += count;
        }
        return counter;
    };
    long double low = 0, high = INT_MIN;
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }
    long double maxDiff = 1e-6;
    while (high - low > maxDiff) {
        long double mid = low + ((high - low) / 2);
        int requriedGasStations = countGasStations(mid);
        if (requriedGasStations > k) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return high;

    /*
    2
    4 4
    1 13 17 23
    5 4
    1 2 3 4 5

    4
    0.5
    */
}

float medianOfTwoSortedArray(const vi &arr1, const vi &arr2) {
    /*
        better solution
        Time:
        Space:
     */

    /*
        int n1 = arr1.size(), n2 = arr2.size(), n = n1 + n2;
        int itr = -1, i = 0, j = 0;
        bool isOdd = n & 1 != 0;
        int medIdx = n / 2, prevVal = 0, sum = 0;
        while (i < n1 && j < n2) {
            if (arr1[i] <= arr2[j]) {
                prevVal = arr1[i++];
            } else {
                prevVal = arr2[j++];
            }
            itr++;
            if (isOdd && itr == medIdx) {
                return prevVal;
            } else if (!isOdd && itr == medIdx || itr == medIdx - 1) {
                sum += prevVal;
            }
        }
        while (i < n1) {
            prevVal = arr1[i++], itr++;
            if (isOdd && itr == medIdx) {
                return prevVal;
            } else if (!isOdd && itr == medIdx || itr == medIdx - 1) {
                sum += prevVal;
            }
        }
        while (j < n2) {
            prevVal = arr2[j++], itr++;
            if (isOdd && itr == medIdx) {
                return prevVal;
            } else if (!isOdd && itr == medIdx || itr == medIdx - 1) {
                sum += prevVal;
            }
        }

        return (float)sum / 2;
    */

    /*
        Optimal Solution using Binary Search
        Time: log(min(n1, n2))
        Space: O(1)
     */
    int n1 = arr1.size(), n2 = arr2.size(), n = n1 + n2;
    if (n1 > n2) return medianOfTwoSortedArray(arr2, arr1);
    int low = 0, high = n1;
    int leftLen = (n + 1) / 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        if (mid - 1 >= 0) l1 = arr1[mid - 1];
        if (mid < n1) r1 = arr1[mid];
        if ((leftLen - mid - 1) >= 0) l2 = arr2[leftLen - mid - 1];
        if ((leftLen - mid) < n2) r2 = arr2[leftLen - mid];

        if (l1 <= r2 && l2 <= r1) {
            if (n & 1 != 0) {
                return max(l1, l2);
            }
            return double(max(l1, l2) + min(r1, r2)) / 2.0;
        } else if (l2 > r1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;

    /*
    2
    3 3
    1 3 5
    2 4 6
    2 2
    1 2
    3 4

    3.5
    2.5
    */
}

int findKthElementInTwoSortedArray(const vi &arr1, const vi &arr2, int k) {
    int n1 = arr1.size(), n2 = arr2.size(), n = n1 + n2;
    if (n1 > n2) return medianOfTwoSortedArray(arr2, arr1);
    int low = max(0, k - n2), high = min(k, n1);
    int leftLen = k;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        if (mid - 1 >= 0) l1 = arr1[mid - 1];
        if (mid < n1) r1 = arr1[mid];
        if ((leftLen - mid - 1) >= 0) l2 = arr2[leftLen - mid - 1];
        if ((leftLen - mid) < n2) r2 = arr2[leftLen - mid];

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        } else if (l2 > r1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;
}

int main() {
    // int n;
    // cin >> n;
    // cout << findSquareRoot(n);
    // int n = 3, m = 4;
    // int result = powerExponential(n, m);
    // cout << result;
    // return 0;

    // vi arr = {7, 7, 7, 7, 13, 11, 12, 7};
    // int m = 2, k = 3;
    // cout << minimumDaysToMakeNBouquets(arr, m, k) << endl;
    // return 0;
    // cout << medianOfTwoSortedArray({1, 2, 3, 7}, {3, 9, 12, 15, 17})
    //      << endl;
    // return 0;
    // cout << findKthElementInTwoSortedArray({1, 2, 3, 7}, {3, 9, 12, 15, 17},
    // 6)
    //      << endl;
    // return 0;

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        // // cout << findNthRoot(n, m) << endl;
        // int result = powerExponential(n, m);
        // cout << n << " ^ " << m << " = " << result << endl;

        // int n, h;
        // cin >> n >> h;
        vi arr(n, 0);
        for (auto &x : arr) cin >> x;
        // cout << kokoEatingBananas(arr, h) << "\n";

        // vi arr = {7, 7, 7, 7, 13, 11, 12, 7};
        // int m = 2, k = 3;
        // cout << minimumDaysToMakeNBouquets(arr, m, k) << endl;

        // cout << findSmallestIntegerDiviser(arr, m) << endl;
        // cout << shipWithinDays(arr, m) << endl;
        // cout << findKthPositive(arr, m) << endl;
        // cout << aggrasiveCows(arr, m) << endl;
        // cout << findPages(arr, n, m) << endl;
        // cout << splitArray(arr, m) << endl;
        // cout << findLargestMinDistance(arr, m) << endl;
        // cout << minimiseMaxDistance(arr, m) << endl;
        vi arr2(m, 0);
        for (auto &x : arr2) cin >> x;
        cout << medianOfTwoSortedArray(arr, arr2) << endl;
    }

    return 0;
}