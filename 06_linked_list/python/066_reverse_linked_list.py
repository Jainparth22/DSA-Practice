# LC #206 — Reverse Linked List
# Difficulty : Easy
# Pattern    : Linked List
# Time       : O(n)   Space: O(1) iterative

"""
Iterative: maintain prev and curr pointers, reverse links one by one.
Recursive: recurse to end, then reverse links on the way back.
"""

from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, curr = None, head
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        return prev

    def reverseListRecursive(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        new_head = self.reverseListRecursive(head.next)
        head.next.next = head
        head.next = None
        return new_head


def make_list(vals):
    dummy = ListNode()
    cur = dummy
    for v in vals:
        cur.next = ListNode(v)
        cur = cur.next
    return dummy.next

def to_list(head):
    result = []
    while head:
        result.append(head.val)
        head = head.next
    return result


if __name__ == "__main__":
    sol = Solution()

    for fn in [sol.reverseList, sol.reverseListRecursive]:
        assert to_list(fn(make_list([1, 2, 3, 4, 5]))) == [5, 4, 3, 2, 1]
        assert to_list(fn(make_list([1, 2])))           == [2, 1]
        assert to_list(fn(make_list([])))               == []
        assert to_list(fn(make_list([1])))              == [1]

    print("All tests passed!")
