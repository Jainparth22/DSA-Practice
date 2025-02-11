/*
 * LC #121 / Pattern — Maximum Sum Subarray of Size K
 * Difficulty : Easy (custom)
 * Pattern    : Sliding Window (fixed size)
 * Time       : O(n)
 * Space      : O(1)
 *
 * Classic fixed-window problem. Add right element, remove left element.
 * Find the maximum sum window of exactly size k.
 */

#include <bits/stdc++.h>
using namespace std;

int maxSumSubarrayOfSizeK(vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;

    int windowSum = 0;
    // Build first window
    for (int i = 0; i < k; i++) windowSum += arr[i];
    int maxSum = windowSum;

    // Slide window
    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k]; // add right, remove left
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}

/*
 * LC #643 — Maximum Average Subarray I
 * Same pattern: fixed window of size k, find max average.
 */
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double windowSum = 0;
        for (int i = 0; i < k; i++) windowSum += nums[i];
        double maxSum = windowSum;
        for (int i = k; i < (int)nums.size(); i++) {
            windowSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, windowSum);
        }
        return maxSum / k;
    }
};

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    cout << maxSumSubarrayOfSizeK(arr, 3) << "\n"; // 9 ([5,1,3])

    Solution sol;
    vector<int> n = {1, 12, -5, -6, 50, 3};
    cout << sol.findMaxAverage(n, 4) << "\n";  // 12.75
    return 0;
}
