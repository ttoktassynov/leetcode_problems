class Solution {
public:
    int middle(vector<int>& nums, int low, int mid, int high) {
        int leftSum = INT_MIN;
        int currSum = 0;
        for (int i = mid; i > low - 1; i--) {
            currSum += nums[i];
            leftSum = max(leftSum, currSum);
        }
        
        int rightSum = INT_MIN;
        currSum = 0;
        for (int i = mid + 1; i < high + 1; i++) {
            currSum += nums[i];
            rightSum = max(rightSum, currSum);
        }
        return leftSum + rightSum;
    }
    int helper(vector<int>& nums, int low, int high) {
        if (low == high) {
            return nums[low];
        }
        int mid = low + (high - low) / 2;
        int leftVal = helper(nums, low, mid);
        int rightVal = helper(nums, mid + 1, high);
        int midVal = middle(nums, low, mid, high);
        return max(max(leftVal, rightVal), midVal);
    }
    int maxSubArray(vector<int>& nums) {
        int low = 0, high = (int) nums.size() - 1;
        return helper(nums, low, high);
    }
};