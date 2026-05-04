# LC#648 — Replace Words
# Difficulty: Medium | Pattern: Trie | Time: O(total chars) | Space: O(dict chars)
def replace_words(dictionary, sentence):
    root = {}
    for w in dictionary:
        t = root
        for c in w: t = t.setdefault(c, {})
        t["$"] = True
    def short(w):
        t = root
        for i, c in enumerate(w):
            if c not in t: break
            t = t[c]
            if "$" in t: return w[:i+1]
        return w
    return " ".join(short(w) for w in sentence.split())

assert replace_words(["cat","bat","rat"], "the cattle was rattled by the battery") == "the cat was rat by the bat"
