#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

string reverseWords(string s) {
    string result = "";

    // Lambda function to add a word to the result
    auto addWord = [&result](const string &word) {
        if (!result.empty()) {
            result += ' ';
        }
        result += word;
    };

    int wordEnd = -1;
    s = ' ' + s;  // Add leading space to handle edge cases

    // Iterate from right to left to find words
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            // If we found a complete word, add it to result
            if (wordEnd != -1) {
                string word = s.substr(i + 1, wordEnd - i);
                addWord(word);
                wordEnd = -1;  // Reset for next word
            }
            continue;
        }

        // Mark the end of current word
        if (wordEnd == -1) {
            wordEnd = i;
        }
    }

    return result;
}

int main() {
    string s = "  hello world  ";
    getline(cin, s);
    cout << reverseWords(s);
    return 0;
}