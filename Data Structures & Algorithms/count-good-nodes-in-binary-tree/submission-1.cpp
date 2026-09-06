class Solution {
    int result{0};

    void dfsHelper(TreeNode* root, int maxValue) {
        if (root == nullptr) {
            return;
        }

        if (root->val >= maxValue) {
            result++;
            maxValue = root->val;
        }

        dfsHelper(root->left, maxValue);
        dfsHelper(root->right, maxValue);
    }

public:
    int goodNodes(TreeNode* root) {
        dfsHelper(root, INT_MIN);
        return result;
    }
};