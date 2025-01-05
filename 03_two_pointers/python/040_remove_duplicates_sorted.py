# LC#26 — Remove Duplicates from Sorted Array
# Difficulty: Easy | Pattern: Two Pointers | Time: O(n) | Space: O(1)
def remove_duplicates(a):
    k = 0
    for x in a:
        if k == 0 or x != a[k-1]:
            a[k] = x; k += 1
    return k

assert remove_duplicates([0,0,1,1,1,2,2,3,3,4]) == 5
