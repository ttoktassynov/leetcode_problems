//https://leetcode.com/problems/shuffle-an-array/
class Solution {
    vector<int> orig_nums;
    vector<int> cur_nums;
public:
    Solution(vector<int>& nums) : 
        orig_nums(nums), cur_nums(nums) {}
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        cur_nums = orig_nums;
        return cur_nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        unordered_set<int> used;
        int n = (int) cur_nums.size();
        vector<int> shuffled(n);
        for (int i = 0; i < n; i++){
            while(true){
                int id = rand() % n;
                if (!used.count(id)){
                    shuffled[i] = orig_nums[id];
                    used.insert(id);
                    break;
                }
            }
        }
        cur_nums = shuffled;
        return cur_nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */