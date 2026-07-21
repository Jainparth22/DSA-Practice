# LC#428 — Serialize and Deserialize N-ary Tree
# Difficulty: Hard | Pattern: Preorder with child counts | Time: O(n) | Space: O(n)
class Node:
    def __init__(self, val, children=None): self.val, self.children = val, children or []

def serialize(root):
    out = []
    def go(n):
        out.append(str(n.val)); out.append(str(len(n.children)))
        for c in n.children: go(c)
    if root: go(root)
    return ",".join(out)

def deserialize(s):
    if not s: return None
    it = iter(s.split(","))
    def go():
        n = Node(int(next(it)))
        for _ in range(int(next(it))): n.children.append(go())
        return n
    return go()

root = Node(1, [Node(3, [Node(5)]), Node(2)]); s = serialize(root); assert serialize(deserialize(s)) == s == "1,2,3,1,5,0,2,0"
