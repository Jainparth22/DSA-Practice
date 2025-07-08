# LC #207 — Course Schedule
# Difficulty : Medium
# Pattern    : Graph — Topological Sort (Kahn's BFS) + DFS cycle detection
# Time       : O(V+E)   Space: O(V+E)

"""
Two approaches:
  1. Kahn's (BFS topo sort): if processed nodes < numCourses → cycle
  2. DFS with 3-state coloring: 0=white, 1=gray, 2=black
"""

from typing import List
from collections import deque


class Solution:
    # Approach 1: Kahn's Algorithm
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses
        for a, b in prerequisites:
            adj[b].append(a)
            indegree[a] += 1

        q = deque(i for i in range(numCourses) if indegree[i] == 0)
        processed = 0
        while q:
            u = q.popleft()
            processed += 1
            for v in adj[u]:
                indegree[v] -= 1
                if indegree[v] == 0:
                    q.append(v)
        return processed == numCourses

    # Approach 2: DFS 3-color
    def canFinish_dfs(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        for a, b in prerequisites:
            adj[b].append(a)
        state = [0] * numCourses  # 0=white, 1=gray, 2=black

        def dfs(u: int) -> bool:  # returns True if cycle found
            state[u] = 1
            for v in adj[u]:
                if state[v] == 1: return True   # back edge = cycle
                if state[v] == 0 and dfs(v): return True
            state[u] = 2
            return False

        return not any(state[i] == 0 and dfs(i) for i in range(numCourses))


if __name__ == "__main__":
    sol = Solution()
    for fn in [sol.canFinish, sol.canFinish_dfs]:
        assert fn(2, [[1, 0]])          is True
        assert fn(2, [[1, 0], [0, 1]])  is False
        assert fn(1, [])                is True
        assert fn(3, [[1,0],[2,1]])     is True
        assert fn(3, [[1,0],[0,2],[2,1]]) is False
    print("All tests passed!")
