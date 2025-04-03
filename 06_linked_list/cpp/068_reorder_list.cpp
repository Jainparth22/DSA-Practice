// LC#143 — Reorder List
// Difficulty: Medium | Pattern: Middle + Reverse + Merge | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int v) : val(v), next(nullptr) {} };
ListNode* build(vector<int> v) { ListNode d(0); auto* t = &d; for (int x : v) { t->next = new ListNode(x); t = t->next; } return d.next; }
void reorderList(ListNode* h) {
    if (!h || !h->next) return;
    ListNode *s = h, *f = h;
    while (f->next && f->next->next) { s = s->next; f = f->next->next; }
    ListNode *prev = nullptr, *cur = s->next; s->next = nullptr;
    while (cur) { auto* n = cur->next; cur->next = prev; prev = cur; cur = n; }
    ListNode *a = h, *b = prev;
    while (b) { auto *an = a->next, *bn = b->next; a->next = b; b->next = an; a = an; b = bn; }
}
int main() { auto* h = build({1,2,3,4}); reorderList(h); for (; h; h = h->next) cout << h->val << " "; } // 1 4 2 3
