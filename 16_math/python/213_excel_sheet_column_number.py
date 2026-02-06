# LC#171 — Excel Sheet Column Number
# Difficulty: Easy | Pattern: Base-26 | Time: O(n) | Space: O(1)
def title_to_number(s):
    r = 0
    for c in s: r = r * 26 + ord(c) - 64
    return r

assert title_to_number("A") == 1 and title_to_number("AB") == 28 and title_to_number("ZY") == 701
