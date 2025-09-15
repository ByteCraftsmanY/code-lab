#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)

int binarySearch(vector<int> arr, int m, long long k) {
  int n = arr.size(), low = 0, high = n - 1, mid = 0;
  while (low <= high) {
    mid = low + ((high - low) / 2);
    long long res = (long long)(arr[mid] * m);
    if (res >= k)
      high = mid - 1;
    else if (res < k)
      low = mid + 1;
  }
  return n - low;
}

vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                            long long success) {
  sort(all(potions));
  vector<int> result;
  result.reserve(spells.size());
  for (auto s : spells) {
    result.push_back(binarySearch(potions, s, success));
  }
  return result;
}

int main() {
  vector<int> arr = {5, 1, 3}, arr2 = {1, 2, 3, 4, 5}, res;
  int k = 7;
  res = successfulPairs(arr, arr2, k);
  for (int i : res)
    cout << i << " ";
  return 0;
}