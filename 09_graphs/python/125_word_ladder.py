# LC#127 — Word Ladder
# Difficulty: Hard | Pattern: BFS | Time: O(N * L^2) | Space: O(N * L)
from collections import deque

def ladder_length(begin, end, words):
    d = set(words)
    if end not in d: return 0
    q = deque([(begin, 1)])
    while q:
        w, n = q.popleft()
        if w == end: return n
        for i in range(len(w)):
            for c in "abcdefghijklmnopqrstuvwxyz":
                x = w[:i] + c + w[i+1:]
                if x in d: d.remove(x); q.append((x, n + 1))
    return 0

assert ladder_length("hit", "cog", ["hot","dot","dog","lot","log","cog"]) == 5
