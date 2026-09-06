/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


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