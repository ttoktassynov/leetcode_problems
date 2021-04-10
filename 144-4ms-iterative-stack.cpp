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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        vector<int> out_list;
        stack<TreeNode*> tree_stack;
        tree_stack.push(root);
        
        while(!tree_stack.empty()) {
            TreeNode* cur_node = tree_stack.top();
            tree_stack.pop();
            out_list.push_back(cur_node->val);
            if (cur_node->right != NULL) {
                tree_stack.push(cur_node->right);
            }
            if (cur_node->left != NULL) {
                tree_stack.push(cur_node->left);
            }
        }
        return out_list;
        
    }
};