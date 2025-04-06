# LC#2 — Add Two Numbers
# Difficulty: Medium | Pattern: Simulation with Carry | Time: O(max(m,n)) | Space: O(1)
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

def add_two_numbers(a, b):
    d = t = ListNode(); c = 0
    while a or b or c:
        s = c + (a.val if a else 0) + (b.val if b else 0); c = s // 10
        t.next = ListNode(s % 10); t = t.next
        a = a.next if a else None; b = b.next if b else None
    return d.next

assert to_list(add_two_numbers(build([2,4,3]), build([5,6,4]))) == [7,0,8]
