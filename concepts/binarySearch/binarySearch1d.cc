#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
auto calculateMid = [](int low, int high) -> int {
    return low + (high - low) / 2;
};

// iterative
int findElementIdx(const vi &arr, int ele) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = calculateMid(low, high);
        if (arr[mid] == ele) {
            return mid;
        } else if (arr[mid] > ele) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

// recursive
int findElementIdx(const vi &arr, int ele, int low, int high) {
    if (low > high) {
        return -1;
    }
    int mid = calculateMid(low, high);
    if (arr.at(mid) == ele) {
        return mid;
    }
    return arr.at(mid) > ele ? findElementIdx(arr, ele, low, mid - 1)
                             : findElementIdx(arr, ele, mid + 1, high);
}

int findLowerBond(const vi &arr, int ele) {
    // smallest index such x >=arr[i]
    int n = arr.size(), ans = n, low = 0, high = n - 1, mid = 0;
    while (low <= high) {
        mid = calculateMid(low, high);
        if (arr[mid] >= ele) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int findUpperBond(const vi &arr, int ele) {
    // smallest index such that x > arr[i]
    int n = arr.size(), ans = n, low = 0, high = n - 1, mid = 0;
    while (low <= high) {
        mid = calculateMid(low, high);
        if (arr[mid] > ele) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int searchInsertPosition(const vi &arr, int ele) {
    return findLowerBond(arr, ele);
}

pair<int, int> findFloorAndCeil(const vi &arr, int x) {
    pair<int, int> result;
    int n = arr.size(), ans = n;
    int low = 0, high = n - 1, mid = 0;

    // find floor
    {
        while (low <= high) {
            mid = calculateMid(low, high);
            if (arr[mid] <= x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        result.first = ans == n ? -1 : arr[ans];
    }

    // find ceil
    {
        low = 0, high = n - 1, mid = 0, ans = n;
        while (low <= high) {
            mid = calculateMid(low, high);
            if (arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        result.second = ans == n ? -1 : arr[ans];
    }

    return result;
}

pair<int, int> findFirstAndLastOccuranceInSortedArray(const vi &arr, int x) {
    pair<int, int> result;
    int n = arr.size(), ans = n;
    int low = 0, high = n - 1, mid = 0;
    // first occurance
    {
        while (low <= high) {
            mid = calculateMid(low, high);
            if (arr[mid] == x) {
                ans = mid;
                high = mid - 1;
            } else if (arr[mid] > x) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        result.first = ans == n ? -1 : ans;
    }
    // last occurance
    {
        low = 0, high = n - 1, mid = 0, ans = n;
        while (low <= high) {
            mid = calculateMid(low, high);
            if (arr[mid] == x) {
                ans = mid;
                low = mid + 1;
            } else if (arr[mid] > x) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        result.second = ans == n ? -1 : ans;
    }
    return result;
}

int countOccuranceInSortedArray(const vi &arr, int x) {
    auto [first, last] = findFirstAndLastOccuranceInSortedArray(arr, x);
    return last - first + 1;
}

// unique elements
int findElementInRotatedSortedArray(const vi &arr, int target) {
    int n = arr.size(), low = 0, high = n - 1, mid = 0;
    while (low <= high) {
        mid = calculateMid(low, high);
        if (arr[mid] == target) {
            return mid;
        } else if (arr[low] <= arr[mid]) {  // left half is sorted
            if (target >= arr[low] &&
                target < arr[mid]) {  // is target in range
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {  // right half is sorted
            if (target > arr[mid] &&
                target <= arr[high]) {  // is target in range
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

// duplicates elements
bool isRotatedSortedArrayContainsElement(const vi &arr, int target) {
    int n = arr.size(), low = 0, high = n - 1, mid = 0;
    while (low <= high) {
        mid = calculateMid(low, high);
        if (arr[mid] == target) {
            return true;
        } else if (arr[low] == arr[mid] &&
                   arr[mid] == arr[high]) {  // shrink array
            low++, high--;
        } else if (arr[low] <= arr[mid]) {  // left half is sorted
            if (target >= arr[low] &&
                target < arr[mid]) {  // is target in range
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {  // right half is sorted
            if (target > arr[mid] &&
                target <= arr[high]) {  // is target in range
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return false;
}

int findMinElementInRotatedSortedArray(const vi &arr) {
    int n = arr.size(), low = 0, high = n - 1, mid = 0, minVal = INT_MAX;
    while (low <= high) {
        mid = calculateMid(low, high);
        if (arr[low] <= arr[high]) {  // if already is sorted
            minVal = min(minVal, arr[low]);
            break;
        } else if (arr[low] <= arr[mid]) {  // left is sorted
            minVal = min(minVal, arr[low]);
            low = mid + 1;
        } else {  // right is sorted
            minVal = min(minVal, arr[mid]);
            high = mid - 1;
        }
    }
    return minVal;
}

int findNumberOfRotatedItems(const vi &arr) {
    int n = arr.size(), low = 0, high = n - 1, mid = 0, minIdxVal = n - 1;
    while (low <= high) {
        mid = calculateMid(low, high);
        if (arr[low] <= arr[high]) {  // if already is sorted
            if (arr[low] < arr[minIdxVal]) {
                minIdxVal = low;
            }
            break;
        } else if (arr[low] <= arr[mid]) {  // left is sorted
            if (arr[low] < arr[minIdxVal]) {
                minIdxVal = low;
            }
            low = mid + 1;
        } else {  // right is sorted
            if (arr[mid] < arr[minIdxVal]) {
                minIdxVal = mid;
            }
            high = mid - 1;
        }
    }
    return minIdxVal;
}

int findSingleElementInSortedArray(const vi &arr) {
    int n = arr.size();
    if (n == 1) {
        return arr[0];
    } else if (arr[0] != arr[1]) {
        return arr[0];
    } else if (arr[n - 1] != arr[n - 2]) {
        return arr[n - 1];
    }
    int low = 1, high = n - 2, mid;
    while (low <= high) {
        mid = calculateMid(low, high);
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
            return arr[mid];
        } else if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) ||
                   (mid % 2 != 0 && arr[mid] == arr[mid - 1])) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int findPeakElementIdx(const vi &arr) {
    int n = arr.size();
    if ((n == 1) || (arr[0] > arr[1]))
        return 0;
    else if (arr[n - 1] > arr[n - 2])
        return n - 1;

    // brute force approach
    // for (int i = 1; i < n - 2; i++)
    //     if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) return i;

    int low = 1, high = n - 2, mid;
    while (low <= high) {
        mid = calculateMid(low, high);
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;
        else if (arr[mid] > arr[mid - 1])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int findPeakElement(const vi &arr) {
    int n = arr.size();
    if (n == 1)
        return arr[0];
    else if (arr[0] > arr[1])
        return arr[0];
    else if (arr[n - 1] > arr[n - 2])
        return arr[n - 1];

    int low = 1, high = n - 2, mid = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid]) {
            return arr[mid];
        }
        if (arr[mid - 1] < arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    // cout << findElementIdx(arr, 90);
    // cout << findElementIdx(arr, 1, 0, arr.size() - 1);
    // vi arr = {2, 7, 9, 25, 47, 47, 77, 88, 90};
    // int x = 46;
    // cout << findLowerBond(arr, x) << " "
    //      << (lower_bound(arr.begin(), arr.end(), x) - arr.begin()) << endl;
    // cout << findUpperBond(arr, x) << " "
    //      << (upper_bound(arr.begin(), arr.end(), x) - arr.begin()) << endl;
    // cout << format("insert position for ele {} is {}\n", x,
    //                searchInsertPosition(arr, x));
    // arr = {3, 4, 4, 7, 8, 10}, x = 2;
    // auto [floorVal, ceilVal] = findFloorAndCeil(arr, x);
    // cout << format("floor: {}, ceil: {}\n", floorVal, ceilVal);
    // arr = {3, 4, 13, 13, 13, 20, 40}, x = 13;
    // auto [firstOccr, lastOccr] = findFirstAndLastOccuranceInSortedArray(arr,
    // x); cout << format("firstOccr: {}, lastOccr: {}\n", firstOccr, lastOccr);
    // arr = {2, 2, 3, 3, 3, 3, 4}, x = 3;
    // cout << countOccuranceInSortedArray(arr, x) << endl;
    // arr = {7, 8, 9, 1, 2, 3, 4, 5, 6}, x = 1;
    // cout << findElementInRotatedSortedArray(arr, x);
    // arr = {7, 8, 8, 9, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 5, 6, 6}, x = 8;
    // for (int i = 0; i <= 10; i++) {
    //     cout << i << " " << isRotatedSortedArrayContainsElement(arr, i) <<
    //     endl;
    // }
    // arr = {7, 8, 9, -1, 0, 1, 2, 3, 4, 5, 6};
    // cout << findMinElementInRotatedSortedArray(arr);
    // arr = {3, 4, 5};
    // cout << findNumberOfRotatedItems(arr);
    // arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    // cout << findSingleElementInSortedArray(arr);
    // arr = {5, 4, 2};
    // cout << findPeakElementIdx(arr);
    // cout << findSquareRoot(35) << endl;
    return 0;
}
