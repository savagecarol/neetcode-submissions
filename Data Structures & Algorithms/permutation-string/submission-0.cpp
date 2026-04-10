class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        unordered_map<char , int> a;
        unordered_map<char , int> b;

        for(int i = 0 ; i < n ; i++){
            a[s1[i]]++;
            b[s2[i]]++;
        }

        if(a==b) return true;

        for(int i = 1 ; i <= (m-n) ; i++){

            b[s2[i+n-1]]++;
            b[s2[i-1]]--;
            if (b[s2[i - 1]] == 0) b.erase(s2[i - 1]);
            if(a==b)return true;
        }
        return false;
        
    }
};
