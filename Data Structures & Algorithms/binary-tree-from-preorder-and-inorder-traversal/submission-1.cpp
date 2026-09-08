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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       
            if (preorder.empty()) {
            return nullptr;
        }

        int rootValue = preorder[0];

        TreeNode* root = new TreeNode(rootValue);

        int midPoint = 0;

        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == rootValue) {
                midPoint = i;
                break;
            }
        }

        std::vector<int> leftInorder(inorder.begin(), inorder.begin() + midPoint);
        std::vector<int> rightInorder(inorder.begin() + midPoint + 1, inorder.end());

        std::vector<int> leftPreorder(preorder.begin() + 1,
                                 preorder.begin() + 1 + midPoint);

        std::vector<int> rightPreorder(preorder.begin() + 1 + midPoint,
                                  preorder.end());
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);

        return root;







    }



};

