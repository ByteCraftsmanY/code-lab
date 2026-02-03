#include <bits/stdc++.h>
using namespace std;

template <typename t>
class Stack {
   private:
    vector<int> arr;

   public:
    void push(t val) {
        arr.push_back(val);
    }

    t pop() {
        t val;
        if (this->empty()) return val;
        arr.pop_back();
    }

    t top() {
        if (!this->arr.empty()) {
        }
    }
};

main() {
    return 0;
}
