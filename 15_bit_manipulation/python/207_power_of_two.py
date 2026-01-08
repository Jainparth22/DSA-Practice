# LC#231 — Power of Two
# Difficulty: Easy | Pattern: n & (n-1) | Time: O(1) | Space: O(1)
def is_power_of_two(n): return n > 0 and n & (n - 1) == 0

assert is_power_of_two(16) and not is_power_of_two(3) and not is_power_of_two(0)
