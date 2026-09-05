class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> q;
        std::vector<std::vector<int>> solution;

        if (root == nullptr) {
            return solution;
        }

        q.push(root);

        while (!q.empty()) {
            int size{static_cast<int>(q.size())};
            std::vector<int> levelVector;

            for (int i{0}; i < size; i++) {
                TreeNode* node{q.front()};
                q.pop();

                levelVector.push_back(node->val);

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            solution.push_back(levelVector);
        }

        return solution;
    }
};