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

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

                unordered_map<string , vector<string>> x;

                vector<string> check;

                check.push_back(strs[0]);
                x[strs[0]] = check; 

                int n = strs.size();

                for(int i = 1 ; i< n ; i++) {
                    string s = strs[i];
                    bool isAna = true;
                    for(auto p : x) {
                        if(p.first.size() == s.size()  && isAnagram(p.first , s) ) {
                            x[p.first].push_back(s);
                           isAna = false; 
                           break;
                        }
                   
                    }
                    if(isAna) {
                        vector<string> temp;
                        temp.push_back(strs[i]);
                        x[strs[i]] = temp; 
                    }
                }
                vector<vector<string>> ans;
                for(auto p : x)
                {
                    ans.push_back(p.second);
                }
                return ans;

    }
};
