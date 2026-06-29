# LC#488 — Zuma Game
# Difficulty: Hard | Pattern: BFS over states | Time: exponential (small input) | Space: O(states)
from collections import deque

def find_min_step(board, hand):
    def shrink(s):
        i = 0
        while i < len(s):
            j = i
            while j < len(s) and s[j] == s[i]: j += 1
            if j - i >= 3: s = s[:i] + s[j:]; i = 0
            else: i = j
        return s
    hand = "".join(sorted(hand)); q = deque([(board, hand, 0)]); seen = {(board, hand)}
    while q:
        b, h, d = q.popleft()
        for i in range(len(h)):
            if i and h[i] == h[i-1]: continue
            for j in range(len(b) + 1):
                nb = shrink(b[:j] + h[i] + b[j:]); nh = h[:i] + h[i+1:]
                if not nb: return d + 1
                if (nb, nh) not in seen: seen.add((nb, nh)); q.append((nb, nh, d + 1))
    return -1

assert find_min_step("WRRBBW", "RB") == -1 and find_min_step("WWRRBBWW", "WRBRW") == 2
