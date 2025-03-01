# LC #20 — Valid Parentheses
# Difficulty : Easy
# Pattern    : Stack
# Time       : O(n)   Space: O(n)

"""
Push opening brackets. On closing bracket, check top of stack matches.
Stack must be empty at end.
"""


class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        match = {')': '(', ']': '[', '}': '{'}
        for c in s:
            if c in '([{':
                stack.append(c)
            else:
                if not stack or stack[-1] != match[c]:
                    return False
                stack.pop()
        return len(stack) == 0


if __name__ == "__main__":
    sol = Solution()
    assert sol.isValid("()")       is True
    assert sol.isValid("()[]{}")   is True
    assert sol.isValid("(]")       is False
    assert sol.isValid("([)]")     is False
    assert sol.isValid("{[]}")     is True
    assert sol.isValid("]")        is False
    assert sol.isValid("")         is True
    print("All tests passed!")
