// LC#160 — Intersection of Two Linked Lists
// Difficulty: Easy | Pattern: Two Pointers | Time: O(m+n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int v) : val(v), next(nullptr) {} };
ListNode* getIntersectionNode(ListNode* a, ListNode* b) {
    ListNode *p = a, *q = b;
    while (p != q) { p = p ? p->next : b; q = q ? q->next : a; }
    return p;
}
int main() { ListNode c(8), a(1), b(2); a.next = &c; b.next = &c; cout << getIntersectionNode(&a, &b)->val << endl; } // 8
