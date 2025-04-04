# LC#19 — Remove Nth Node From End
# Difficulty: Medium | Pattern: Two Pointers | Time: O(n) | Space: O(1)
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

def remove_nth_from_end(h, n):
    d = ListNode(0, h); f = s = d
    for _ in range(n): f = f.next
    while f.next: f, s = f.next, s.next
    s.next = s.next.next
    return d.next

assert to_list(remove_nth_from_end(build([1,2,3,4,5]), 2)) == [1,2,3,5]
