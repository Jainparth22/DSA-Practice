// LC#141 — Linked List Cycle
// Difficulty: Easy
// Pattern: Floyd's Two Pointer (Slow & Fast)
// Time: O(n) | Space: O(1)
//
// Approach:
//   Slow pointer moves 1 step, fast pointer moves 2 steps.
//   If fast ever catches slow → cycle exists.
//   If fast reaches null → no cycle.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    // 3 -> 2 -> 0 -> -4 -> (back to 2)
    ListNode* h1 = new ListNode(3);
    h1->next = new ListNode(2);
    h1->next->next = new ListNode(0);
    h1->next->next->next = new ListNode(-4);
    h1->next->next->next->next = h1->next; // cycle at pos 1
    cout << sol.hasCycle(h1) << endl; // 1 (true)

    // 1 -> 2 -> null (no cycle)
    ListNode* h2 = new ListNode(1);
    h2->next = new ListNode(2);
    cout << sol.hasCycle(h2) << endl; // 0 (false)

    // Single node, no cycle
    ListNode* h3 = new ListNode(1);
    cout << sol.hasCycle(h3) << endl; // 0 (false)

    cout << "All tests passed!" << endl;
    return 0;
}
