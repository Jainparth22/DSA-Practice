# LC#27 — Remove Element
# Difficulty: Easy | Pattern: Two Pointers | Time: O(n) | Space: O(1)
def remove_element(a, v):
    k = 0
    for x in a:
        if x != v:
            a[k] = x; k += 1
    return k

assert remove_element([3,2,2,3], 3) == 2
