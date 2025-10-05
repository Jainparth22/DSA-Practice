// LC#621 — Task Scheduler
// Difficulty: Medium | Pattern: Greedy + Max Heap
// Time: O(n log 26) = O(n) | Space: O(1)
// Approach:
//   Most frequent task determines the minimum slots needed.
//   Fill each "frame" of size (n+1) with the most frequent tasks available.
//   If not enough tasks, add idle slots. Count total time.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (char t : tasks) freq[t - 'A']++;
        priority_queue<int> maxHeap(freq, freq + 26);
        // Remove zeros
        while (!maxHeap.empty() && maxHeap.top() == 0) maxHeap.pop();

        int time = 0;
        while (!maxHeap.empty()) {
            vector<int> temp;
            int cycle = n + 1; // frame size
            while (cycle > 0 && !maxHeap.empty()) {
                temp.push_back(maxHeap.top() - 1);
                maxHeap.pop();
                cycle--;
                time++;
            }
            for (int t : temp)
                if (t > 0) maxHeap.push(t);
            if (!maxHeap.empty()) time += cycle; // idle slots
        }
        return time;
    }
};

int main() {
    Solution sol;
    vector<char> t1 = {'A','A','A','B','B','B'};
    cout << sol.leastInterval(t1, 2) << endl; // 8

    vector<char> t2 = {'A','A','A','B','B','B'};
    cout << sol.leastInterval(t2, 0) << endl; // 6

    vector<char> t3 = {'A','A','A','A','A','A','B','C','D','E','F','G'};
    cout << sol.leastInterval(t3, 2) << endl; // 16

    cout << "All tests passed!" << endl;
    return 0;
}
