//https://leetcode.com/problems/number-of-islands/
class Solution {
    
    int crossOffIsland(vector<vector<char>>& grid,
                vector<vector<int>>& used, 
                pair<int,int> start) {
        int i = start.first;
        int j = start.second;
        if (!(i >= 0 && i < grid.size() && 
            j >= 0 && j < grid[0].size())) {
            return 0;
        }
        if (grid[i][j] == '0' || used[i][j]) {
            return 0;
        }
        used[i][j] = 1;
        return 1 + crossOffIsland(grid, used, {i + 1, j}) 
            + crossOffIsland(grid, used, {i, j + 1})
            + crossOffIsland(grid, used, {i, j - 1})
            + crossOffIsland(grid, used, {i - 1, j});
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = (int) grid.size();
        if (n == 0) {
            return 0;
        }
        int m = (int) grid[0].size();
        vector<vector<int>> used(n, vector<int>(m, 0));
        int counter = 0;
        
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !used[i][j]) {
                    crossOffIsland(grid, used, {i,j});
                    counter++;
                }
            }
        }
        return counter;
    }
};