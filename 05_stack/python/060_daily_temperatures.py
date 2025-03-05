# LC #739 — Daily Temperatures
# Difficulty : Medium
# Pattern    : Monotonic Stack (Next Greater Element)
# Time       : O(n)   Space: O(n)

"""
Stack stores indices of days with DECREASING temperatures.
When we find a warmer day, pop and record the wait.
"""

from typing import List


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        answer = [0] * n
        stack = []  # indices, temps decreasing

        for i, t in enumerate(temperatures):
            while stack and t > temperatures[stack[-1]]:
                idx = stack.pop()
                answer[idx] = i - idx
            stack.append(i)
        return answer


if __name__ == "__main__":
    sol = Solution()
    assert sol.dailyTemperatures([73, 74, 75, 71, 69, 72, 76, 73]) == [1, 1, 4, 2, 1, 1, 0, 0]
    assert sol.dailyTemperatures([30, 40, 50, 60]) == [1, 1, 1, 0]
    assert sol.dailyTemperatures([30, 60, 90]) == [1, 1, 0]
    assert sol.dailyTemperatures([89]) == [0]
    print("All tests passed!")
