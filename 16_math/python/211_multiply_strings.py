# LC#43 — Multiply Strings
# Difficulty: Medium | Pattern: Grade-school multiplication | Time: O(mn) | Space: O(m+n)
def multiply(a, b):
    if a == "0" or b == "0": return "0"
    r = [0] * (len(a) + len(b))
    for i in range(len(a) - 1, -1, -1):
        for j in range(len(b) - 1, -1, -1):
            s = int(a[i]) * int(b[j]) + r[i + j + 1]
            r[i + j + 1] = s % 10; r[i + j] += s // 10
    return "".join(map(str, r)).lstrip("0")

assert multiply("123", "456") == "56088" and multiply("2", "3") == "6"
