# LC#151 — Reverse Words in a String
# Difficulty: Medium | Pattern: Split / Two Pointers | Time: O(n) | Space: O(n)
def reverse_words(s):
    return " ".join(reversed(s.split()))

assert reverse_words("  the sky  is blue ") == "blue is sky the"
