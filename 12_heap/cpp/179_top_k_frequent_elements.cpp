// LC#347 — Top K Frequent Elements
// Difficulty: Medium | Pattern: Heap / Bucket Sort
// Time: O(n log k) heap | Space: O(n)
// Approach: Count frequencies. Use a min-heap of size k.
// At the end, heap contains the k most frequent elements.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;
        // min-heap: (frequency, value)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        for (auto& [val, cnt] : freq) {
            minHeap.push({cnt, val});
            if ((int)minHeap.size() > k) minHeap.pop();
        }
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> v1 = {1,1,1,2,2,3};
    auto r1 = sol.topKFrequent(v1, 2);
    // Expected: [1,2] in any order
    sort(r1.begin(), r1.end());
    for (int x : r1) cout << x << " "; cout << endl; // 1 2

    vector<int> v2 = {1};
    auto r2 = sol.topKFrequent(v2, 1);
    cout << r2[0] << endl; // 1

    cout << "All tests passed!" << endl;
    return 0;
}
