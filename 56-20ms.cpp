//https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> results;
        sort(begin(intervals), end(intervals), [](const auto& lhs, const auto& rhs)         {
            return lhs[0] < rhs[0];    
        });
        
        int n = (int) intervals.size();
        int i = 0, j;
        while (i < n) {
            j = i + 1;
            int curEnd = intervals[i][1];
            while (j < n 
                   && curEnd >= intervals[j][0] ) {
                if (curEnd < intervals[j][1]){
                    curEnd = intervals[j][1]; 
                }
                j++;
            }
            results.push_back({intervals[i][0], curEnd});
            i = j;
        }
        return results;
    }
};