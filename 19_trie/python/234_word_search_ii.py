# LC#212 — Word Search II
# Difficulty: Hard | Pattern: Trie + DFS | Time: O(mn * 4^L) | Space: O(total chars)
def find_words(board, words):
    root = {}
    for w in words:
        t = root
        for c in w: t = t.setdefault(c, {})
        t["$"] = w
    R, C = len(board), len(board[0]); res = []
    def dfs(i, j, t):
        if i < 0 or j < 0 or i >= R or j >= C or board[i][j] not in t: return
        ch = board[i][j]; t = t[ch]
        if "$" in t: res.append(t.pop("$"))
        board[i][j] = "#"
        for x, y in ((i+1, j), (i-1, j), (i, j+1), (i, j-1)): dfs(x, y, t)
        board[i][j] = ch
    for i in range(R):
        for j in range(C): dfs(i, j, root)
    return res

b = [list("oaan"), list("etae"), list("ihkr"), list("iflv")]
assert sorted(find_words(b, ["oath","pea","eat","rain"])) == ["eat", "oath"]
