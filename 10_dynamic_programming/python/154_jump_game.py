# LC#55 — Jump Game
# Difficulty: Medium | Pattern: Greedy | Time: O(n) | Space: O(1)
def can_jump(a):
    far = 0
    for i, x in enumerate(a):
        if i > far: return False
        far = max(far, i + x)
    return True

assert can_jump([2,3,1,1,4]) and not can_jump([3,2,1,0,4])
