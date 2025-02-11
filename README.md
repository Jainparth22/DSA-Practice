# DSA Practice — 300 Questions in C++ and Python

Curated interview-style data structures & algorithms problems, solved in both C++ and Python and organised by pattern.

## Stats
| Metric | Value |
|---|---|
| Total questions | 300 |
| Solved (C++ and Python) | 55 / 300 — see [PROGRESS.md](PROGRESS.md) |
| Categories | 20 |
| Languages | C++17 and Python 3 |

## Layout
Each topic folder has a `README.md` (question list with links), a `cpp/` folder and a `python/` folder. Files are named `NNN_problem_name`, where `NNN` is the question number in [PROGRESS.md](PROGRESS.md). Every file starts with the LeetCode number, difficulty, pattern, and time/space complexity.

## Compile & Run
```bash
# C++
g++ -std=c++17 -O2 01_arrays/cpp/001_two_sum.cpp -o sol && ./sol

# Python (each file ends with assert-based checks)
python 01_arrays/python/001_two_sum.py
```

## Categories

| # | Folder | Questions | Difficulty mix |
|---|---|---|---|
| 1 | [01_arrays](01_arrays/) | 20 | E×5, M×13, H×2 |
| 2 | [02_strings](02_strings/) | 15 | E×3, M×10, H×2 |
| 3 | [03_two_pointers](03_two_pointers/) | 10 | E×6, M×4 |
| 4 | [04_sliding_window](04_sliding_window/) | 10 | E×1, M×6, H×3 |
| 5 | [05_stack](05_stack/) | 10 | E×2, M×7, H×1 |
| 6 | [06_linked_list](06_linked_list/) | 15 | E×6, M×7, H×2 |
| 7 | [07_binary_search](07_binary_search/) | 12 | E×4, M×7, H×1 |
| 8 | [08_trees](08_trees/) | 20 | E×8, M×10, H×2 |
| 9 | [09_graphs](09_graphs/) | 20 | M×17, H×3 |
| 10 | [10_dynamic_programming](10_dynamic_programming/) | 25 | E×2, M×18, H×5 |
| 11 | [11_backtracking](11_backtracking/) | 12 | M×10, H×2 |
| 12 | [12_heap](12_heap/) | 10 | E×2, M×5, H×3 |
| 13 | [13_hashing](13_hashing/) | 10 | E×4, M×6 |
| 14 | [14_greedy](14_greedy/) | 10 | M×10 |
| 15 | [15_bit_manipulation](15_bit_manipulation/) | 8 | E×6, M×2 |
| 16 | [16_math](16_math/) | 8 | E×5, M×3 |
| 17 | [17_intervals](17_intervals/) | 8 | E×1, M×6, H×1 |
| 18 | [18_matrix](18_matrix/) | 8 | M×8 |
| 19 | [19_trie](19_trie/) | 7 | E×1, M×5, H×1 |
| 20 | [20_advanced](20_advanced/) | 62 | M×10, H×52 |

## Adding a question
1. Add the solution to the topic's `cpp/` and `python/` folders as `NNN_name`.
2. Mark it done in `PROGRESS.md`.
3. `git add . && git commit -m "solve: <title>" && git push`
