# LC#118 — Pascal's Triangle
# Difficulty: Easy | Pattern: Simulation | Time: O(n^2) | Space: O(n^2)
def generate(n):
    t = []
    for i in range(n):
        row = [1] * (i + 1)
        for j in range(1, i): row[j] = t[i-1][j-1] + t[i-1][j]
        t.append(row)
    return t

assert generate(5)[4] == [1,4,6,4,1]
