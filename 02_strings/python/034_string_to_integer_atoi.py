# LC#8 — String to Integer (atoi)
# Difficulty: Medium | Pattern: Parsing | Time: O(n) | Space: O(1)
def my_atoi(s):
    i, n, sign, r = 0, len(s), 1, 0
    while i < n and s[i] == " ": i += 1
    if i < n and s[i] in "+-":
        sign = -1 if s[i] == "-" else 1; i += 1
    while i < n and s[i].isdigit():
        r = r * 10 + int(s[i]); i += 1
    return max(-2**31, min(2**31 - 1, sign * r))

assert my_atoi("   -42abc") == -42 and my_atoi("9999999999") == 2**31 - 1
