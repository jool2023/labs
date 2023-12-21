1. Двоичное дерево поиска (Binary Search Tree) в C++:
#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    bool search(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (node->data == value) {
            return true;
        } else if (value < node->data) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) {
        return search(root, value);
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);

    std::cout << "Search 3: " << (bst.search(3) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 6: " << (bst.search(6) ? "Found" : "Not Found") << std::endl;

    return 0;
}

2. Heap (Куча) в C++:
#include <iostream>
#include <vector>
#include <algorithm>

class MaxHeap {
private:
    std::vector<int> heap;

public:
    void insert(int value) {
        heap.push_back(value);
        std::push_heap(heap.begin(), heap.end());
    }

    bool search(int value) {
        return std::find(heap.begin(), heap.end(), value) != heap.end();
    }
};

int main() {
    MaxHeap maxHeap;
    maxHeap.insert(5);
    maxHeap.insert(3);
    maxHeap.insert(7);

    std::cout << "Search 3: " << (maxHeap.search(3) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 6: " << (maxHeap.search(6) ? "Found" : "Not Found") << std::endl;

    return 0;
}

3. Связанный список (Linked List) в C++:
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
};

int main() {
    LinkedList linkedList;
    linkedList.insert(5);
    linkedList.insert(3);
    linkedList.insert(7);

    // You can add more functionality as needed

    return 0;
}

4. Префиксное дерево (Trie) в C++:
#include <iostream>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

    void insert(TrieNode* node, const std::string& word) {
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    bool search(TrieNode* node, const std::string& word) {
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }

public:
    Trie() : root(new TrieNode()) {}

    void insert(const std::string& word) {
        insert(root, word);
    }

    bool search(const std::string& word) {
        return search(root, word);
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apricot");

    std::cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 'ap': " << (trie.search("ap") ? "Found" : "Not Found") << std::endl;

    return 0;
}
