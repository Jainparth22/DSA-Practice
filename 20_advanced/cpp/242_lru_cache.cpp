// LC#146 — LRU Cache
// Difficulty: Medium
// Pattern: Hash Map + Doubly Linked List
// Time: O(1) for get and put | Space: O(capacity)
//
// Approach:
//   Doubly linked list: most-recently-used at HEAD, least-recently-used at TAIL.
//   Hash map: key -> node pointer for O(1) lookup.
//   get:  if key exists, move node to head, return value.
//   put:  if key exists, update + move to head.
//         else insert at head; if over capacity, remove tail node.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, val;
    Node *prev, *next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head; // dummy head (MRU side)
    Node* tail; // dummy tail (LRU side)

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insertFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
public:
    LRUCache(int cap) : capacity(cap) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        if (!cache.count(key)) return -1;
        Node* node = cache[key];
        remove(node);
        insertFront(node);
        return node->val;
    }
    void put(int key, int value) {
        if (cache.count(key)) {
            remove(cache[key]);
            delete cache[key];
            cache.erase(key);
        }
        Node* node = new Node(key, value);
        cache[key] = node;
        insertFront(node);
        if ((int)cache.size() > capacity) {
            Node* lru = tail->prev;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

int main() {
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl;   // 1
    lru.put(3, 3);                // evicts key 2
    cout << lru.get(2) << endl;   // -1 (evicted)
    lru.put(4, 4);                // evicts key 1
    cout << lru.get(1) << endl;   // -1 (evicted)
    cout << lru.get(3) << endl;   // 3
    cout << lru.get(4) << endl;   // 4

    cout << "All tests passed!" << endl;
    return 0;
}
