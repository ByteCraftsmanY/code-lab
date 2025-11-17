// N meetings in one room
// Step: Greedy Algorithms [Easy, Medium/Hard]
// Sub Step: Medium/Hard
// Post Link: https://takeuforward.org/data-structure/n-meetings-in-one-room/
// LeetCode Link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

#include <bits/stdc++.h>
using namespace std;

struct Data {
    int startTime, endTime, position;
    Data(int start, int end, int idx) {
        this->startTime = start;
        this->endTime = end;
        this->position = idx;
    }
};

bool comparitor(Data* a, Data* b) {
    return a->endTime < b->endTime;
}

int maxMeetings(vector<int>& start, vector<int>& end) {
    vector<Data*> combinedData;
    for (int i = 0; i < start.size(); i++) {
        combinedData.push_back(new Data(start.at(i), end.at(i), i + 1));
    }
    sort(combinedData.begin(), combinedData.end(), comparitor);
    int result = 0, endTime = -1;
    for (auto const d : combinedData) {
        if (d->startTime > endTime) {
            result++;
            endTime = d->endTime;
        }
    }
    return result;
}
int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5}, end = {2, 4, 5, 7, 9, 9};
    start = {25, 0, 14, 24, 18, 3, 17}, end = {29, 25, 24, 26, 25, 23, 18};
    cout << maxMeetings(start, end) << endl;
    // vector<int> result = maxMeetings(start, end);
    // for (auto const& x : result) cout << x << " ";
    return 0;
}
