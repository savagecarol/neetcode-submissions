class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> m;
        int i = 0 , j = 0 , n = s.size(), ans =0 ,count = 0,calc = k;  

        for(int i = 0 ; i < n ; i++) {
            m[s[i]]++;
            count = max(count , m[s[i]]);
            int window = i - j + 1;
            
            if(window - count > k){
                m[s[j]]--;  
                j++;
            }
            ans = max(ans , i-j+1);
        }


        return ans;
    }
};
