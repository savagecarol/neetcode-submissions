class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int n = s.size();
    unordered_map<char,int> x;

    int ans = 0;
    int i = 0;   

    for(int j = 0; j < n; j++) {
        if(x.find(s[j]) != x.end() && x[s[j]] >= i) {
            i = x[s[j]] + 1; 
        }
        
        x[s[j]] = j;      
        ans = max(ans, j - i + 1);
    }

    return ans;
    }
};
