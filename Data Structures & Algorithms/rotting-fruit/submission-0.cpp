class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
    
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;
    
        queue<pair<int,int>> q;
        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        int fresh = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] == 1) fresh++;
            }
        }
        
   while(!q.empty() && fresh > 0){
    int size = q.size();       
    for(int i = 0; i < size; i++) {  
        auto [x, y] = q.front();
        q.pop();
        for(auto [dx, dy] : dirs){
            int nx = x + dx;
            int ny = y + dy;
            if(nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1){
                grid[nx][ny] = 2;
                q.push({nx, ny});
                fresh--;
            }
        }
    }                          
    ans++;                      
    }

     return (fresh > 0)? -1 : ans; 
       
    }
};
