class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> s;

        for(int i = 0 ; i < nums.size() ; i++){
            s[nums[i]] = i;
        }
        for(int i = 0 ; i < nums.size();i++){
            if(s.find(target - nums[i]) !=s.end() && i != s[target - nums[i]]){
                    return {i , s[target - nums[i]]};
            }
        }
        return {0,0};
    }
};
