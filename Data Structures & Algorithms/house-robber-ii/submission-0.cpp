class Solution {
public:

    int robLinear(vector<int>& nums, int n , int x , int y) {
        vector<int> dp(n,0);

        dp[x] = nums[x];
        dp[x+1] = max(nums[x] , nums[x+1]);

        for(int i = x+2 ; i <=y ; i++){
            dp[i] = max(dp[i-1] ,(dp[i-2] + nums[i]));
        }
        return dp[y];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(robLinear(nums , n ,  0 , n-2),robLinear(nums, n , 1, n-1));
    }
};
