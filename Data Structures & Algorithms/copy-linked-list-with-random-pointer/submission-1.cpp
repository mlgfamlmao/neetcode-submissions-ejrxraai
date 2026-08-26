/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/



class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        std::unordered_map<Node*, Node*> hash{};

        Node* iterator{head};

        
        while (iterator != nullptr) {
            hash[iterator] = new Node{iterator->val};
            iterator = iterator->next;
        }

        iterator = head;

        while (iterator != nullptr) {
            hash[iterator]->next = hash[iterator->next];
            hash[iterator]->random = hash[iterator->random];

            iterator = iterator->next;
        }

        return hash[head];
    }
};