# LC#684 — Redundant Connection
# Difficulty: Medium | Pattern: Union Find | Time: O(n α(n)) | Space: O(n)
def find_redundant_connection(edges):
    p = list(range(len(edges) + 1))
    def find(x):
        while p[x] != x: p[x] = p[p[x]]; x = p[x]
        return x
    for a, b in edges:
        ra, rb = find(a), find(b)
        if ra == rb: return [a, b]
        p[ra] = rb

assert find_redundant_connection([[1,2],[1,3],[2,3]]) == [2, 3]
