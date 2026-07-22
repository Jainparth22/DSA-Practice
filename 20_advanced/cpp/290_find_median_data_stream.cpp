// LC#295 — Find Median from Data Stream
// Difficulty: Hard | Pattern: Two Heaps
// Time: O(log n) addNum, O(1) findMedian | Space: O(n)
// Approach:
//   Two heaps: max-heap for lower half, min-heap for upper half.
//   Always keep sizes balanced: lo.size() == hi.size() or lo.size() == hi.size()+1.
//   Median = lo.top() if odd total, else avg of lo.top() and hi.top().

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int> lo;                          // max-heap (lower half)
    priority_queue<int, vector<int>, greater<int>> hi; // min-heap (upper half)
public:
    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top()); lo.pop();         // balance: push max of lo to hi
        if (hi.size() > lo.size()) {          // keep lo >= hi in size
            lo.push(hi.top()); hi.pop();
        }
    }
    double findMedian() {
        if (lo.size() > hi.size()) return lo.top();
        return (lo.top() + hi.top()) / 2.0;
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl; // 1.5
    mf.addNum(3);
    cout << mf.findMedian() << endl; // 2.0
    mf.addNum(4);
    cout << mf.findMedian() << endl; // 2.5
    cout << "All tests passed!" << endl;
    return 0;
}
