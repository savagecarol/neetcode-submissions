class Solution {
public:
    int maxArea(vector<int>& heights) {
        
            int n = heights.size();

            int i = 0 , j = n-1 , ans = 0 , curr = 0;
            while(i < j)
            {   
                    curr = min(heights[i] , heights[j]) * (j-i);
                    ans = max(ans , curr);
                    if(heights[j] > heights[i]) i++;
                    else j--;
            }

            return ans;
    }
};
