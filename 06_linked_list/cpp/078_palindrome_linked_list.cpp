// LC#234 — Palindrome Linked List
// Difficulty: Easy | Pattern: Middle + Reverse | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int v) : val(v), next(nullptr) {} };
ListNode* build(vector<int> v) { ListNode d(0); auto* t = &d; for (int x : v) { t->next = new ListNode(x); t = t->next; } return d.next; }
bool isPalindrome(ListNode* h) {
    ListNode *s = h, *f = h;
    while (f && f->next) { s = s->next; f = f->next->next; }
    ListNode* prev = nullptr;
    while (s) { auto* n = s->next; s->next = prev; prev = s; s = n; }
    for (; prev; prev = prev->next, h = h->next) if (prev->val != h->val) return false;
    return true;
}
int main() { cout << isPalindrome(build({1,2,2,1})) << isPalindrome(build({1,2})) << endl; } // 10
