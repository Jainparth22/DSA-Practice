# LC#797 — All Paths From Source to Target
# Difficulty: Medium | Pattern: DFS Backtracking | Time: O(2^n * n) | Space: O(n)
def all_paths_source_target(g):
    res = []
    def go(u, path):
        path.append(u)
        if u == len(g) - 1: res.append(path[:])
        else:
            for v in g[u]: go(v, path)
        path.pop()
    go(0, [])
    return res

assert all_paths_source_target([[1,2],[3],[3],[]]) == [[0,1,3],[0,2,3]]
