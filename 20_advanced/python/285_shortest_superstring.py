# LC#943 — Find the Shortest Superstring
# Difficulty: Hard | Pattern: Bitmask DP (TSP) | Time: O(2^n * n^2) | Space: O(2^n * n)
def shortest_superstring(words):
    n = len(words); ov = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if i != j:
                for k in range(min(len(words[i]), len(words[j])), 0, -1):
                    if words[i].endswith(words[j][:k]): ov[i][j] = k; break
    INF = float("inf"); dp = [[INF] * n for _ in range(1 << n)]; par = [[-1] * n for _ in range(1 << n)]
    for i in range(n): dp[1 << i][i] = len(words[i])
    for m in range(1 << n):
        for i in range(n):
            if dp[m][i] == INF: continue
            for j in range(n):
                if m >> j & 1: continue
                nm = m | 1 << j; c = dp[m][i] + len(words[j]) - ov[i][j]
                if c < dp[nm][j]: dp[nm][j] = c; par[nm][j] = i
    full = (1 << n) - 1; i = min(range(n), key=lambda x: dp[full][x]); order = []; m = full
    while i != -1:
        order.append(i); p = par[m][i]; m ^= 1 << i; i = p
    order.reverse(); res = words[order[0]]
    for a, b in zip(order, order[1:]): res += words[b][ov[a][b]:]
    return res

r = shortest_superstring(["alex","loves","leetcode"]); assert len(r) == 17 and all(w in r for w in ["alex","loves","leetcode"])
