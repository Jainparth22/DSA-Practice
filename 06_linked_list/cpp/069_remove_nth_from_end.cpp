// LC#19 — Remove Nth Node From End
// Difficulty: Medium | Pattern: Two Pointers | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int v) : val(v), next(nullptr) {} };
ListNode* build(vector<int> v) { ListNode d(0); auto* t = &d; for (int x : v) { t->next = new ListNode(x); t = t->next; } return d.next; }
ListNode* removeNthFromEnd(ListNode* h, int n) {
    ListNode d(0); d.next = h; ListNode *f = &d, *s = &d;
    for (int i = 0; i < n; i++) f = f->next;
    while (f->next) { f = f->next; s = s->next; }
    s->next = s->next->next;
    return d.next;
}
int main() { auto* h = removeNthFromEnd(build({1,2,3,4,5}), 2); for (; h; h = h->next) cout << h->val << " "; } // 1 2 3 5
