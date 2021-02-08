class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n = (int) matrix.size(), m = (int) matrix[0].size();
        vector<int> spiralList(n * m);
        vector<vector<bool>> seen(n, vector<bool>(m, false));
        int r = 0, c = 0, cr = 0, cc = 0, dir = 0;
        int rChange[4] = {0, 1, 0, -1};
        int cChange[4] = {1, 0, -1, 0};
        
        for (int i = 0; i < m * n; i++) {
            seen[r][c] = true;
            spiralList[i] = matrix[r][c];
            cr = r + rChange[dir];
            cc = c + cChange[dir];
            if (cr >= 0 && cr < n && cc >= 0 && cc < m && !seen[cr][cc]) {
                r = cr;
                c = cc;
            }
            else {
                dir = (dir + 1) % 4;
                r = r + rChange[dir];
                c = c + cChange[dir];
            }
        }
        
        return spiralList;
        
    }
};