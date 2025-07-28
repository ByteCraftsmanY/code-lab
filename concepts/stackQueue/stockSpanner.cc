#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// https://leetcode.com/problems/online-stock-span/description/

/**
 * Stock Spanner - Online Stock Span Problem
 *
 * The StockSpanner class calculates the span of stock's price for the current
 * day. The span is defined as the maximum number of consecutive days (starting
 * from today and going backwards) for which the stock price was less than or
 * equal to today's price.
 *
 * Time Complexity: O(1) amortized per call to next()
 * Space Complexity: O(n) where n is the number of calls to next()
 */
class StockSpanner {
private:
  stack<pair<int, int>> priceStack; // {dayIndex, price}
  int currentDay;

public:
  /**
   * Constructor initializes the stock spanner
   */
  StockSpanner() : currentDay(0) {}

  /**
   * Calculate the span for the given price
   *
   * @param price The stock price for the current day
   * @return The span (number of consecutive days with price <= current price)
   */
  int next(int price) {
    // Remove all previous days with price <= current price
    // as they can't contribute to future spans
    while (!priceStack.empty() && priceStack.top().second <= price) {
      priceStack.pop();
    }

    // Calculate span: find the last greater element's day index
    int lastGreaterElementDay =
        priceStack.empty() ? -1 : priceStack.top().first;
    int span = currentDay - lastGreaterElementDay;

    // Push current day and price onto stack
    priceStack.push({currentDay, price});
    currentDay++;

    return span;
  }
};

int main() {
  cout << "=== Stock Spanner Tests ===\n\n";

  // Test Case 1: Original example
  cout << "Test Case 1: [100, 80, 60, 70, 60, 75, 85]\n";
  StockSpanner spanner1;
  vector<int> prices1 = {100, 80, 60, 70, 60, 75, 85};
  cout << "Price\tSpan\n";
  for (int price : prices1) {
    cout << price << "\t" << spanner1.next(price) << "\n";
  }
  cout << "\n";

  // Test Case 2: Increasing prices
  cout << "Test Case 2: [31, 41, 48, 59, 79] (Increasing)\n";
  StockSpanner spanner2;
  vector<int> prices2 = {31, 41, 48, 59, 79};
  cout << "Price\tSpan\n";
  for (int price : prices2) {
    cout << price << "\t" << spanner2.next(price) << "\n";
  }
  cout << "\n";

  // Test Case 3: Decreasing prices
  cout << "Test Case 3: [100, 90, 80, 70, 60] (Decreasing)\n";
  StockSpanner spanner3;
  vector<int> prices3 = {100, 90, 80, 70, 60};
  cout << "Price\tSpan\n";
  for (int price : prices3) {
    cout << price << "\t" << spanner3.next(price) << "\n";
  }
  cout << "\n";

  // Test Case 4: Same prices
  cout << "Test Case 4: [50, 50, 50, 50] (Same prices)\n";
  StockSpanner spanner4;
  vector<int> prices4 = {50, 50, 50, 50};
  cout << "Price\tSpan\n";
  for (int price : prices4) {
    cout << price << "\t" << spanner4.next(price) << "\n";
  }
  cout << "\n";

  // Test Case 5: Single element
  cout << "Test Case 5: [100] (Single element)\n";
  StockSpanner spanner5;
  vector<int> prices5 = {100};
  cout << "Price\tSpan\n";
  for (int price : prices5) {
    cout << price << "\t" << spanner5.next(price) << "\n";
  }
  cout << "\n";

  return 0;
}