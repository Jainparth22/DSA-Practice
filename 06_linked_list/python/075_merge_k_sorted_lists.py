# LC#23 — Merge K Sorted Lists
# Difficulty: Hard | Pattern: Min Heap | Time: O(N log k) | Space: O(k)
import heapq

class ListNode:
    def __init__(self, val=0, next=None): self.val, self.next = val, next

def build(v):
    d = t = ListNode()
    for x in v: t.next = ListNode(x); t = t.next
    return d.next

def to_list(h):
    out = []
    while h: out.append(h.val); h = h.next
    return out

def merge_k_lists(lists):
    pq = [(l.val, i, l) for i, l in enumerate(lists) if l]; heapq.heapify(pq)
    d = t = ListNode()
    while pq:
        _, i, n = heapq.heappop(pq); t.next = n; t = n
        if n.next: heapq.heappush(pq, (n.next.val, i, n.next))
    return d.next

assert to_list(merge_k_lists([build([1,4,5]), build([1,3,4]), build([2,6])])) == [1,1,2,3,4,4,5,6]
