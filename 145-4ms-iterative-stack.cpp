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
 * https://leetcode.com/problems/binary-tree-postorder-traversal/
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        stack<TreeNode*> root_stack, out_stack;
        root_stack.push(root);
        vector<int> out_list;
        
        while (!root_stack.empty()) {
            TreeNode* cur_root = root_stack.top();
            root_stack.pop();
            out_stack.push(cur_root);
            if (cur_root->left != NULL) {
                root_stack.push(cur_root->left);
            }
            if (cur_root->right != NULL) {
                root_stack.push(cur_root->right);
            }
        }
        while (!out_stack.empty()) {
            out_list.push_back(out_stack.top()->val);
            out_stack.pop();
        }
        return out_list;
    }
};