class Solution {
public:
    void twoSum(vector<int>& nums, int first, vector<vector<int> >& result) {
       
        unordered_set<int> seen;
        for (int second = first + 1; second < (int) nums.size(); second++){ 
            int complement = - nums[first] - nums[second];
            if (seen.count(complement)) {
                result.push_back({nums[first], complement, nums[second]});
                while(second + 1 < (int)nums.size() && nums[second] == nums[second + 1]) {
                    second++;
                }
            }
            seen.insert(nums[second]);
        }
    } 
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int> > result;
        
        cout << endl;
        for (int start = 0; start < (int) nums.size() && nums[start] <= 0; start++) {
            if (start == 0 || nums[start] != nums[start - 1] ) {
                twoSum(nums, start, result);
            }
        }
        return result;
    }
};