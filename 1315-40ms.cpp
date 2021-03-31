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
    int sumEvenGrandparent(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int curSum = 0;
        TreeNode* leftSubtree = root->left;
        TreeNode* rightSubtree = root->right;
        
        if (root->val % 2 == 0) {
            if (leftSubtree != NULL) {
                curSum += (leftSubtree->left != NULL) ? 
                    leftSubtree->left->val : 0;
                curSum += (leftSubtree->right != NULL) ? 
                    leftSubtree->right->val : 0;
            }
            if (rightSubtree != NULL) {
                curSum += (rightSubtree->left != NULL) ? 
                    rightSubtree->left->val : 0;
                curSum += (rightSubtree->right != NULL) ? 
                    rightSubtree->right->val : 0;
            }
            if (curSum == 0) {
                return curSum;
            }
        }
        return curSum  + sumEvenGrandparent(leftSubtree) + sumEvenGrandparent(rightSubtree);
        
    }
};