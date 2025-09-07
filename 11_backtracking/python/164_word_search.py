# LC#79 — Word Search
# Difficulty: Medium
# Pattern: Backtracking / DFS on Grid
# Time: O(m*n*4^L) | Space: O(L)
#
# Approach:
#   Try starting DFS from every cell.
#   At each step, check bounds, board char matches word[idx].
#   Mark visited with '#', recurse in 4 directions, restore on return.

class Solution:
    def exist(self, board: list[list[str]], word: str) -> bool:
        rows, cols = len(board), len(board[0])

        def dfs(r: int, c: int, idx: int) -> bool:
            if idx == len(word):
                return True
            if r < 0 or r >= rows or c < 0 or c >= cols or board[r][c] != word[idx]:
                return False
            tmp = board[r][c]
            board[r][c] = '#'
            found = (dfs(r + 1, c, idx + 1) or
                     dfs(r - 1, c, idx + 1) or
                     dfs(r, c + 1, idx + 1) or
                     dfs(r, c - 1, idx + 1))
            board[r][c] = tmp
            return found

        for r in range(rows):
            for c in range(cols):
                if dfs(r, c, 0):
                    return True
        return False


if __name__ == "__main__":
    s = Solution()
    b1 = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]
    assert s.exist(b1, "ABCCED") == True
    assert s.exist(b1, "SEE") == True
    assert s.exist(b1, "ABCB") == False
    assert s.exist([['a']], "a") == True
    print("All tests passed!")
