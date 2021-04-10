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
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> tree_stack;
        TreeNode* cur_node = root;
        int ans = - 1;
        while (cur_node != NULL || !tree_stack.empty()) {
            while (cur_node != NULL){
                tree_stack.push(cur_node);
                cur_node = cur_node->left;
            }
            TreeNode* tmp = tree_stack.top();
            tree_stack.pop();
            if (k == 1){
                ans = tmp->val;
                break;
            }
            k--;
            cur_node = tmp->right;
        }
        return ans;
    }
};