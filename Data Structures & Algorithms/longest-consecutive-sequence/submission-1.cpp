class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> x;   
        for(int i = 0 ; i < nums.size();i++)
        {
            x.insert(nums[i]);
        }
        int ans = 0;
        for(int i = 0 ; i < nums.size();i++)
        {
            int k = 1;
            while(x.find(nums[i]+k)!=x.end()){
                    k++;
            }
            ans = max(ans , k);
        }
        return ans;
    }
};
