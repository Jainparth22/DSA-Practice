# LC#169 — Majority Element
# Difficulty: Easy | Pattern: Boyer-Moore Voting | Time: O(n) | Space: O(1)
def majority_element(a):
    cand = cnt = 0
    for x in a:
        if cnt == 0: cand = x
        cnt += 1 if x == cand else -1
    return cand

assert majority_element([2,2,1,1,1,2,2]) == 2
