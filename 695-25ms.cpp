class Solution {

    int getArea(vector<vector<int>>& grid,
                vector<vector<int>>& used, 
                pair<int,int> start) {
        queue<pair<int, int>> queue;
        queue.push(start);
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        
        int cnt = 0;
        while (!queue.empty()) {
            auto currentPoint = queue.front();
            int i = currentPoint.first;
            int j = currentPoint.second;
            queue.pop();
            used[i][j] = 1;
            cnt++;
            if (j > 0 && grid[i][j - 1] && !used[i][j - 1]) {
                queue.push({i, j - 1});
                used[i][j - 1] = 1;
            }
            if (i > 0 && grid[i - 1][j] && !used[i - 1][j]) {
                queue.push({i - 1, j});
                used[i - 1][j] = 1;
            }
            if (j < m - 1 && grid[i][j + 1] && !used[i][j + 1]) {
                queue.push({i, j + 1});
                used[i][j + 1] = 1;
            }
            if (i < n - 1 && grid[i + 1][j] && !used[i + 1][j]) {
                queue.push({i + 1, j});
                used[i + 1][j] = 1;
            }
            
        }
        return cnt;
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
                    maxArea = max(maxArea, getArea(grid, used, {i,j}));
                    
                }
            }
        }
        return maxArea;
    }
};