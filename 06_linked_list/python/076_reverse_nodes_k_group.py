# LC#25 — Reverse Nodes in k-Group
# Difficulty: Hard | Pattern: Iterative Reversal | Time: O(n) | Space: O(1)
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

def reverse_k_group(h, k):
    d = ListNode(0, h); gp = d
    while True:
        kth = gp
        for _ in range(k):
            kth = kth.next if kth else None
        if not kth: break
        nxt = kth.next; prev, cur = nxt, gp.next
        while cur is not nxt: cur.next, prev, cur = prev, cur, cur.next
        tmp = gp.next; gp.next = kth; gp = tmp
    return d.next

assert to_list(reverse_k_group(build([1,2,3,4,5]), 2)) == [2,1,4,3,5]
