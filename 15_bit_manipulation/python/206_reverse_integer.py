# LC#7 — Reverse Integer
# Difficulty: Medium | Pattern: Math with overflow check | Time: O(log n) | Space: O(1)
def reverse(x):
    sign = -1 if x < 0 else 1
    r = sign * int(str(abs(x))[::-1])
    return r if -2**31 <= r <= 2**31 - 1 else 0

assert reverse(123) == 321 and reverse(-120) == -21 and reverse(1534236469) == 0
