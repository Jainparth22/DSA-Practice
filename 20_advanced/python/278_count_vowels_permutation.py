# LC#1220 — Count Vowels Permutation
# Difficulty: Hard | Pattern: DP on last vowel | Time: O(n) | Space: O(1)
def count_vowel_permutation(n):
    M = 10**9 + 7; a = e = i = o = u = 1
    for _ in range(n - 1): a, e, i, o, u = (e + i + u) % M, (a + i) % M, (e + o) % M, i, (i + o) % M
    return (a + e + i + o + u) % M

assert count_vowel_permutation(1) == 5 and count_vowel_permutation(2) == 10 and count_vowel_permutation(5) == 68
