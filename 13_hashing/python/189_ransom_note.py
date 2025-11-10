# LC#383 — Ransom Note
# Difficulty: Easy | Pattern: Frequency count | Time: O(m+n) | Space: O(1)
from collections import Counter

def can_construct(ransom, magazine):
    return not (Counter(ransom) - Counter(magazine))

assert not can_construct("a", "b") and can_construct("aa", "aab")
