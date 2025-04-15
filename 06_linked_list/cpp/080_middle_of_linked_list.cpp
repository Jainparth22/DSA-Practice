// LC#876 — Middle of the Linked List
// Difficulty: Easy | Pattern: Slow/Fast Pointers | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int v) : val(v), next(nullptr) {} };
ListNode* build(vector<int> v) { ListNode d(0); auto* t = &d; for (int x : v) { t->next = new ListNode(x); t = t->next; } return d.next; }
ListNode* middleNode(ListNode* h) {
    ListNode *s = h, *f = h;
    while (f && f->next) { s = s->next; f = f->next->next; }
    return s;
}
int main() { cout << middleNode(build({1,2,3,4,5,6}))->val << endl; } // 4
