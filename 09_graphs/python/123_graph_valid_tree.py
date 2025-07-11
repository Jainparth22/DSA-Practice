# LC#261 — Graph Valid Tree
# Difficulty: Medium | Pattern: Union Find (n-1 edges, no cycle) | Time: O(E α(V)) | Space: O(V)
def valid_tree(n, edges):
    if len(edges) != n - 1: return False
    p = list(range(n))
    def find(x):
        while p[x] != x: p[x] = p[p[x]]; x = p[x]
        return x
    for a, b in edges:
        ra, rb = find(a), find(b)
        if ra == rb: return False
        p[ra] = rb
    return True

assert valid_tree(5, [[0,1],[0,2],[0,3],[1,4]]) and not valid_tree(5, [[0,1],[1,2],[2,3],[1,3],[1,4]])
