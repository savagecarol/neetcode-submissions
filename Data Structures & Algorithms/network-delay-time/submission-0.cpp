class Solution {
public:

    void dfs(vector<vector<pair<int , int>>> &ad ,vector<int> &visit ,int k){
        for(auto it : ad[k]){  
            if(visit[it.first] > visit[k] + it.second) {
                visit[it.first] = visit[k] + it.second;
                dfs(ad ,visit,it.first);
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

            vector<vector<pair<int , int>>> ad(n);
            int len = times.size();

            for(int i = 0 ; i < len ;i++){
                    ad[times[i][0]-1].push_back({times[i][1]-1 ,times[i][2]});
            }
            vector<int> value(n , INT_MAX);
            value[k-1] = 0;
            dfs(ad ,value,k-1);

            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (value[i] == INT_MAX) return -1;
                ans = max(ans, value[i]);
            }
            return ans;
    }
};
