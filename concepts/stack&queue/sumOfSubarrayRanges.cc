#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * Brute force approach to find sum of subarray ranges
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 */
long long subArrayRangesBruteForce(vector<int> &nums) {
  long long sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    int minEle = nums[i], maxEle = nums[i];
    for (int j = i; j < nums.size(); j++) {
      minEle = min(nums[j], minEle);
      maxEle = max(nums[j], maxEle);
      sum += (maxEle - minEle);
    }
  }
  return sum;
}

/**
 * Find previous smaller element for each position using monotonic stack
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
vector<int> findPreviousSmaller(vector<int> &arr) {
  int n = arr.size();
  vector<int> result(n, -1);
  stack<int> st;

  for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] >= arr[i]) {
      st.pop();
    }
    if (!st.empty()) {
      result[i] = st.top();
    }
    st.push(i);
  }
  return result;
}

/**
 * Find next smaller element for each position using monotonic stack
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
vector<int> findNextSmaller(vector<int> &arr) {
  int n = arr.size();
  vector<int> result(n, n);
  stack<int> st;

  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && arr[st.top()] > arr[i]) {
      st.pop();
    }
    if (!st.empty()) {
      result[i] = st.top();
    }
    st.push(i);
  }
  return result;
}

/**
 * Find previous greater element for each position using monotonic stack
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
vector<int> findPreviousGreater(vector<int> &arr) {
  int n = arr.size();
  vector<int> result(n, -1);
  stack<int> st;

  for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] <= arr[i]) {
      st.pop();
    }
    if (!st.empty()) {
      result[i] = st.top();
    }
    st.push(i);
  }
  return result;
}

/**
 * Find next greater element for each position using monotonic stack
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
vector<int> findNextGreater(vector<int> &arr) {
  int n = arr.size();
  vector<int> result(n, n);
  stack<int> st;

  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && arr[st.top()] < arr[i]) {
      st.pop();
    }
    if (!st.empty()) {
      result[i] = st.top();
    }
    st.push(i);
  }
  return result;
}

/**
 * Calculate sum of all subarray minimums using monotonic stack
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
long long sumSubarrayMins(vector<int> &arr) {
  int n = arr.size();
  vector<int> prevSmaller = findPreviousSmaller(arr);
  vector<int> nextSmaller = findNextSmaller(arr);

  long long sum = 0;
  for (int i = 0; i < n; i++) {
    long long left = i - prevSmaller[i];
    long long right = nextSmaller[i] - i;
    sum += (long long)arr[i] * left * right;
  }
  return sum;
}

/**
 * Calculate sum of all subarray maximums using monotonic stack
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
long long sumSubarrayMaxs(vector<int> &arr) {
  int n = arr.size();
  vector<int> prevGreater = findPreviousGreater(arr);
  vector<int> nextGreater = findNextGreater(arr);

  long long sum = 0;
  for (int i = 0; i < n; i++) {
    long long left = i - prevGreater[i];
    long long right = nextGreater[i] - i;
    sum += (long long)arr[i] * left * right;
  }
  return sum;
}

/**
 * Optimized approach to find sum of subarray ranges
 * Uses the formula: sum of maximums - sum of minimums
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
long long subArrayRangesOptimized(vector<int> &nums) {
  return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
}

/**
 * Main function to test the optimized solution
 */
int main() {
  // Test case 1: Simple array
  vector<int> test1 = {1, 2, 3};
  cout << "Test 1: [1, 2, 3]" << endl;
  cout << "Brute force: " << subArrayRangesBruteForce(test1) << endl;
  cout << "Optimized: " << subArrayRangesOptimized(test1) << endl;
  cout << endl;

  // Test case 2: Array with duplicates
  vector<int> test2 = {1, 3, 3};
  cout << "Test 2: [1, 3, 3]" << endl;
  cout << "Brute force: " << subArrayRangesBruteForce(test2) << endl;
  cout << "Optimized: " << subArrayRangesOptimized(test2) << endl;
  cout << endl;

  // Test case 3: Large array
  vector<int> test3 = {
      9911,   -90135, -89738, 35019,  -56095, -18837, -81924, 96768,  83709,
      42105,  49101,  -83708, 29516,  33928,  -5479,  -44214, -22153, -76747,
      -99356, 76807,  -12231, 46985,  -12087, 21060,  43150,  -23670, -23204,
      -65344, 81818,  76776,  30956,  18479,  -44424, -76224, -87457, -96291,
      94823,  -39334, -43175, -29222, 20058,  -44259, -95096, 14744,  38890,
      96360,  10996,  70237,  -22899, 46971,  93496,  55180,  32236,  98831,
      -14677, 39989,  -1402,  -67256, -52962, -604,   62508,  -68350, -12018,
      -17920, -54431, 93459,  -15339, 6145,   -10386, -75337, -84230, -79745,
      73742,  -87198, -65921, -63230, -68034, 60918,  69939,  93521,  45833,
      -75382, 38376,  -8957,  -44605, 1517,   78042,  -30046, -51203, 1268,
      64486,  -88572, 78765,  -43640, 22977,  35918,  -60240, -6190,  -24904,
      66546,  56998,  56506,  -84878, -25106, 53291,  25918,  -73575, 13181,
      22302,  54475,  -76365, -1235,  -39069, 8193,   -35294, -24390, 26334,
      -33051, 10653,  30843,  -42931, -73080, 74495,  -58822, -89474, -58196,
      39872,  -82220, 4470,   -87717, -7033,  73446,  30723,  52996,  97766,
      -80240, -96249, -71354, -2716,  66330,  -57731, -4861,  77914,  -75169,
      15435,  36157,  -31931, 37208,  31071,  -77016, 66022,  -83770, 78090,
      26773,  -3918,  -87435, -72431, 12594,  70775,  -64570, 6119,   -49410,
      -96924, -18961, 40174,  -78097, 73845,  88870,  94993,  66352,  -30670,
      65667,  -47589, 49699,  11263,  69895,  -48291, -40686, -65865, 96078,
      54011,  57242,  619,    97356,  7051,   -42711, 40022,  -22064, -63468,
      -60426, -76583, -88342, 71161,  3485,   39743,  -99920, -19040, -53913,
      -11736, 63224,  -88721, 35258,  -41322, 24492,  29518,  91582,  -94250,
      -26142, -3023,  90755,  97269,  92330,  1596,   -2177,  -21206, 72675,
      42519,  -79034, -39951, -78073, -58455, -72284, 66996,  -72352, 81964,
      73171,  2110,   -2433,  -52821, -3283,  -54448, 41248,  67560};
  cout << "Test 3: Large array" << endl;
  cout << "Optimized result: " << subArrayRangesOptimized(test3) << endl;

  return 0;
}