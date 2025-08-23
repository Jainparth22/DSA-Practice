# LC#45 — Jump Game II
# Difficulty: Medium | Pattern: Greedy / BFS | Time: O(n) | Space: O(1)
def jump(a):
    jumps = end = far = 0
    for i in range(len(a) - 1):
        far = max(far, i + a[i])
        if i == end:
            jumps += 1; end = far
    return jumps

assert jump([2,3,1,1,4]) == 2
