/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        std::unordered_map<Node*, Node*> m;
        std::queue<Node*> q;

        m[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()){
            Node* cur = q.front();
            q.pop();

            for (auto n : cur->neighbors){
                if (!m.count(n)){
                    m[n] = new Node(n->val);
                    q.push(n);
                }
                m[cur]->neighbors.push_back(m[n]);
            }
        }





        return m[node];
    }
};
