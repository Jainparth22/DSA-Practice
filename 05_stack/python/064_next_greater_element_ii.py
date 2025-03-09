# LC#503 — Next Greater Element II
# Difficulty: Medium | Pattern: Circular Monotonic Stack | Time: O(n) | Space: O(n)
def next_greater_elements(a):
    n = len(a); res = [-1] * n; st = []
    for i in range(2 * n):
        while st and a[st[-1]] < a[i % n]: res[st.pop()] = a[i % n]
        if i < n: st.append(i)
    return res

assert next_greater_elements([1,2,1]) == [2, -1, 2]
