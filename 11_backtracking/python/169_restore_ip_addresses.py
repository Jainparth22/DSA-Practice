# LC#93 — Restore IP Addresses
# Difficulty: Medium | Pattern: Backtracking | Time: O(3^4) | Space: O(1)
def restore_ip_addresses(s):
    res = []
    def go(i, parts):
        if len(parts) == 4:
            if i == len(s): res.append(".".join(parts))
            return
        for n in (1, 2, 3):
            seg = s[i:i+n]
            if len(seg) == n and not (n > 1 and seg[0] == "0") and int(seg) <= 255: go(i + n, parts + [seg])
    go(0, [])
    return res

assert sorted(restore_ip_addresses("25525511135")) == ["255.255.11.135", "255.255.111.35"]
