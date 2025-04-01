/*
 * LC #206 — Reverse Linked List
 * Difficulty : Easy
 * Pattern    : Linked List — Iterative + Recursive
 * Time       : O(n)
 * Space      : O(1) iterative, O(n) recursive (call stack)
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Iterative — O(1) space
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Recursive — O(n) call stack space
    ListNode* reverseListRecursive(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = reverseListRecursive(head->next);
        head->next->next = head; // reverse the link
        head->next = nullptr;
        return newHead;
    }
};

// Helpers
ListNode* makeList(vector<int> vals) {
    ListNode dummy(0); ListNode* cur = &dummy;
    for (int v : vals) { cur->next = new ListNode(v); cur = cur->next; }
    return dummy.next;
}

void printList(ListNode* head) {
    while (head) { cout << head->val; if (head->next) cout << "->"; head = head->next; }
    cout << "\n";
}

int main() {
    Solution sol;

    ListNode* l1 = makeList({1, 2, 3, 4, 5});
    printList(sol.reverseList(l1));  // 5->4->3->2->1

    ListNode* l2 = makeList({1, 2});
    printList(sol.reverseList(l2));  // 2->1

    ListNode* l3 = makeList({});
    printList(sol.reverseList(l3));  // (empty)

    return 0;
}
