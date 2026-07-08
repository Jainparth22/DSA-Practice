# LC#1411 — Number of Ways to Paint N x 3 Grid
# Difficulty: Hard | Pattern: DP on row patterns (ABA / ABC) | Time: O(n) | Space: O(1)
def num_of_ways(n):
    M = 10**9 + 7; aba = abc = 6
    for _ in range(n - 1): aba, abc = (3 * aba + 2 * abc) % M, (2 * aba + 2 * abc) % M
    return (aba + abc) % M

assert num_of_ways(1) == 12 and num_of_ways(5000) == 30228214
