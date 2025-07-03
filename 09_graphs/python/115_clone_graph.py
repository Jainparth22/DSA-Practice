# LC#133 — Clone Graph
# Difficulty: Medium | Pattern: DFS + Map | Time: O(V+E) | Space: O(V)
class Node:
    def __init__(self, val, neighbors=None): self.val, self.neighbors = val, neighbors or []

def clone_graph(n):
    m = {}
    def go(x):
        if x in m: return m[x]
        c = m[x] = Node(x.val)
        c.neighbors = [go(y) for y in x.neighbors]
        return c
    return go(n) if n else None

a, b = Node(1), Node(2); a.neighbors = [b]; b.neighbors = [a]
c = clone_graph(a); assert c is not a and c.neighbors[0].neighbors[0] is c
