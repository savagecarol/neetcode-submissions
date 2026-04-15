class Solution {
public:

    void printdp( vector<vector<int>> dp){
        for(int i = 0 ;i <dp.size();i++){
            for(int j = 0; j < dp[0].size();j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
            int n = text1.size();
            int m = text2.size();
            vector<vector<int>> dp(n , vector<int>(m,0));
            bool visit = false;
            for(int i = 0 ; i < m ; i++) {
               if(text1[0] == text2[i] || visit) {
                    dp[0][i] = 1;
                    visit = true;
               }
            }

            visit = false;
            for(int i = 0 ; i < n ; i++) {
                if(text2[0] == text1[i] || visit) {
                    dp[i][0] = 1;
                    visit = true;
               }
            }
            printdp(dp);

            for(int i = 1; i < n ; i++){
                for(int j = 1; j < m ; j++){
                        if(text1[i] == text2[j]){
                            dp[i][j] = 1 + dp[i-1][j-1];
                        }
                        else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }

        return dp[n-1][m-1];
    }
};
