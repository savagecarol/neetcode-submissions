class Solution {
public:

    bool canJump(vector<int>& nums) {
        int j = nums.size()-1;
        int i = j-1;

        while(i>=0){
            int value = nums[i] + i;
            if(value >= j) {
                j = i;
            }
            i--;
        }

        return (j==0);
    
    }
};
