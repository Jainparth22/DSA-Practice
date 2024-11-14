# LC#134 — Gas Station
# Difficulty: Medium | Pattern: Greedy | Time: O(n) | Space: O(1)
def can_complete_circuit(gas, cost):
    total = tank = start = 0
    for i in range(len(gas)):
        d = gas[i] - cost[i]; total += d; tank += d
        if tank < 0:
            start = i + 1; tank = 0
    return start if total >= 0 else -1

assert can_complete_circuit([1,2,3,4,5], [3,4,5,1,2]) == 3
