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

    void inorder(TreeNode* root, std::vector<int> &result){
        if (root ==nullptr) return;

        inorder(root->left, result);

        result.push_back(root->val);

        inorder(root->right, result);



    }
public:
    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> result;
        inorder(root, result );

        return result[k-1];

        
    }
};
