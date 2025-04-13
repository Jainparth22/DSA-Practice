# LC#234 — Palindrome Linked List
# Difficulty: Easy | Pattern: Middle + Reverse | Time: O(n) | Space: O(1)
class ListNode:
    def __init__(self, val=0, next=None): self.val, self.next = val, next

def build(v):
    d = t = ListNode()
    for x in v: t.next = ListNode(x); t = t.next
    return d.next

def is_palindrome(h):
    s = f = h
    while f and f.next: s, f = s.next, f.next.next
    prev = None
    while s: s.next, prev, s = prev, s, s.next
    while prev:
        if prev.val != h.val: return False
        prev, h = prev.next, h.next
    return True

assert is_palindrome(build([1,2,2,1])) and not is_palindrome(build([1,2]))
