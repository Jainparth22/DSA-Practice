# LC#134 — Gas Station
# Difficulty: Medium
# Pattern: Greedy
# Time: O(n) | Space: O(1)
#
# Approach:
#   If sum(gas) >= sum(cost), a valid starting point always exists.
#   Track running tank. When it goes negative, everything before the
#   current index can't be the start → candidate becomes i+1, reset tank.

class Solution:
    def canCompleteCircuit(self, gas: list[int], cost: list[int]) -> int:
        total_gas = sum(gas)
        total_cost = sum(cost)
        if total_gas < total_cost:
            return -1
        tank = 0
        start = 0
        for i in range(len(gas)):
            tank += gas[i] - cost[i]
            if tank < 0:
                start = i + 1
                tank = 0
        return start


if __name__ == "__main__":
    s = Solution()
    assert s.canCompleteCircuit([1, 2, 3, 4, 5], [3, 4, 5, 1, 2]) == 3
    assert s.canCompleteCircuit([2, 3, 4], [3, 4, 3]) == -1
    assert s.canCompleteCircuit([5, 1, 2, 3, 4], [4, 4, 1, 5, 1]) == 4
    print("All tests passed!")
