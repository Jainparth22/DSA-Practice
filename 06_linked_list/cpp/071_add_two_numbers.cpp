// LC#2 — Add Two Numbers
// Difficulty: Medium | Pattern: Simulation with Carry | Time: O(max(m,n)) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int v) : val(v), next(nullptr) {} };
ListNode* build(vector<int> v) { ListNode d(0); auto* t = &d; for (int x : v) { t->next = new ListNode(x); t = t->next; } return d.next; }
ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
    ListNode d(0); auto* t = &d; int c = 0;
    while (a || b || c) {
        int s = c + (a ? a->val : 0) + (b ? b->val : 0); c = s / 10;
        t->next = new ListNode(s % 10); t = t->next;
        if (a) a = a->next; if (b) b = b->next;
    }
    return d.next;
}
int main() { auto* r = addTwoNumbers(build({2,4,3}), build({5,6,4})); for (; r; r = r->next) cout << r->val << " "; } // 7 0 8
