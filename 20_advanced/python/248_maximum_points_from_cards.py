# LC#1423 — Maximum Points You Can Obtain from Cards
# Difficulty: Medium | Pattern: Sliding window on complement | Time: O(n) | Space: O(1)
def max_score(cards, k):
    n = len(cards); s = sum(cards[:k]); best = s
    for i in range(1, k + 1):
        s += cards[n - i] - cards[k - i]; best = max(best, s)
    return best

assert max_score([1,2,3,4,5,6,1], 3) == 12
