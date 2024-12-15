# LC#38 — Count and Say
# Difficulty: Medium | Pattern: Simulation | Time: O(2^n) | Space: O(2^n)
def count_and_say(n):
    s = "1"
    for _ in range(n - 1):
        t, i = [], 0
        while i < len(s):
            j = i
            while j < len(s) and s[j] == s[i]: j += 1
            t.append(f"{j - i}{s[i]}"); i = j
        s = "".join(t)
    return s

assert count_and_say(4) == "1211"
