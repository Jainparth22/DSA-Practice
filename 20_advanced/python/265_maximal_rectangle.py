# LC#85 — Maximal Rectangle
# Difficulty: Hard | Pattern: Histogram per row | Time: O(mn) | Space: O(n)
def maximal_rectangle(m):
    if not m: return 0
    def hist(h):
        h = h + [0]; st = []; best = 0
        for i, x in enumerate(h):
            while st and h[st[-1]] >= x:
                ht = h[st.pop()]; best = max(best, ht * (i - (st[-1] if st else -1) - 1))
            st.append(i)
        return best
    h = [0] * len(m[0]); best = 0
    for row in m:
        h = [h[j] + 1 if row[j] == "1" else 0 for j in range(len(row))]; best = max(best, hist(h))
    return best

assert maximal_rectangle([list("10100"), list("10111"), list("11111"), list("10010")]) == 6
