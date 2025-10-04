/*
 * LC #215 — Kth Largest Element in an Array
 * Difficulty : Medium
 * Pattern    : Heap (Min-Heap of size K) or QuickSelect
 * Time       : O(n log k) heap, O(n) average QuickSelect
 * Space      : O(k) heap, O(1) QuickSelect
 *
 * Approach A — Min-heap of size K:
 *   Maintain a min-heap of exactly K elements.
 *   Top = K-th largest.
 *
 * Approach B — QuickSelect (Hoare partition, in-place):
 *   Partial sort: after partitioning, pivot is in its correct sorted position.
 *   Only recurse into the half containing the K-th largest.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach A: Min-heap
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minH; // min-heap
        for (int n : nums) {
            minH.push(n);
            if ((int)minH.size() > k) minH.pop(); // keep only K largest
        }
        return minH.top(); // smallest of the K largest = K-th largest
    }

    // Approach B: QuickSelect
    int findKthLargest_qs(vector<int>& nums, int k) {
        int target = nums.size() - k; // K-th largest = (n-k)-th smallest (0-indexed)
        return quickSelect(nums, 0, nums.size() - 1, target);
    }

private:
    int quickSelect(vector<int>& nums, int lo, int hi, int target) {
        int pivot = nums[hi];
        int i = lo;
        for (int j = lo; j < hi; j++)
            if (nums[j] <= pivot) swap(nums[i++], nums[j]);
        swap(nums[i], nums[hi]); // pivot in final position
        if (i == target) return nums[i];
        return i < target ? quickSelect(nums, i+1, hi, target)
                          : quickSelect(nums, lo, i-1, target);
    }
};

int main() {
    Solution sol;
    vector<int> n1 = {3,2,1,5,6,4}; cout << sol.findKthLargest(n1, 2) << "\n"; // 5
    vector<int> n2 = {3,2,3,1,2,4,5,5,6}; cout << sol.findKthLargest(n2, 4) << "\n"; // 4
    return 0;
}
