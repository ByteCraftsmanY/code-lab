#include <iostream>

using namespace std;

int sum(int a, int b) {
  // Most efficient approach - works with all numbers including negatives
  while (b != 0) {
    int carry = a & b;
    a = a ^ b;
    b = carry << 1;
  }
  return a;
}

int main() {
  // Test case
  int a = 5, b = 3;
  cout << "Sum: " << sum(a, b) << endl;

  return 0;
}