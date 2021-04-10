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
    TreeNode* deleteRootNode(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        if (root->left == NULL) {
            return root->right;
        }
        if (root->right == NULL) {
            return root->left;
        }
        TreeNode* curNode = root->right;
        TreeNode* parent = NULL;
        while (curNode->left != NULL) {
            parent = curNode;
            curNode = curNode->left;
        }
        curNode->left = root->left;
        if (root->right != curNode) {
            parent->left = curNode->right;
            curNode->right = root->right;
        }
        return curNode;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int val) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* curNode = root;
        TreeNode* parent = NULL;
        while (curNode != NULL && curNode->val != val){
            parent = curNode;
            if (val < curNode->val) {
                curNode = curNode->left;
            }
            else if (val > curNode->val) {
                curNode = curNode->right;
            }
        }
        if (parent == NULL) {
            return deleteRootNode(curNode);
        }
        if (parent->left == curNode) {
            parent->left = deleteRootNode(curNode);
        }
        if (parent->right == curNode){
            parent->right =  deleteRootNode(curNode);
        } 
        return root;
    }
};