# LC#190 — Reverse Bits
# Difficulty: Easy | Pattern: Bit shifting | Time: O(32) | Space: O(1)
def reverse_bits(n):
    r = 0
    for _ in range(32): r = (r << 1) | (n & 1); n >>= 1
    return r

assert reverse_bits(43261596) == 964176192
