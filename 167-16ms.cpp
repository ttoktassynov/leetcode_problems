class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> numPositionMap;
        for (int i = 0; i < (int) numbers.size(); i++) {
            int complement = target - numbers[i];
            if (numPositionMap.count(complement)) {
                return {numPositionMap.at(complement), i + 1};
            }
            numPositionMap[numbers[i]] = i + 1;
        }
        return {};
    }
};