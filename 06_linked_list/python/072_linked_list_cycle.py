# LC#141 — Linked List Cycle
# Difficulty: Easy
# Pattern: Floyd's Two Pointer (Slow & Fast)
# Time: O(n) | Space: O(1)
#
# Approach:
#   Slow moves 1 step, fast moves 2 steps.
#   They meet → cycle. Fast hits None → no cycle.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow is fast:
                return True
        return False


if __name__ == "__main__":
    s = Solution()

    # With cycle: 3 -> 2 -> 0 -> -4 -> (back to 2)
    h1 = ListNode(3)
    h1.next = ListNode(2)
    h1.next.next = ListNode(0)
    h1.next.next.next = ListNode(-4)
    h1.next.next.next.next = h1.next  # cycle
    assert s.hasCycle(h1) == True

    # No cycle: 1 -> 2
    h2 = ListNode(1, ListNode(2))
    assert s.hasCycle(h2) == False

    # Single node
    assert s.hasCycle(ListNode(1)) == False

    print("All tests passed!")
