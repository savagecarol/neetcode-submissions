class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> x;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '[' || s[i] == '(' || s[i] == '{') x.push(s[i]);
            else{
                if(x.empty() || (s[i] == ']' && x.top()!='[') || (s[i] == '}' && x.top()!='{')  ||(s[i] == ')' && x.top()!='('))
                return false;
                x.pop(); 
            }    
        }
        return x.empty();
    }
};
