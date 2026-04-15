class Solution {
public:
    int jump(vector<int>& nums) {
    int n = nums.size() , jump = 0 , farthest = 0 , curr = 0;
       for(int i = 0 ; i < n-1 ; i++){
        farthest = max(nums[i]+i , farthest);
        if(i==curr){
            curr = farthest;
            jump++;
        } 
       }
       return jump;
    }
};
