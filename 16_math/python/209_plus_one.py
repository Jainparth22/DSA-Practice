# LC#66 — Plus One
# Difficulty: Easy | Pattern: Carry propagation | Time: O(n) | Space: O(1)
def plus_one(d):
    for i in range(len(d) - 1, -1, -1):
        d[i] += 1
        if d[i] < 10: return d
        d[i] = 0
    return [1] + d

assert plus_one([1,2,3]) == [1,2,4] and plus_one([9,9]) == [1,0,0]
