# LC#588 — Design In-Memory File System
# Difficulty: Hard | Pattern: Trie of directories | Time: O(path) | Space: O(total)
class FileSystem:
    class Node:
        def __init__(self): self.kids = {}; self.content = ""; self.file = False
    def __init__(self): self.root = self.Node()
    def _walk(self, path):
        t = self.root
        for part in path.split("/"):
            if part:
                if part not in t.kids: t.kids[part] = self.Node()
                t = t.kids[part]
        return t
    def ls(self, path):
        t = self._walk(path)
        return [path.split("/")[-1]] if t.file else sorted(t.kids)
    def mkdir(self, path): self._walk(path)
    def add_content_to_file(self, path, content):
        t = self._walk(path); t.file = True; t.content += content
    def read_content_from_file(self, path): return self._walk(path).content

fs = FileSystem(); fs.mkdir("/a/b/c"); fs.add_content_to_file("/a/b/c/d", "hello")
assert fs.ls("/") == ["a"] and fs.read_content_from_file("/a/b/c/d") == "hello" and fs.ls("/a/b/c/d") == ["d"]
