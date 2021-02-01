class Solution {
public: 
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int> > triplets;
        unordered_set<int> dups;
        unordered_map<int, int>seen;
        
        for (int first = 0; first < (int) nums.size(); first++) {
            if (dups.insert(nums[first]).second) {
                for (int second = first + 1; second < (int) nums.size(); second++) {
                    int complement = -nums[first] - nums[second];
                    if (seen.count(complement) && seen.at(complement) == first) {
                        vector<int> triplet = {nums[first], nums[second], complement};
                        sort(begin(triplet), end(triplet));
                        triplets.insert(triplet);
                    }
                    seen[nums[second]] = first;
                }
            }
        }
        return vector<vector<int>>(begin(triplets), end(triplets));
    }
};