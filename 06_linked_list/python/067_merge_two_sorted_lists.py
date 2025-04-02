# LC #21 — Merge Two Sorted Lists
# Difficulty : Easy
# Pattern    : Linked List — Dummy Head
# Time       : O(m+n)   Space: O(1)

"""
Dummy head node avoids special-casing first node.
Compare current heads, attach smaller, advance that pointer.
Attach remaining list at end.
"""

from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val; self.next = next


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        tail = dummy
        while list1 and list2:
            if list1.val <= list2.val:
                tail.next = list1; list1 = list1.next
            else:
                tail.next = list2; list2 = list2.next
            tail = tail.next
        tail.next = list1 or list2
        return dummy.next


def make(vals):
    dummy = ListNode(); cur = dummy
    for v in vals: cur.next = ListNode(v); cur = cur.next
    return dummy.next

def to_list(h):
    res = []
    while h: res.append(h.val); h = h.next
    return res


if __name__ == "__main__":
    sol = Solution()
    assert to_list(sol.mergeTwoLists(make([1,2,4]), make([1,3,4]))) == [1,1,2,3,4,4]
    assert to_list(sol.mergeTwoLists(make([]),      make([])))      == []
    assert to_list(sol.mergeTwoLists(make([]),      make([0])))     == [0]
    assert to_list(sol.mergeTwoLists(make([5]),     make([1,3,7]))) == [1,3,5,7]
    print("All tests passed!")
