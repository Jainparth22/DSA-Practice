// LC#24 — Swap Nodes in Pairs
// Difficulty: Medium | Pattern: Pointer Manipulation | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int v) : val(v), next(nullptr) {} };
ListNode* build(vector<int> v) { ListNode d(0); auto* t = &d; for (int x : v) { t->next = new ListNode(x); t = t->next; } return d.next; }
ListNode* swapPairs(ListNode* h) {
    ListNode d(0); d.next = h; ListNode* p = &d;
    while (p->next && p->next->next) {
        ListNode *a = p->next, *b = a->next;
        a->next = b->next; b->next = a; p->next = b; p = a;
    }
    return d.next;
}
int main() { for (auto* r = swapPairs(build({1,2,3,4})); r; r = r->next) cout << r->val << " "; } // 2 1 4 3
