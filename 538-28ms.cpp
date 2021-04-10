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
    int delta = 0;
    void rinorder(TreeNode* root) {
        if (root !=NULL){
            rinorder(root->right);
            root->val += delta; 
            delta = root->val;
            rinorder(root->left);
        }
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        rinorder(root);
        return root;
    }
    
};