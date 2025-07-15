# LC#787 — Cheapest Flights Within K Stops
# Difficulty: Medium | Pattern: Bellman-Ford (k+1 rounds) | Time: O(k*E) | Space: O(n)
def find_cheapest_price(n, flights, src, dst, k):
    INF = float("inf"); d = [INF] * n; d[src] = 0
    for _ in range(k + 1):
        t = d[:]
        for u, v, w in flights:
            if d[u] + w < t[v]: t[v] = d[u] + w
        d = t
    return -1 if d[dst] == INF else d[dst]

assert find_cheapest_price(3, [[0,1,100],[1,2,100],[0,2,500]], 0, 2, 1) == 200
