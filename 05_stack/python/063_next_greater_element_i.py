# LC#496 — Next Greater Element I
# Difficulty: Easy | Pattern: Monotonic Stack + Map | Time: O(n+m) | Space: O(n)
def next_greater_element(a, b):
    nxt, st = {}, []
    for x in b:
        while st and st[-1] < x: nxt[st.pop()] = x
        st.append(x)
    return [nxt.get(x, -1) for x in a]

assert next_greater_element([4,1,2], [1,3,4,2]) == [-1, 3, -1]
