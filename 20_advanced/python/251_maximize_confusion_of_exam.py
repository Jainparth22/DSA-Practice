# LC#2024 — Maximize the Confusion of an Exam
# Difficulty: Medium | Pattern: Sliding Window | Time: O(n) | Space: O(1)
def max_consecutive_answers(s, k):
    def longest(c):
        l = cnt = best = 0
        for r, x in enumerate(s):
            cnt += x != c
            while cnt > k: cnt -= s[l] != c; l += 1
            best = max(best, r - l + 1)
        return best
    return max(longest("T"), longest("F"))

assert max_consecutive_answers("TTFTTFTT", 1) == 5 and max_consecutive_answers("TFFT", 1) == 3
