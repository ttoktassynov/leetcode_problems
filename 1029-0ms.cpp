//https://leetcode.com/problems/two-city-scheduling/
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int totalCost = 0;
        int a = 0, b = 0;
        int n = costs.size() / 2;
        
        sort(begin(costs), end(costs), [](const auto& lhs, const auto& rhs) {
            return abs(lhs[0] - lhs[1]) > abs(rhs[0] - rhs[1]);
        });
            
        for (const auto& cost: costs) {
            
            if (cost[0] < cost[1]) {
                if (a < n) {
                    totalCost += cost[0];
                    a++;
                }
                else {
                    totalCost += cost[1];
                    b++;
                }
            }
            else {
                if (b < n) {
                    totalCost += cost[1];
                    b++;
                }else{
                    totalCost += cost[0];
                    a++;
                }
            }
        }
        
        
        return totalCost;
    }
};