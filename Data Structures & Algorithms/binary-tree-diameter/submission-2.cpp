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
    int diameter{0};
    int height(TreeNode* root){

       
        if(root == nullptr){return 0;}

        int leftHeight{ height(root->left)};
        int rightHeight{ height(root->right)};
        diameter = std::max(leftHeight + rightHeight, diameter);

        return 1+ std::max(leftHeight,rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);

        return diameter;
        
    }
};
