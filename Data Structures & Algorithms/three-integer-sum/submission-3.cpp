
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0 ; i < n - 2 ; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1]) // duplicate condition
                continue;

            int target = -nums[i];
            int j = i + 1 , k = n - 1;

            while(j < k){ 
                int sum = nums[j] + nums[k];

                if(sum == target){ 
                    ans.push_back({nums[i], nums[j], nums[k]});

                    while(j < k && nums[j] == nums[j + 1]) j++; // duplicate condition
                    while(j < k && nums[k] == nums[k - 1]) k--; // duplicate condition

                    j++;
                    k--;
                }
                else if(sum < target)  
                    j++;
                else 
                    k--;
            }
        }
        return ans;
    }
};


