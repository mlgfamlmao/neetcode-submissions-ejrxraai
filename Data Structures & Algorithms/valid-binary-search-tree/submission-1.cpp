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
    
public:

    bool helper (TreeNode* root, int low , int high){
    if (root == nullptr) return true;

    if (root->val <= low || root->val >= high) return false;

    if (helper(root->left, low, root->val) && helper(root->right, root->val, high)){
        return true;

    }
    else return false;

    }
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MIN, INT_MAX);
        

        

         
        
    }
};
