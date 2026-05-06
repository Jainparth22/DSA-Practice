# LC#720 — Longest Word in Dictionary
# Difficulty: Medium | Pattern: Sort + Set | Time: O(n log n) | Space: O(n)
def longest_word(words):
    ok = set(); best = ""
    for w in sorted(words):
        if len(w) == 1 or w[:-1] in ok:
            ok.add(w)
            if len(w) > len(best): best = w
    return best

assert longest_word(["w","wo","wor","worl","world"]) == "world" and longest_word(["a","banana","app","appl","ap","apply","apple"]) == "apple"
