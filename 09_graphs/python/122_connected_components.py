# LC#323 — Number of Connected Components
# Difficulty: Medium | Pattern: Union Find | Time: O(E α(V)) | Space: O(V)
def count_components(n, edges):
    p = list(range(n))
    def find(x):
        while p[x] != x: p[x] = p[p[x]]; x = p[x]
        return x
    c = n
    for a, b in edges:
        ra, rb = find(a), find(b)
        if ra != rb: p[ra] = rb; c -= 1
    return c

assert count_components(5, [[0,1],[1,2],[3,4]]) == 2
