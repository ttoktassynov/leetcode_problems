#include <iostream>

using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

int goodNodes(TreeNode* root) {
    int ans = 0;
    dfs(root, root->val, ans);
    return ans;
}
void dfs(TreeNode* node, int maxSoFar, int& ans){
    if (!node) return;
    
    if (node->val >= maxSoFar){
        maxSoFar = node->val;
        ++ans;
    }
    dfs(node->left, maxSoFar);
    dfs(node->right, maxSoFar);
}
int main(){
    
}