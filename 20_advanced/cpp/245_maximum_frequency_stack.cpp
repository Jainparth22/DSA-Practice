// LC#895 — Maximum Frequency Stack
// Difficulty: Hard | Pattern: Frequency -> Stack map | Time: O(1) per op | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
class FreqStack {
    unordered_map<int,int> cnt; unordered_map<int, vector<int>> groups; int maxf = 0;
public:
    void push(int x) { int f = ++cnt[x]; maxf = max(maxf, f); groups[f].push_back(x); }
    int pop() { int x = groups[maxf].back(); groups[maxf].pop_back(); if (groups[maxf].empty()) maxf--; cnt[x]--; return x; }
};
int main() { FreqStack s; for (int x : {5,7,5,7,4,5}) s.push(x); cout << s.pop() << s.pop() << s.pop() << s.pop() << endl; } // 5754
