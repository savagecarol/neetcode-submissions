class Solution {
public:


    // bool pacific(vector<vector<int>>& heights, int i , int j, int &n, int &m, vector<vector<int>> &p,vector<vector<int>> &vis){               
    //     if(i==0 || j==0 || p[i][j] == 1) {
    //         p[i][j] = 1;
    //         return true;
    //     }
    //     if (vis[i][j]) return false;
    //     vis[i][j] = 1;

    //     bool left = false , right = false , top = false , bottom = false;

    //     if(i-1 >= 0 && heights[i-1][j] <= heights[i][j]) left = pacific(heights,i-1 , j , n, m, p,vis);
    //     if(j-1 >= 0 && heights[i][j-1] <= heights[i][j]) bottom = pacific(heights,i , j-1 , n, m, p,vis);
    //     if(i+1 < n && heights[i+1][j] <= heights[i][j]) right = pacific(heights,i+1 , j , n, m, p,vis);
    //     if(j+1 < m && heights[i][j+1] <= heights[i][j]) top = pacific(heights,i , j+1 , n, m, p,vis); 
        
    //     vis[i][j] = 0;
    //     if(left || right || top || bottom) {
    //         p[i][j] = 1;
    //         return true;
    //     }
    //     return false;
    // }

    //  bool atlantic(vector<vector<int>>& heights, int i , int j, int &n, int &m, vector<vector<int>> &a,vector<vector<int>> &vis){               
        
    //     if(i==n-1 || j==m-1 || a[i][j] == 1) {
    //         a[i][j] = 1;
    //         return true;
    //     }
    //     if (vis[i][j]) return false;
    //     vis[i][j] = 1;

    //     bool left = false , right = false , top = false , bottom = false;

    //     if(i-1 >=0  && heights[i-1][j] <= heights[i][j]) left = atlantic(heights,i-1 , j , n, m, a,vis);
    //     if(j-1 >=0 && heights[i][j-1] <= heights[i][j]) bottom = atlantic(heights,i , j-1 , n, m, a,vis);
    //     if(i+1 < n && heights[i+1][j] <= heights[i][j]) right = atlantic(heights,i+1 , j , n, m, a,vis);
    //     if(j+1 < m && heights[i][j+1] <= heights[i][j]) top = atlantic(heights,i , j+1 , n, m, a,vis); 

    //     vis[i][j] = 0;
    //     if(left || right || top || bottom) {
    //         a[i][j] = 1;
    //         return true;
    //     }
    //     return false;
    // }

    // vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    //         int n = heights.size();
    //         int m = heights[0].size();
    //         vector<vector<int>> ans;

    //         vector<vector<int>> p( n , vector<int>(m , 0));
    //         vector<vector<int>> a( n , vector<int>(m , 0));
    //         vector<vector<int>> vis(n, vector<int>(m, 0));

    //         for(int i = 0 ; i < n ; i++){
    //             for(int j = 0 ; j < m ; j++){
    //                 if(pacific(heights , i , j , n , m,p,vis) && atlantic(heights , i , j , n , m,a,vis)){
    //                     ans.push_back({i , j});
    //                 }    
    //             }
    //         }
    //         return ans;
        
    // }


    void bfs(vector<vector<int>>& heights, queue<pair<int,int>>& q,
             vector<vector<bool>>& visited, int n, int m) {
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            for (auto& d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                if (visited[ni][nj]) continue;
                if (heights[ni][nj] < heights[i][j]) continue;
                visited[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> p(n, vector<bool>(m, false));
        vector<vector<bool>> a(n, vector<bool>(m, false));
        queue<pair<int,int>> pq, aq;

        for (int i = 0; i < n; i++) {
            pq.push({i, 0});   p[i][0]   = true;
            aq.push({i, m-1}); a[i][m-1] = true;
        }
        for (int j = 0; j < m; j++) {
            pq.push({0, j});   p[0][j]   = true;
            aq.push({n-1, j}); a[n-1][j] = true;
        }

        bfs(heights, pq, p, n, m);
        bfs(heights, aq, a, n, m);

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (p[i][j] && a[i][j])
                    ans.push_back({i, j});
        return ans;
    }


};
