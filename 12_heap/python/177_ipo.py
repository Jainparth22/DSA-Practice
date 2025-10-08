# LC#502 — IPO
# Difficulty: Hard | Pattern: Greedy + Two Heaps | Time: O(n log n) | Space: O(n)
import heapq

def find_maximized_capital(k, w, profits, capital):
    projects = sorted(zip(capital, profits)); h = []; i = 0
    for _ in range(k):
        while i < len(projects) and projects[i][0] <= w:
            heapq.heappush(h, -projects[i][1]); i += 1
        if not h: break
        w -= heapq.heappop(h)
    return w

assert find_maximized_capital(2, 0, [1,2,3], [0,1,1]) == 4
