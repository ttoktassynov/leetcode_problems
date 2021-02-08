class Solution {
public:
    void printArray(vector<int>& matrix) {
        for (int i = 0;i < matrix.size(); i++) {
            printf("\t%d ", matrix[i]);
        }
        cout << endl;
    }
    void printMatrix(vector<vector<int>>& matrix) {
        for (int i = 0;i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                printf("\t%d ", matrix[i][j]);
            }
            cout << endl;
        }
        cout << endl;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        //[1,-3,2,3,-4]
        //[-3,-5,-3,-2,-6,3,10,-10,-8,-3,0,10,3,-5,8,7,-9,-9,5,-8]
        //maxAbs = 5
        //i = 4
        //curPsum = 1
        //curMsum = 4
        int maxAbsSum = 0;
        vector<int> dp(nums.size(), 0);
        vector<int> prevDp(nums.size(), 0);
        
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = dp[i - 1] + nums[i];
            maxAbsSum = max(maxAbsSum, max(abs(dp[i]), dp[i]));
        }
        
        for (int i = 1; i < nums.size(); i++) {
            prevDp = dp;
            for (int j = i; j < nums.size(); j++) {
                prevDp[j] = dp[j] - nums[i - 1];
                maxAbsSum = max(maxAbsSum, max(abs(prevDp[j]), prevDp[j]));
            }
            dp = prevDp;
        }
        
        return maxAbsSum;
    }
};