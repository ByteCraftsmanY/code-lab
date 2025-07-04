#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/**
 * Check if a string contains balanced parentheses, brackets, and braces
 * @param expression The string to check
 * @return true if balanced, false otherwise
 */
bool isBalanced(const string &expression) {
  stack<char> parenthesesStack;
  unordered_set<char> openingBrackets = {'(', '{', '['};
  unordered_map<char, char> closingToOpening = {
      {')', '('}, {']', '['}, {'}', '{'}};

  for (char bracket : expression) {
    // If it's an opening bracket, push to stack
    if (openingBrackets.find(bracket) != openingBrackets.end()) {
      parenthesesStack.push(bracket);
      continue;
    }

    // If it's a closing bracket, check if it matches the top of stack
    if (parenthesesStack.empty() ||
        closingToOpening[bracket] != parenthesesStack.top()) {
      return false;
    }

    parenthesesStack.pop();
  }

  // Stack should be empty for balanced expression
  return parenthesesStack.empty();
}

int main() {
  int testCases;
  cout << "Enter number of test cases: ";
  cin >> testCases;
  cin.ignore(); // Clear the newline from input buffer

  while (testCases--) {
    string expression;
    cout << "Enter expression: ";
    getline(cin, expression);

    bool result = isBalanced(expression);
    cout << "Expression: \"" << expression << "\" is ";
    cout << (result ? "balanced" : "not balanced") << endl;
  }

  return 0;
}