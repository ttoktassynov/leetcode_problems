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
    int ans = - 1;
    void helper(TreeNode* root, int& k) {
        if (root != NULL){
            helper(root->left, k);
            if (k == 1) {
                ans = root->val;
            }
            k--;
            helper(root->right, k);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        helper(root, k);
        return ans;
    }
    
};