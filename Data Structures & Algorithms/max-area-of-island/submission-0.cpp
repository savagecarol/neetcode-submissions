class Solution {
public:

    int island(vector<vector<int>>& grid, vector<vector<bool>>& dp,
            int i, int j, int n, int m) {

    if (i<0 || i>=n || j<0 || j>=m) return 0; 
    if (dp[i][j] || grid[i][j]==0) return 0; 

    dp[i][j] = true;

    return 1 + island(grid, dp, i-1, j,n, m)
             + island(grid, dp, i+1, j,   n, m) 
             + island(grid, dp, i,   j-1, n, m) 
             + island(grid, dp, i,   j+1, n, m); 
    
    }

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size(), count = 0;
    vector<vector<bool>> dp(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j]==1 && !dp[i][j]) 
                count = max(island(grid, dp, i, j, n, m),count);
        return count;
    }

};
