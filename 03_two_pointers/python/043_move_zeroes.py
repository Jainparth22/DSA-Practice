# LC#283 — Move Zeroes
# Difficulty: Easy | Pattern: Two Pointers | Time: O(n) | Space: O(1)
def move_zeroes(a):
    k = 0
    for i in range(len(a)):
        if a[i]:
            a[k], a[i] = a[i], a[k]; k += 1

a = [0,1,0,3,12]; move_zeroes(a); assert a == [1,3,12,0,0]
