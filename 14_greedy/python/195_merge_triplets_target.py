# LC#1899 — Merge Triplets to Form Target
# Difficulty: Medium | Pattern: Greedy filter | Time: O(n) | Space: O(1)
def merge_triplets(triplets, target):
    good = set()
    for t in triplets:
        if all(t[i] <= target[i] for i in range(3)):
            good |= {i for i in range(3) if t[i] == target[i]}
    return len(good) == 3

assert merge_triplets([[2,5,3],[1,8,4],[1,7,5]], [2,7,5]) and not merge_triplets([[3,4,5],[4,5,6]], [3,2,5])
