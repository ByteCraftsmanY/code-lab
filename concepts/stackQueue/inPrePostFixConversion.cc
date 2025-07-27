#include <cctype>
#include <iostream>
#include <memory>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

// Abstract base class for all expression converters
class Converter {
public:
  virtual string convert(string) = 0;
  virtual void runTests() = 0;
  virtual ~Converter() = default;
};

// Parent utility class providing common functionality for expression conversion
class ExpressionConverter {
protected:
  // Helper functions to check character types
  bool isOperand(char c) { return isdigit(c) || isalpha(c); }

  bool isOpeningBracket(char c) { return c == '('; }

  bool isClosingBracket(char c) { return c == ')'; }

  // Get operator priority for precedence comparison
  int getPriority(char c) {
    unordered_map<char, int> priority = {
        {'^', 3}, {'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}};
    return priority[c];
  }

  // Helper function to add parentheses when needed based on operator precedence
  string addParentheses(string left, char op, string right) {
    // Check if left operand needs parentheses
    bool leftNeedsParens = needsParentheses(left, op, true);
    // Check if right operand needs parentheses
    bool rightNeedsParens = needsParentheses(right, op, false);

    string result = "";
    if (leftNeedsParens) {
      result += "(" + left + ")";
    } else {
      result += left;
    }

    result += op;

    if (rightNeedsParens) {
      result += "(" + right + ")";
    } else {
      result += right;
    }

    return result;
  }

  // Check if operand needs parentheses based on operator precedence
  bool needsParentheses(string operand, char currentOp, bool isLeftOperand) {
    if (operand.length() == 1) {
      return false; // Single operand doesn't need parentheses
    }

    // Find the main operator in the operand
    char mainOp = findMainOperator(operand);
    if (mainOp == '\0') {
      return false;
    }

    int currentPriority = getPriority(currentOp);
    int mainPriority = getPriority(mainOp);

    // For left associativity (most operators)
    if (currentOp != '^') {
      return mainPriority < currentPriority;
    } else {
      // For right associativity (exponentiation)
      return mainPriority <= currentPriority;
    }
  }

  // Find the main operator in a string (simplified)
  char findMainOperator(string expr) {
    int parenCount = 0;
    for (int i = 0; i < expr.length(); i++) {
      if (expr[i] == '(') {
        parenCount++;
      } else if (expr[i] == ')') {
        parenCount--;
      } else if (parenCount == 0 &&
                 (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' ||
                  expr[i] == '/' || expr[i] == '^')) {
        return expr[i];
      }
    }
    return '\0';
  }

public:
  virtual ~ExpressionConverter() = default;
};

// Derived class for infix to postfix conversion
class InfixToPostfixConverter : public Converter, public ExpressionConverter {
public:
  // Convert infix expression to postfix using stack-based algorithm
  string convert(string infix) {
    int i = 0;
    stack<char> st;
    string result = "";

    while (i < infix.size()) {
      if (isOperand(infix[i])) {
        // If character is operand, add to result
        result += infix[i];
      } else if (isOpeningBracket(infix[i])) {
        // If character is opening bracket, push to stack
        st.push(infix[i]);
      } else if (isClosingBracket(infix[i])) {
        // If character is closing bracket, pop until opening bracket
        while (!st.empty() && st.top() != '(') {
          char c = st.top();
          st.pop();
          result += c;
        }
        st.pop(); // Remove the opening bracket
      } else {
        // If character is operator, handle precedence
        while (!st.empty() && getPriority(st.top()) >= getPriority(infix[i])) {
          char c = st.top();
          st.pop();
          result += c;
        }
        st.push(infix[i]);
      }
      i++;
    }

    // Pop remaining operators from stack
    while (!st.empty()) {
      result += st.top();
      st.pop();
    }

    return result;
  }

  // Test the converter with predefined test cases
  void runTests() {
    // Test cases for infix to postfix conversion
    unordered_map<string, string> testCases = {
        {"a+b*(c^d-e)^(f+g*h)-i", "abcd^e-fgh*+^*+i-"},
        {"(p+q)*(m-n)", "pq+mn-*"}};

    cout << "Testing Infix to Postfix Conversion:" << endl;
    cout << "====================================" << endl;

    for (auto [infix, expected] : testCases) {
      string result = convert(infix);
      bool isCorrect = (result == expected);

      cout << "Infix: " << infix << endl;
      cout << "Expected Postfix: " << expected << endl;
      cout << "Actual Postfix: " << result << endl;
      cout << "Result: " << (isCorrect ? "✓ PASS" : "✗ FAIL") << endl;
      cout << endl;
    }
  }
};

// Derived class for infix to prefix conversion
class InfixToPrefixConverter : public Converter, public ExpressionConverter {
private:
  // Helper function to change bracket sequence
  void changeBracketSeq(string &s, int idx) {
    if (s[idx] == '(') {
      s[idx] = ')';
    } else if (s[idx] == ')') {
      s[idx] = '(';
    }
  }

  // Reverse string and swap brackets
  void reverse(string &s) {
    int l = 0, h = s.size() - 1;
    while (l < h) {
      swap(s[l], s[h]);
      changeBracketSeq(s, l);
      changeBracketSeq(s, h);
      l++, h--;
    }
    // Handle middle character for odd length strings
    if (l == h) {
      changeBracketSeq(s, l);
    }
  }

public:
  // Convert infix expression to prefix using reverse and stack approach
  string convert(string s) {
    string result = "";
    stack<char> st;
    int i = 0;

    // Create a copy to avoid modifying the original string
    string input = s;
    cout << "Original string: " << input << endl;
    reverse(input);
    cout << "Reversed string: " << input << endl;

    while (i < input.size()) {
      if (isOperand(input[i])) {
        result += input[i];
      } else if (isOpeningBracket(input[i])) {
        st.push(input[i]);
      } else if (isClosingBracket(input[i])) {
        while (!st.empty() && st.top() != '(') {
          result += st.top();
          st.pop();
        }
        st.pop(); // Remove the opening bracket
      } else {
        // Handle operator precedence for exponentiation and other operators
        if (input[i] == '^') {
          // For exponentiation: pop operators with equal or higher precedence
          while (!st.empty() &&
                 getPriority(input[i]) <= getPriority(st.top())) {
            result += st.top();
            st.pop();
          }
        } else {
          // For other operators: pop operators with higher precedence only
          while (!st.empty() && getPriority(input[i]) < getPriority(st.top())) {
            result += st.top();
            st.pop();
          }
        }
        st.push(input[i]);
      }
      i++;
    }

    // Pop remaining operators from stack
    while (!st.empty()) {
      result += st.top();
      st.pop();
    }

    // Reverse the result to get prefix
    reverse(result);
    return result;
  }

  // Test the converter with comprehensive test cases
  void runTests() {
    cout << "Testing Infix to Prefix Conversion:" << endl;
    cout << "===================================" << endl;

    // Test case 1: Simple addition
    string test1 = "a+b";
    string expected1 = "+ab";
    string result1 = convert(test1);
    cout << "Infix: " << test1 << endl;
    cout << "Expected Prefix: " << expected1 << endl;
    cout << "Actual Prefix: " << result1 << endl;
    cout << "Result: " << (result1 == expected1 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 2: Simple multiplication
    string test2 = "a*b";
    string expected2 = "*ab";
    string result2 = convert(test2);
    cout << "Infix: " << test2 << endl;
    cout << "Expected Prefix: " << expected2 << endl;
    cout << "Actual Prefix: " << result2 << endl;
    cout << "Result: " << (result2 == expected2 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 3: Expression with parentheses
    string test3 = "(a+b)*c";
    string expected3 = "*+abc";
    string result3 = convert(test3);
    cout << "Infix: " << test3 << endl;
    cout << "Expected Prefix: " << expected3 << endl;
    cout << "Actual Prefix: " << result3 << endl;
    cout << "Result: " << (result3 == expected3 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 4: Complex expression with operator precedence
    string test4 = "a+b*c";
    string expected4 = "+a*bc";
    string result4 = convert(test4);
    cout << "Infix: " << test4 << endl;
    cout << "Expected Prefix: " << expected4 << endl;
    cout << "Actual Prefix: " << result4 << endl;
    cout << "Result: " << (result4 == expected4 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 5: Expression with exponentiation
    string test5 = "a^b+c";
    string expected5 = "+^abc";
    string result5 = convert(test5);
    cout << "Infix: " << test5 << endl;
    cout << "Expected Prefix: " << expected5 << endl;
    cout << "Actual Prefix: " << result5 << endl;
    cout << "Result: " << (result5 == expected5 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 6: Complex nested expression requiring parentheses
    string test6 = "(p+q)*(m-n)";
    string expected6 = "*+pq-mn";
    string result6 = convert(test6);
    cout << "Infix: " << test6 << endl;
    cout << "Expected Prefix: " << expected6 << endl;
    cout << "Actual Prefix: " << result6 << endl;
    cout << "Result: " << (result6 == expected6 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    cout << "All tests completed!" << endl;
  }
};

// Derived class for postfix to infix conversion
class PostfixToInfix : public Converter, public ExpressionConverter {
public:
  // Convert postfix expression to infix using stack-based algorithm
  string convert(string input) {
    int i = 0;
    stack<string> st;

    while (i < input.size()) {
      if (isOperand(input.at(i))) {
        // If character is operand, push it onto stack
        string t = "";
        t.push_back(input.at(i));
        st.push(t);
      } else {
        // If character is operator, pop two operands and form expression
        string t1 = st.top();
        st.pop();
        string t2 = st.top();
        st.pop();

        // Add parentheses based on operator precedence
        string res = addParentheses(t2, input[i], t1);
        st.push(res);
      }
      i++;
    }
    return st.top();
  }

  // Test the converter with comprehensive test cases
  void runTests() {
    cout << "Testing Postfix to Infix Conversion:" << endl;
    cout << "====================================" << endl;

    // Test case 1: Simple addition
    string test1 = "ab+";
    string expected1 = "a+b";
    string result1 = convert(test1);
    cout << "Postfix: " << test1 << endl;
    cout << "Expected Infix: " << expected1 << endl;
    cout << "Actual Infix: " << result1 << endl;
    cout << "Result: " << (result1 == expected1 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 2: Simple multiplication
    string test2 = "ab*";
    string expected2 = "a*b";
    string result2 = convert(test2);
    cout << "Postfix: " << test2 << endl;
    cout << "Expected Infix: " << expected2 << endl;
    cout << "Actual Infix: " << result2 << endl;
    cout << "Result: " << (result2 == expected2 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 3: Multiple operations with operator precedence
    string test3 = "abc*+";
    string expected3 = "a+b*c";
    string result3 = convert(test3);
    cout << "Postfix: " << test3 << endl;
    cout << "Expected Infix: " << expected3 << endl;
    cout << "Actual Infix: " << result3 << endl;
    cout << "Result: " << (result3 == expected3 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 4: Complex expression with parentheses
    string test4 = "ab+cd-*";
    string expected4 = "(a+b)*(c-d)";
    string result4 = convert(test4);
    cout << "Postfix: " << test4 << endl;
    cout << "Expected Infix: " << expected4 << endl;
    cout << "Actual Infix: " << result4 << endl;
    cout << "Result: " << (result4 == expected4 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 5: Expression with exponentiation
    string test5 = "ab^c+";
    string expected5 = "a^b+c";
    string result5 = convert(test5);
    cout << "Postfix: " << test5 << endl;
    cout << "Expected Infix: " << expected5 << endl;
    cout << "Actual Infix: " << result5 << endl;
    cout << "Result: " << (result5 == expected5 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 6: More complex expression requiring parentheses
    string test6 = "abc+*";
    string expected6 = "a*(b+c)";
    string result6 = convert(test6);
    cout << "Postfix: " << test6 << endl;
    cout << "Expected Infix: " << expected6 << endl;
    cout << "Actual Infix: " << result6 << endl;
    cout << "Result: " << (result6 == expected6 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    cout << "All tests completed!" << endl;
  }
};

// Derived class for prefix to infix conversion
class PrefixToInfix : public Converter, public ExpressionConverter {
public:
  // Convert prefix expression to infix using stack-based algorithm
  string convert(string s) {
    stack<string> st;
    int i = s.size() - 1;

    // Process from right to left for prefix notation
    while (i >= 0) {
      if (isOperand(s[i])) {
        // If character is an operand, push it onto stack
        string t = "";
        t += s[i];
        st.push(t);
      } else {
        // If character is an operator, pop two operands and form expression
        string t1, t2, t;
        t1 = st.top();
        st.pop();
        t2 = st.top();
        st.pop();
        t = addParentheses(t1, s[i], t2);
        st.push(t);
      }
      i--;
    }

    return st.top();
  }

  // Test the converter with comprehensive test cases
  void runTests() {
    cout << "Testing Prefix to Infix Conversion:" << endl;
    cout << "===================================" << endl;

    // Test case 1: Simple addition
    string test1 = "+ab";
    string expected1 = "a+b";
    string result1 = convert(test1);
    cout << "Prefix: " << test1 << endl;
    cout << "Expected Infix: " << expected1 << endl;
    cout << "Actual Infix: " << result1 << endl;
    cout << "Result: " << (result1 == expected1 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 2: Simple multiplication
    string test2 = "*ab";
    string expected2 = "a*b";
    string result2 = convert(test2);
    cout << "Prefix: " << test2 << endl;
    cout << "Expected Infix: " << expected2 << endl;
    cout << "Actual Infix: " << result2 << endl;
    cout << "Result: " << (result2 == expected2 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 3: Complex expression with operator precedence
    string test3 = "+a*bc";
    string expected3 = "a+b*c";
    string result3 = convert(test3);
    cout << "Prefix: " << test3 << endl;
    cout << "Expected Infix: " << expected3 << endl;
    cout << "Actual Infix: " << result3 << endl;
    cout << "Result: " << (result3 == expected3 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 4: Expression with exponentiation
    string test4 = "+^abc";
    string expected4 = "a^b+c";
    string result4 = convert(test4);
    cout << "Prefix: " << test4 << endl;
    cout << "Expected Infix: " << expected4 << endl;
    cout << "Actual Infix: " << result4 << endl;
    cout << "Result: " << (result4 == expected4 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 5: More complex nested expression requiring parentheses
    string test5 = "*+pq-mn";
    string expected5 = "(p+q)*(m-n)";
    string result5 = convert(test5);
    cout << "Prefix: " << test5 << endl;
    cout << "Expected Infix: " << expected5 << endl;
    cout << "Actual Infix: " << result5 << endl;
    cout << "Result: " << (result5 == expected5 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    cout << "All tests completed!" << endl;
  }
};

// Derived class for postfix to prefix conversion
class PostfixToPrefix : public Converter, public ExpressionConverter {
public:
  // Convert postfix expression to prefix using stack-based algorithm
  string convert(string s) {
    int i = 0;
    stack<string> st;

    while (i < s.size()) {
      if (isOperand(s.at(i))) {
        // If character is operand, push it onto stack
        string t = "";
        t.push_back(s.at(i));
        st.push(t);
      } else {
        // If character is operator, pop two operands and form prefix expression
        string t, t1, t2;
        t2 = st.top();
        st.pop();
        t1 = st.top();
        st.pop();
        t = s[i] + t1 + t2; // Operator + operand1 + operand2
        st.push(t);
      }
      i++;
    }
    return st.top();
  }

  // Test the converter with comprehensive test cases
  void runTests() {
    cout << "Testing Postfix to Prefix Conversion:" << endl;
    cout << "=====================================" << endl;

    // Test case 1: Simple addition
    string test1 = "ab+";
    string expected1 = "+ab";
    string result1 = convert(test1);
    cout << "Postfix: " << test1 << endl;
    cout << "Expected Prefix: " << expected1 << endl;
    cout << "Actual Prefix: " << result1 << endl;
    cout << "Result: " << (result1 == expected1 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 2: Simple multiplication
    string test2 = "ab*";
    string expected2 = "*ab";
    string result2 = convert(test2);
    cout << "Postfix: " << test2 << endl;
    cout << "Expected Prefix: " << expected2 << endl;
    cout << "Actual Prefix: " << result2 << endl;
    cout << "Result: " << (result2 == expected2 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 3: Multiple operations with operator precedence
    string test3 = "abc*+";
    string expected3 = "+a*bc";
    string result3 = convert(test3);
    cout << "Postfix: " << test3 << endl;
    cout << "Expected Prefix: " << expected3 << endl;
    cout << "Actual Prefix: " << result3 << endl;
    cout << "Result: " << (result3 == expected3 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 4: Complex expression with multiple operators
    string test4 = "ab+cd-*";
    string expected4 = "*+ab-cd";
    string result4 = convert(test4);
    cout << "Postfix: " << test4 << endl;
    cout << "Expected Prefix: " << expected4 << endl;
    cout << "Actual Prefix: " << result4 << endl;
    cout << "Result: " << (result4 == expected4 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 5: Expression with exponentiation
    string test5 = "ab^c+";
    string expected5 = "+^abc";
    string result5 = convert(test5);
    cout << "Postfix: " << test5 << endl;
    cout << "Expected Prefix: " << expected5 << endl;
    cout << "Actual Prefix: " << result5 << endl;
    cout << "Result: " << (result5 == expected5 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 6: More complex nested expression
    string test6 = "pq+mn-*";
    string expected6 = "*+pq-mn";
    string result6 = convert(test6);
    cout << "Postfix: " << test6 << endl;
    cout << "Expected Prefix: " << expected6 << endl;
    cout << "Actual Prefix: " << result6 << endl;
    cout << "Result: " << (result6 == expected6 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    cout << "All tests completed!" << endl;
  }
};

// Derived class for prefix to postfix conversion
class PrefixToPostfix : public Converter, public ExpressionConverter {
public:
  // Convert prefix expression to postfix using stack-based algorithm
  string convert(string s) {
    int i = s.size() - 1;
    stack<string> st;

    // Process from right to left for prefix notation
    while (i >= 0) {
      if (isOperand(s[i])) {
        // If character is operand, push it onto stack
        string t = "";
        t.push_back(s[i]);
        st.push(t);
      } else {
        // If character is operator, pop two operands and form postfix
        // expression
        string t, t1, t2;
        t1 = st.top();
        st.pop();
        t2 = st.top();
        st.pop();
        t = t1 + t2 + s[i]; // operand1 + operand2 + operator
        st.push(t);
      }
      i--;
    }
    return st.top();
  }

  // Test the converter with comprehensive test cases
  void runTests() {
    cout << "Testing Prefix to Postfix Conversion:" << endl;
    cout << "=====================================" << endl;

    // Test case 1: Simple addition
    string test1 = "+ab";
    string expected1 = "ab+";
    string result1 = convert(test1);
    cout << "Prefix: " << test1 << endl;
    cout << "Expected Postfix: " << expected1 << endl;
    cout << "Actual Postfix: " << result1 << endl;
    cout << "Result: " << (result1 == expected1 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 2: Simple multiplication
    string test2 = "*ab";
    string expected2 = "ab*";
    string result2 = convert(test2);
    cout << "Prefix: " << test2 << endl;
    cout << "Expected Postfix: " << expected2 << endl;
    cout << "Actual Postfix: " << result2 << endl;
    cout << "Result: " << (result2 == expected2 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 3: Multiple operations with operator precedence
    string test3 = "+a*bc";
    string expected3 = "abc*+";
    string result3 = convert(test3);
    cout << "Prefix: " << test3 << endl;
    cout << "Expected Postfix: " << expected3 << endl;
    cout << "Actual Postfix: " << result3 << endl;
    cout << "Result: " << (result3 == expected3 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 4: Complex expression with multiple operators
    string test4 = "*+ab-cd";
    string expected4 = "ab+cd-*";
    string result4 = convert(test4);
    cout << "Prefix: " << test4 << endl;
    cout << "Expected Postfix: " << expected4 << endl;
    cout << "Actual Postfix: " << result4 << endl;
    cout << "Result: " << (result4 == expected4 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 5: Expression with exponentiation
    string test5 = "+^abc";
    string expected5 = "ab^c+";
    string result5 = convert(test5);
    cout << "Prefix: " << test5 << endl;
    cout << "Expected Postfix: " << expected5 << endl;
    cout << "Actual Postfix: " << result5 << endl;
    cout << "Result: " << (result5 == expected5 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    // Test case 6: More complex nested expression
    string test6 = "*+pq-mn";
    string expected6 = "pq+mn-*";
    string result6 = convert(test6);
    cout << "Prefix: " << test6 << endl;
    cout << "Expected Postfix: " << expected6 << endl;
    cout << "Actual Postfix: " << result6 << endl;
    cout << "Result: " << (result6 == expected6 ? "✓ PASS" : "✗ FAIL") << endl
         << endl;

    cout << "All tests completed!" << endl;
  }
};

// Main function to demonstrate the converter functionality
int main() {
  // Use smart pointer to avoid memory leak
  unique_ptr<Converter> converter = make_unique<PrefixToPostfix>();
  converter->runTests();
  return 0;
}