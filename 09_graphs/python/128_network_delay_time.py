# LC#743 — Network Delay Time
# Difficulty: Medium | Pattern: Dijkstra | Time: O(E log V) | Space: O(V+E)
import heapq

def network_delay_time(times, n, k):
    g = {i: [] for i in range(1, n + 1)}
    for u, v, w in times: g[u].append((v, w))
    d = {i: float("inf") for i in g}; d[k] = 0; pq = [(0, k)]
    while pq:
        dist, u = heapq.heappop(pq)
        if dist > d[u]: continue
        for v, w in g[u]:
            if dist + w < d[v]: d[v] = dist + w; heapq.heappush(pq, (d[v], v))
    m = max(d.values())
    return -1 if m == float("inf") else m

assert network_delay_time([[2,1,1],[2,3,1],[3,4,1]], 4, 2) == 2
