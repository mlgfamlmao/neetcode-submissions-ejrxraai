#include <unordered_map>

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int inputKey, int inputValue) {
            key = inputKey;
            value = inputValue;
            prev = nullptr;
            next = nullptr;
        }
    };

    std::unordered_map<int, Node*> cache;
    int cacheCapacity;

    Node* head;
    Node* tail;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtEnd(Node* node) {
        node->prev = tail->prev;
        node->next = tail;

        tail->prev->next = node;
        tail->prev = node;
    }

public:
    LRUCache(int capacity) {
        cacheCapacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        Node* node = cache[key];

        remove(node);
        insertAtEnd(node);

        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];

            node->value = value;

            remove(node);
            insertAtEnd(node);
        }
        else {
            Node* newNode = new Node(key, value);

            cache[key] = newNode;
            insertAtEnd(newNode);

            if (cache.size() > cacheCapacity) {
                Node* leastUsed = head->next;

                remove(leastUsed);
                cache.erase(leastUsed->key);

                delete leastUsed;
            }
        }
    }
};