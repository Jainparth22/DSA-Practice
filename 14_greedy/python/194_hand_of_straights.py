# LC#846 — Hand of Straights
# Difficulty: Medium | Pattern: Greedy + Ordered Map | Time: O(n log n) | Space: O(n)
from collections import Counter

def is_n_straight_hand(hand, g):
    if len(hand) % g: return False
    c = Counter(hand)
    for k in sorted(c):
        if c[k] > 0:
            for i in range(1, g):
                c[k + i] -= c[k]
                if c[k + i] < 0: return False
    return True

assert is_n_straight_hand([1,2,3,6,2,3,4,7,8], 3) and not is_n_straight_hand([1,2,3,4,5], 4)
