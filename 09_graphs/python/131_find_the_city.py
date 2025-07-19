# LC#1334 — Find the City With Fewest Neighbors
# Difficulty: Medium | Pattern: Floyd-Warshall | Time: O(n^3) | Space: O(n^2)
def find_the_city(n, edges, th):
    d = [[float("inf")] * n for _ in range(n)]
    for i in range(n): d[i][i] = 0
    for a, b, w in edges: d[a][b] = d[b][a] = w
    for k in range(n):
        for i in range(n):
            for j in range(n): d[i][j] = min(d[i][j], d[i][k] + d[k][j])
    best, bc = -1, float("inf")
    for i in range(n):
        c = sum(d[i][j] <= th for j in range(n))
        if c <= bc: bc, best = c, i
    return best

assert find_the_city(4, [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], 4) == 3
