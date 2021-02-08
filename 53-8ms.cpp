class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSubarraySum = -1e5, curSubarraySum = nums[0];
        for (int i = 1; i < (int) nums.size(); i++) {
            maxSubarraySum = max(maxSubarraySum, curSubarraySum);
            curSubarraySum = max(nums[i], curSubarraySum + nums[i]);
        }
        return max(maxSubarraySum, curSubarraySum);
    }
};