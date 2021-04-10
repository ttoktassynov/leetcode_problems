class Solution {
    
    int getAreaByDfs(vector<vector<int>>& grid,
                vector<vector<int>>& used, 
                pair<int,int> start) {
        int i = start.first;
        int j = start.second;
        if (!(i >= 0 && i < grid.size() && 
            j >= 0 && j < grid[0].size())) {
            return 0;
        }
        if (!grid[i][j] || used[i][j]) {
            return 0;
        }
        used[i][j] = 1;
        return 1 + getAreaByDfs(grid, used, {i + 1, j}) 
            + getAreaByDfs(grid, used, {i, j + 1})
            + getAreaByDfs(grid, used, {i, j - 1})
            + getAreaByDfs(grid, used, {i - 1, j});
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = (int) grid.size();
        if (n == 0) {
            return 0;
        }
        int m = (int) grid[0].size();
        vector<vector<int>> used(n, vector<int>(m, 0));

        
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !used[i][j]) {
                    maxArea = max(maxArea, getAreaByDfs(grid, used, {i,j}));
                }
            }
        }
        return maxArea;
    }
};