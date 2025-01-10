# LC#75 — Sort Colors
# Difficulty: Medium | Pattern: Dutch National Flag | Time: O(n) | Space: O(1)
def sort_colors(a):
    lo, mid, hi = 0, 0, len(a) - 1
    while mid <= hi:
        if a[mid] == 0:
            a[lo], a[mid] = a[mid], a[lo]; lo += 1; mid += 1
        elif a[mid] == 1:
            mid += 1
        else:
            a[mid], a[hi] = a[hi], a[mid]; hi -= 1

a = [2,0,2,1,1,0]; sort_colors(a); assert a == [0,0,1,1,2,2]
