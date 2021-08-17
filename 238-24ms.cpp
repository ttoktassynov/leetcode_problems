//https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> ans(n, 0);
        for (int i = 0, curProd = 1; i < n; i++) {
            ans[i] = curProd;
            curProd *= nums[i];
        }
        for (int i = n - 1, curPod = 1; i >= 0; i--) {
            ans[i] *= curPod;
            curPod *= nums[i];
        }
        return ans;
    }
};