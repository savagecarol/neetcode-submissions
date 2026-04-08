class Solution {
public:
    bool isAnagram(string s, string t) {

          unordered_map<char , int> x;
            int n = s.size();
            int m = t.size();
            for(int i = 0 ; i < max(n , m) ; i++)
            {
                if(i < n){
                        x[s[i]]++;
                }
                if(i<m){
                        x[t[i]]--;
                }
            }
            for(auto p : x){
                    if(p.second !=0) return false;
            }
            return true;
        
    }
};
