# LC#84 — Largest Rectangle in Histogram
# Difficulty: Hard | Pattern: Monotonic Stack | Time: O(n) | Space: O(n)
def largest_rectangle_area(h):
    h = h + [0]; st = []; best = 0
    for i, x in enumerate(h):
        while st and h[st[-1]] >= x:
            ht = h[st.pop()]
            left = st[-1] if st else -1
            best = max(best, ht * (i - left - 1))
        st.append(i)
    return best

assert largest_rectangle_area([2,1,5,6,2,3]) == 10
