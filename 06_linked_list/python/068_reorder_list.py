# LC#143 — Reorder List
# Difficulty: Medium | Pattern: Middle + Reverse + Merge | Time: O(n) | Space: O(1)
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

def reorder_list(h):
    if not h or not h.next: return
    s = f = h
    while f.next and f.next.next: s, f = s.next, f.next.next
    prev, cur = None, s.next; s.next = None
    while cur: cur.next, prev, cur = prev, cur, cur.next
    a, b = h, prev
    while b:
        an, bn = a.next, b.next
        a.next = b; b.next = an; a, b = an, bn

h = build([1,2,3,4]); reorder_list(h); assert to_list(h) == [1,4,2,3]
