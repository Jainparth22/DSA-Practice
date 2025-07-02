# LC#695 — Max Area of Island
# Difficulty: Medium | Pattern: DFS on grid | Time: O(mn) | Space: O(mn)
def max_area_of_island(g):
    R, C = len(g), len(g[0])
    def dfs(i, j):
        if i < 0 or j < 0 or i >= R or j >= C or not g[i][j]: return 0
        g[i][j] = 0
        return 1 + dfs(i+1, j) + dfs(i-1, j) + dfs(i, j+1) + dfs(i, j-1)
    return max(dfs(i, j) for i in range(R) for j in range(C))

assert max_area_of_island([[1,1,0],[0,1,0],[0,0,1]]) == 3
