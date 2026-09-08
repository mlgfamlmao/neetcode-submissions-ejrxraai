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

class Codec {
public:

    
string serialize(TreeNode* root) {
    if (!root) return "N";
    std::queue<TreeNode*> q;
    q.push(root);
    std::string result;

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (!node) {
            result += "N,";
        } else {
            result += std::to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }
    }

    return result;

        
    }

TreeNode* deserialize(string data) {

        if (data == "N") {
            return nullptr;
        }

        std::vector<string> values;
        std::string current = "";

        for (int i = 0; i < data.size(); i++) {

            if (data[i] == ',') {
                values.push_back(current);
                current = "";
            }
            else {
                current += data[i];
            }
        }

        
        int index = 0;

        TreeNode* root = new TreeNode(stoi(values[index]));
        index++;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            
            if (values[index] != "N") {

                node->left = new TreeNode(stoi(values[index]));

                q.push(node->left);
            }

            index++;

 
            if (values[index] != "N") {

                node->right = new TreeNode(stoi(values[index]));

                q.push(node->right);
            }

            index++;
        }

        return root;


    }
};