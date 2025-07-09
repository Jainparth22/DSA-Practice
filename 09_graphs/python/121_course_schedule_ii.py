# LC#210 — Course Schedule II
# Difficulty: Medium | Pattern: Topological Sort (Kahn) | Time: O(V+E) | Space: O(V+E)
from collections import deque

def find_order(n, pre):
    g = [[] for _ in range(n)]; indeg = [0] * n
    for a, b in pre: g[b].append(a); indeg[a] += 1
    q = deque(i for i in range(n) if not indeg[i]); order = []
    while q:
        u = q.popleft(); order.append(u)
        for v in g[u]:
            indeg[v] -= 1
            if not indeg[v]: q.append(v)
    return order if len(order) == n else []

assert find_order(4, [[1,0],[2,0],[3,1],[3,2]])[0] == 0 and find_order(2, [[1,0],[0,1]]) == []
