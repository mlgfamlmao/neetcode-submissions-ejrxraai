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
    int maxSum{INT_MIN};

    int dfs(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        int leftSum {dfs(root->left)};
        int rightSum {dfs(root->right)};

        leftSum = std::max(0, leftSum);
        rightSum = std::max(0, rightSum);





        int splitSum = root->val + leftSum + rightSum;

        maxSum = std::max(maxSum, splitSum);

        
        return root->val + std::max(leftSum, rightSum);

    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
        


    }
};
