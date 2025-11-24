// Job sequencing Problem
// Step: Greedy Algorithms [Easy, Medium/Hard]
// Sub Step: Medium/Hard
// Post Link: https://takeuforward.org/data-structure/job-sequencing-problem/
// LeetCode Link: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

#include <bits/stdc++.h>
using namespace std;

vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
    class data {
       public:
        int deadline;
        int profit;
        data(int d, int p) {
            this->deadline = d;
            this->profit = p;
        }
    };
    int maxDeadline = 0;
    vector<data*> combinedData;
    for (int i = 0; i < profit.size(); i++) {
        maxDeadline = max(deadline.at(i), maxDeadline);
        combinedData.push_back(new data(deadline.at(i), profit.at(i)));
    }
    sort(combinedData.begin(), combinedData.end(), [](data* d1, data* d2) -> bool {
        return d1->profit > d2->profit;
    });
    // int maxDeadline = *max_element(deadline.begin(), deadline.end());
    vector<int> jobDeadSeq(maxDeadline + 1, -1);

    int maxJob = 0, maxProfit = 0;
    for (auto const& data : combinedData) {
        int i = data->deadline;
        while (i >= 1) {
            if (jobDeadSeq[i] == -1) {
                jobDeadSeq[i] = data->deadline;
                maxProfit += data->profit;
                maxJob += 1;
                break;
            }
            i--;
        }
    }
    return {maxJob, maxProfit};
}

int main() {
    vector<int> arr = {4, 1, 1, 1}, dep = {20, 10, 40, 30}, res = jobSequencing(arr, dep);
    cout << res[0] << " " << res[1];
    return 0;
}
