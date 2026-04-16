class Solution {
public:
void islandsAndTreasure(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    queue<pair<int,int>> q;
    vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(grid[i][j] == 0) q.push({i, j});

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        for(auto [dx, dy] : dirs){
            int nx = x + dx;
            int ny = y + dy;

            if(nx >= 0 && nx < rows && ny >= 0 && ny < cols  && grid[nx][ny] == INT_MAX){
                grid[nx][ny] = grid[x][y] + 1;  
                q.push({nx, ny});
            }
        }
    }
}
};
