https://leetcode.com/problems/two-city-scheduling/
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int totalCost = 0;
        int n = costs.size() / 2;
        
        sort(begin(costs), end(costs), [](const auto& lhs, const auto& rhs) {
            return (lhs[0] - lhs[1]) < (rhs[0] - rhs[1]);
        });
            
        for (int i = 0; i < costs.size(); i++) {
            totalCost += (i < n) ? costs[i][0] : costs[i][1];
        }
        
        return totalCost;
    }
};