// LC#23 — Merge K Sorted Lists
// Difficulty: Hard | Pattern: Min Heap | Time: O(N log k) | Space: O(k)
#include <bits/stdc++.h>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int v) : val(v), next(nullptr) {} };
ListNode* build(vector<int> v) { ListNode d(0); auto* t = &d; for (int x : v) { t->next = new ListNode(x); t = t->next; } return d.next; }
ListNode* mergeKLists(vector<ListNode*>& ls) {
    auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    for (auto* l : ls) if (l) pq.push(l);
    ListNode d(0); auto* t = &d;
    while (!pq.empty()) { auto* n = pq.top(); pq.pop(); t->next = n; t = n; if (n->next) pq.push(n->next); }
    return d.next;
}
int main() { vector<ListNode*> ls = {build({1,4,5}), build({1,3,4}), build({2,6})}; for (auto* r = mergeKLists(ls); r; r = r->next) cout << r->val << " "; } // 1 1 2 3 4 4 5 6
