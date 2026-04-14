class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> m;
        unordered_map<char,int> check;
        vector<pair<int , int>> help; 
        int lent = t.size() , lens = s.size() , i = 0 , j = 0 , count = 0;

        int ansInd = -1;
        int ansLen = INT_MAX;

        for(int i = 0 ; i < lent ; i++) {
            m[t[i]]++; 
            check[t[i]]++; 
        }


        while(j < lens){

            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]]>=0)count++;

                if(count == lent){
                    while(i < j){
                            if(m.find(s[i])!=m.end()){
                                    if(m[s[i]] < 0) m[s[i]]++;
                                    else break;
                                } 
                                i++;
                    }
                    if( j-i+1 < ansLen){
                        ansLen = j-i+1;
                         ansInd = i ;
                    }
                    count--;
                    m[s[i]]++;
                    i++;
                }
            }
            j++;
        }

        return (ansInd == -1 || ansLen == INT_MAX) ? "" : s.substr(ansInd , ansLen);
    }
};
