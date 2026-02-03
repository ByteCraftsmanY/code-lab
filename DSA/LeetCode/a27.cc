#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
   private:
    queue<int> q;
    const int maxRange = 3000;

   public:
    RecentCounter() {
    }

    int ping(int t) {
        int range = t - maxRange;
        while (!q.empty() && q.front() < range) {
            q.pop();
        }
        q.push(t);
        return this->q.size();
    }
};

int main() {
}