# LC#54 — Spiral Matrix
# Difficulty: Medium
# Pattern: Matrix Simulation with Boundary Shrinking
# Time: O(m*n) | Space: O(1) extra
#
# Approach:
#   Use four boundaries (top, bottom, left, right).
#   Each pass: go right, down, left, up — then shrink the boundary.

class Solution:
    def spiralOrder(self, matrix: list[list[int]]) -> list[int]:
        result = []
        top, bottom = 0, len(matrix) - 1
        left, right = 0, len(matrix[0]) - 1

        while top <= bottom and left <= right:
            # Right
            for col in range(left, right + 1):
                result.append(matrix[top][col])
            top += 1

            # Down
            for row in range(top, bottom + 1):
                result.append(matrix[row][right])
            right -= 1

            # Left
            if top <= bottom:
                for col in range(right, left - 1, -1):
                    result.append(matrix[bottom][col])
                bottom -= 1

            # Up
            if left <= right:
                for row in range(bottom, top - 1, -1):
                    result.append(matrix[row][left])
                left += 1

        return result


if __name__ == "__main__":
    s = Solution()
    assert s.spiralOrder([[1, 2, 3], [4, 5, 6], [7, 8, 9]]) == [1, 2, 3, 6, 9, 8, 7, 4, 5]
    assert s.spiralOrder([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]) == [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
    assert s.spiralOrder([[1]]) == [1]
    print("All tests passed!")
