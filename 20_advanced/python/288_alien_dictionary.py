# LC#269 — Alien Dictionary
# Difficulty: Hard | Pattern: Topological Sort | Time: O(C) | Space: O(1)
from collections import deque

def alien_order(words):
    g = {c: set() for w in words for c in w}; indeg = {c: 0 for c in g}
    for a, b in zip(words, words[1:]):
        k = 0
        while k < min(len(a), len(b)) and a[k] == b[k]: k += 1
        if k == min(len(a), len(b)):
            if len(a) > len(b): return ""
            continue
        if b[k] not in g[a[k]]: g[a[k]].add(b[k]); indeg[b[k]] += 1
    q = deque(c for c in g if indeg[c] == 0); res = []
    while q:
        c = q.popleft(); res.append(c)
        for n in g[c]:
            indeg[n] -= 1
            if indeg[n] == 0: q.append(n)
    return "".join(res) if len(res) == len(g) else ""

assert alien_order(["wrt","wrf","er","ett","rftt"]) == "wertf"
