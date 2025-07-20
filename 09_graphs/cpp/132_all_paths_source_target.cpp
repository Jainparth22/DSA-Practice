// LC#797 — All Paths From Source to Target
// Difficulty: Medium | Pattern: DFS Backtracking | Time: O(2^n * n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
void go(vector<vector<int>>& g, int u, vector<int>& path, vector<vector<int>>& res) {
    path.push_back(u);
    if (u == (int)g.size() - 1) res.push_back(path);
    else for (int v : g[u]) go(g, v, path, res);
    path.pop_back();
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) { vector<vector<int>> res; vector<int> p; go(g, 0, p, res); return res; }
int main() { vector<vector<int>> g = {{1,2},{3},{3},{}}; cout << allPathsSourceTarget(g).size() << endl; } // 2
