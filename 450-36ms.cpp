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
    TreeNode* minElement(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int val) {
        if (root == NULL) {
            return NULL;
        }
        if (val < root->val) {
            root->left = deleteNode(root->left, val);
        }
        else if (val > root->val) {
            root->right =  deleteNode(root->right, val);
        }
        else {
            if (root->left != NULL && root->right != NULL) {
                TreeNode* inorderSucc = minElement(root->right);
                root->val = inorderSucc->val;
                root->right = deleteNode(root->right, inorderSucc->val);
                return root;
            }
            else if (root->left != NULL) {
                TreeNode* out = root->left;
                delete root;
                return out;
            }
            else if (root->right != NULL) {
                TreeNode * out = root->right;
                delete root;
                return out;
            }
            else {
                return NULL;
            }
        }
        return root;
    }
};