# LC#1584 — Min Cost to Connect All Points
# Difficulty: Medium | Pattern: Prim's MST | Time: O(n^2) | Space: O(n)
def min_cost_connect_points(p):
    n = len(p); d = [float("inf")] * n; used = [False] * n; d[0] = 0; total = 0
    for _ in range(n):
        u = min((i for i in range(n) if not used[i]), key=lambda i: d[i])
        used[u] = True; total += d[u]
        for v in range(n):
            if not used[v]: d[v] = min(d[v], abs(p[u][0] - p[v][0]) + abs(p[u][1] - p[v][1]))
    return total

assert min_cost_connect_points([[0,0],[2,2],[3,10],[5,2],[7,0]]) == 20
