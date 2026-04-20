class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();   
        string ans = "";
        int p = 0;
        for(int i = 0 ; i < n; i++){
            int left = i , right = i;
            while(left>=0 && right < n && s[left] == s[right]){
                        left--;
                        right++;
            }
            left++; right--;
            if((right - left + 1) > p) {
                ans = s.substr(left , right - left + 1);
                 p =  right - left + 1;
            }
        }

        for(int i = 0 ; i < n-1; i++){
            int left = i , right = i+1;
            while(left>=0 && right < n && s[left] == s[right]){
                        left--;
                        right++;
            }
            
            left++; right--;
             if((right - left + 1) > p) {
                ans = s.substr(left , right - left + 1);
                 p =  right - left + 1;
            }
        }

        return ans;        
    }
};
