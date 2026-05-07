# LC#1065 — Index Pairs of a String
# Difficulty: Easy | Pattern: Trie scan | Time: O(n * L) | Space: O(total chars)
def index_pairs(text, words):
    d = set(words)
    return [[i, j] for i in range(len(text)) for j in range(i, len(text)) if text[i:j+1] in d]

assert index_pairs("thestoryofleetcodeandme", ["story","fleet","leetcode"]) == [[3,7],[9,13],[10,17]]
