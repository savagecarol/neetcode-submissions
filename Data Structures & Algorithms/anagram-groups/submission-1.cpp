class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<int>> x; 
        int n = strs.size();
        
        for(int i = 0 ; i < n ; i++){
            vector<int> ar(26,0);
            for(int j = 0 ; j < strs[i].size() ; j++) {
                ar[strs[i][j] - 'a']++;
            }
            x[strs[i]] = ar;
        }
        
        vector<vector<string>> ans;
        vector<int> visit(n,0);

        for(int i = 0 ; i < n ; i++)
        {
            vector<string> res;
            if(visit[i] == 0) {
                res.push_back(strs[i]);
                visit[i] = 1;
            }
            for(int j = i+1; j < n ; j++){
                if(visit[j]== 0 && x[strs[j]] == x[strs[i]]){
                       visit[j] = 1;
                       res.push_back(strs[j]); 
                }
            }
            if(res.size()!= 0) ans.push_back(res);
        }
        return ans;    
    }
};
