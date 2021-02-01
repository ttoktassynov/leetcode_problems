class Solution {
public:
 
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        sort(begin(nums), end(nums));
        unordered_set<int> set;
        unordered_set<int> used;
        
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            set.clear();
            used.clear();
            int target = -nums[i];
            
            for (int j = i + 1; j < (int) nums.size(); ++j) {
               
                int comp = target - nums[j];
                
                if (set.count(comp) && !used.count(nums[j])) {
                    result.push_back({nums[i], nums[j], comp});
                    used.insert(nums[j]);
                }
                set.insert(nums[j]);
            }
        } 
        
        return result;
    }
};