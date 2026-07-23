# LC#126 — Word Ladder II
# Difficulty: Hard | Pattern: BFS levels + DFS paths | Time: O(N * L^2 + paths) | Space: O(N * L)
from collections import defaultdict

def find_ladders(begin, end, word_list):
    words = set(word_list)
    if end not in words: return []
    layer = {begin: [[begin]]}
    while layer:
        nxt = defaultdict(list)
        for w, paths in layer.items():
            if w == end: return paths
            for i in range(len(w)):
                for c in "abcdefghijklmnopqrstuvwxyz":
                    x = w[:i] + c + w[i+1:]
                    if x in words: nxt[x] += [p + [x] for p in paths]
        words -= set(nxt); layer = nxt
    return []

assert sorted(find_ladders("hit", "cog", ["hot","dot","dog","lot","log","cog"])) == [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
