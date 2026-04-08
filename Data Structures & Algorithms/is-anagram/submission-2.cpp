class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> x;
        for(auto i:  s) x[i]++;
        for(auto i:  t) x[i]--;
        for(auto i:  x) if(i.second!=0)return false;
        return true;
    }
};
