# LC#17 — Letter Combinations of Phone Number
# Difficulty: Medium | Pattern: Backtracking | Time: O(4^n) | Space: O(n)
def letter_combinations(d):
    if not d: return []
    m = {"2":"abc","3":"def","4":"ghi","5":"jkl","6":"mno","7":"pqrs","8":"tuv","9":"wxyz"}
    res = [""]
    for c in d: res = [p + l for p in res for l in m[c]]
    return res

assert len(letter_combinations("23")) == 9 and letter_combinations("") == []
