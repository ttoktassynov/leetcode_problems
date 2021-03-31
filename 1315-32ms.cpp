//https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
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
    struct RelativeInfo {
        int grandVal;
        int dadVal;
        TreeNode* node;
    };
public:
    int sumEvenGrandparent(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<RelativeInfo> myQueue;
        myQueue.push({1, 1, root});
        int totalSum  = 0;
        while (!myQueue.empty()) {
            auto curEl = myQueue.front();
            if (curEl.grandVal % 2 == 0) {
                totalSum += curEl.node->val;
            }
            if (curEl.node->left != NULL) {
                myQueue.push({curEl.dadVal, curEl.node->val, curEl.node->left});
            }
            if (curEl.node->right != NULL) {
                myQueue.push({curEl.dadVal, curEl.node->val, curEl.node->right});
            }
            myQueue.pop();
        }
        return totalSum;
    }
};