# LC#24 — Swap Nodes in Pairs
# Difficulty: Medium | Pattern: Pointer Manipulation | Time: O(n) | Space: O(1)
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

def swap_pairs(h):
    d = ListNode(0, h); p = d
    while p.next and p.next.next:
        a, b = p.next, p.next.next
        a.next = b.next; b.next = a; p.next = b; p = a
    return d.next

assert to_list(swap_pairs(build([1,2,3,4]))) == [2,1,4,3]
