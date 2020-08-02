class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i ++)
            for (int j = 0; j < grid[0].size(); j ++) 
                if (grid[i][j] == '1') {
                    res ++;
                    dfs(grid, i, j);
                }
        return res;
    }
    void dfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';  
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i ++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >=0 && b >= 0 && a < grid.size() && b < grid[0].size() && grid[a][b] == '1')
                dfs(grid, a, b);
        }
    }
};
