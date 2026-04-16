class Solution {
public:

void island(vector<vector<char>>& grid, vector<vector<bool>>& dp,
            int i, int j, int n, int m) {
    if (i<0 || i>=n || j<0 || j>=m) return; 
    if (dp[i][j] || grid[i][j]=='0') return;  

    dp[i][j] = true;

    island(grid, dp, i-1, j,   n, m);  
    island(grid, dp, i+1, j,   n, m);  
    island(grid, dp, i,   j-1, n, m);  
    island(grid, dp, i,   j+1, n, m);  
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size(), count = 0;
    vector<vector<bool>> dp(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j]=='1' && !dp[i][j]) {
                island(grid, dp, i, j, n, m);
                count++;
            }

    return count;
}
};
