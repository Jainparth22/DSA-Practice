// LC#25 — Reverse Nodes in k-Group
// Difficulty: Hard | Pattern: Iterative Reversal | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int v) : val(v), next(nullptr) {} };
ListNode* build(vector<int> v) { ListNode d(0); auto* t = &d; for (int x : v) { t->next = new ListNode(x); t = t->next; } return d.next; }
ListNode* reverseKGroup(ListNode* h, int k) {
    ListNode d(0); d.next = h; ListNode* gp = &d;
    while (true) {
        ListNode* kth = gp; for (int i = 0; i < k && kth; i++) kth = kth->next;
        if (!kth) break;
        ListNode *nxt = kth->next, *prev = nxt, *cur = gp->next;
        while (cur != nxt) { auto* t = cur->next; cur->next = prev; prev = cur; cur = t; }
        auto* tmp = gp->next; gp->next = kth; gp = tmp;
    }
    return d.next;
}
int main() { for (auto* r = reverseKGroup(build({1,2,3,4,5}), 2); r; r = r->next) cout << r->val << " "; } // 2 1 4 3 5
