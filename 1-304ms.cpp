class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (size_t first = 0; first < nums.size(); ++first) {
            for (size_t second = first + 1; second < nums.size(); ++second){
                if ((nums[first] + nums[second]) == target) {
                    return {static_cast<int>(first), static_cast<int>(second)};
                }
            }
        }   
        return {};
    }
};