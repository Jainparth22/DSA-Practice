# LC#371 — Sum of Two Integers
# Difficulty: Medium | Pattern: XOR + carry | Time: O(1) | Space: O(1)
def get_sum(a, b):
    mask = 0xFFFFFFFF
    while b:
        a, b = (a ^ b) & mask, ((a & b) << 1) & mask
    return a if a <= 0x7FFFFFFF else ~(a ^ mask)

assert get_sum(1, 2) == 3 and get_sum(-2, 3) == 1 and get_sum(-1, -1) == -2
