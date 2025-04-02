/*
 * LC #21 — Merge Two Sorted Lists
 * Difficulty : Easy
 * Pattern    : Linked List — Dummy Head
 * Time       : O(m + n)
 * Space      : O(1) — in-place pointer manipulation
 *
 * Approach:
 *   Use a dummy head node so we don't special-case the first node.
 *   Compare heads of both lists, attach the smaller one, advance.
 *   Attach the remaining non-empty list at the end.
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val; ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) { tail->next = list1; list1 = list1->next; }
            else                          { tail->next = list2; list2 = list2->next; }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
};

ListNode* make(vector<int> v) {
    ListNode d(0); ListNode* c = &d;
    for (int x : v) { c->next = new ListNode(x); c = c->next; }
    return d.next;
}
void print(ListNode* h) {
    while (h) { cout << h->val; if (h->next) cout << "->"; h = h->next; }
    cout << "\n";
}

int main() {
    Solution sol;
    print(sol.mergeTwoLists(make({1,2,4}), make({1,3,4}))); // 1->1->2->3->4->4
    print(sol.mergeTwoLists(make({}), make({})));             // (empty)
    print(sol.mergeTwoLists(make({}), make({0})));            // 0
    return 0;
}
