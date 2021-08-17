class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int first = 0; first < static_cast<int>(nums.size()) ; ++first) {
            int complement = target - nums[first]; 
            if (seen.count(complement)) {
                return {first, seen[complement]};
            }
            seen[nums[first]] = first;
        }
        return {};
    }
};